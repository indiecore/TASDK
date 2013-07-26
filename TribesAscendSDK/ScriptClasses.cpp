#include "TASDK.h"
#include "IndentedStreamWriter.h"
#include <deque>
#include <unordered_map>
#include <vector>

// Altimor
//#define REPO_ROOT "..\\..\\..\\src\\"

// Orvid
#define REPO_ROOT "..\\..\\..\\AltimorTASDK\\"

void ScriptObject::LogAll()
{
	OutputLog( "ScriptObject.LogAll output: \n" );
	for( int i = 0; i < object_array()->count(); i++ )
	{
		ScriptObject *object = ( *object_array() )( i );
		if( object )
		{
			OutputLog( "%s\n", object->GetFullName() );
		}
	}
}

bool ScriptObject::IsA( ScriptClass *script_class )
{
	for( ScriptClass *super_class = object_class(); super_class; super_class = ( ScriptClass* )( super_class->super() ) )
	{
		if( super_class == script_class )
		{
			return true;
		}
	}

	return false;
}


std::string GetTypeNameForProperty(ScriptProperty* prop)
{
	if (!strcmp(prop->object_class()->GetName(), "ObjectProperty") || !strcmp(prop->object_class()->GetName(), "StructProperty"))
	{
		std::string tp = ((ScriptObjectProperty*)prop)->property_class->GetName();
		for (auto outer = ((ScriptObjectProperty*)prop)->property_class->outer(); outer->outer(); outer = outer->outer())
		{
			tp.insert(0, "::");
			tp.insert(0, outer->GetName());
		}
		if (!strcmp(prop->object_class()->GetName(), "ObjectProperty"))
		{
			tp.insert(0, "class ");
			tp += "*";
		}
		return tp;
	}
	else if (!strcmp(prop->object_class()->GetName(), "ByteProperty"))
		return "byte";
	else if (!strcmp(prop->object_class()->GetName(), "IntProperty"))
		return "int";
	else if (!strcmp(prop->object_class()->GetName(), "FloatProperty"))
		return "float";
	else if (!strcmp(prop->object_class()->GetName(), "BoolProperty"))
		return "bool";
	else if (!strcmp(prop->object_class()->GetName(), "StrProperty"))
		return "ScriptArray<wchar_t>";
	else if (!strcmp(prop->object_class()->GetName(), "StringRefProperty"))
		return "void*";
	else if (!strcmp(prop->object_class()->GetName(), "NameProperty"))
		return "ScriptName";
	else if (!strcmp(prop->object_class()->GetName(), "ClassProperty"))
		return "ScriptClass*";
	else
	{
			std::string tp = "\n// ERROR: Unknown object class '";
			tp += prop->object_class()->GetFullName();
			tp += "'!\nvoid*";
			return tp;
	}
}

std::string GetHeaderName(ScriptObject* obj)
{
	std::string file_name = obj->GetName();
	file_name.append( ".h" );

	for(ScriptObject* outer = obj->outer(); outer; outer = outer->outer())
	{
		file_name.insert(0, ".");
		file_name.insert(0, outer->GetName());
	}

	return file_name;
}

struct ClassDependencyManager
{
	std::unordered_map<std::string, int> requiredHeaders;
	ScriptObject* parentClass;

	~ClassDependencyManager()
	{
		for each (auto h in requiredHeaders)
			h.first.~basic_string();
	}

	void ProcessProperty(ScriptProperty* prop)
	{
		// TODO: Once child structs are dumped, add those headers as dependencies as well.
		if (!strcmp(prop->object_class()->GetName(), "ObjectProperty") || !strcmp(prop->object_class()->GetName(), "StructProperty"))
			RequireType(((ScriptObjectProperty*)prop)->property_class);
	}

	void RequireType(ScriptObject* objType)
	{
		if (objType == parentClass)
			return;
		static std::string headerName;
		headerName = GetHeaderName(objType);
		if (requiredHeaders.count(headerName) > 0)
			headerName.~basic_string();
		else
			requiredHeaders[headerName] = 1;
	}

	void WriteToStream(IndentedStreamWriter* wtr)
	{
		for each (auto h in requiredHeaders)
			wtr->WriteLine("#include \"%s\"", h.first.c_str());
	}
};

struct PropertyDescription
{
	ScriptProperty* originalProperty;

	PropertyDescription(ScriptProperty* originalProperty_)
	{
		originalProperty = originalProperty_;
	}

	// TODO: Add support for DelegateProperty, ArrayProperty, MapProperty, FixedArrayProperty, PointerProperty, InterfaceProperty, and ComponentProperty

	bool IsPrimitiveProperty()
	{
		return
			   !strcmp(originalProperty->object_class()->GetName(), "ByteProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "IntProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "FloatProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "BoolProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "StrProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "NameProperty")
		;
	}

	bool IsObjectProperty()
	{
		return
			   !strcmp(originalProperty->object_class()->GetName(), "ObjectProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "StringRefProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "ClassProperty")
		;
	}

	bool IsStructProperty()
	{
		return !strcmp(originalProperty->object_class()->GetName(), "StructProperty");
	}

	void RequireTypes(ClassDependencyManager* classDepMgr)
	{
		classDepMgr->ProcessProperty(originalProperty);
	}

	void WriteToStream(IndentedStreamWriter* writer)
	{
		if (
			   !strcmp(originalProperty->object_class()->GetName(), "ByteProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "IntProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "FloatProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "StrProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "NameProperty")
		)
		{
			writer->WriteLine("ADD_VAR(::%s, %s, 0xFFFFFFFF)", originalProperty->object_class()->GetName(), originalProperty->GetName());
		}
		else if (!strcmp(originalProperty->object_class()->GetName(), "BoolProperty"))
			writer->WriteLine("ADD_VAR(::%s, %s, 0x%X)", originalProperty->object_class()->GetName(), originalProperty->GetName(), ((ScriptBoolProperty*)originalProperty)->bit_mask);
		else if (!strcmp(originalProperty->object_class()->GetName(), "ObjectProperty"))
			writer->WriteLine("ADD_OBJECT(%s, %s)", ((ScriptObjectProperty*)originalProperty)->property_class->GetName(), originalProperty->GetName());
		else if (!strcmp(originalProperty->object_class()->GetName(), "StringRefProperty"))
			writer->WriteLine("ADD_OBJECT(void, %s)", originalProperty->GetName());
		else if (!strcmp(originalProperty->object_class()->GetName(), "ClassProperty"))
			writer->WriteLine("ADD_OBJECT(ScriptClass, %s)", originalProperty->GetName());
		else if (!strcmp(originalProperty->object_class()->GetName(), "StructProperty"))
		{
			auto objectProperty = (ScriptObjectProperty*)originalProperty;
			if (!strcmp(objectProperty->property_class->GetName(), "Vector"))
				writer->WriteLine("ADD_STRUCT(::VectorProperty, %s, 0xFFFFFFFF)", originalProperty->GetName());
			else if (!strcmp(objectProperty->property_class->GetName(), "Rotator"))
				writer->WriteLine("ADD_STRUCT(::RotatorProperty, %s, 0xFFFFFFFF)", originalProperty->GetName());
			else if (!strcmp(objectProperty->property_class->GetFullName(), "ScriptStruct Core.Object.QWord"))
				writer->WriteLine("ADD_STRUCT(::QWordProperty, %s, 0xFFFFFFFF)", originalProperty->GetName());
			else
				writer->WriteLine("ADD_STRUCT(::NonArithmeticProperty<%s>, %s, 0xFFFFFFFF)", GetTypeNameForProperty(objectProperty).c_str(), originalProperty->GetName());
		}
		else
			writer->WriteLine("// ERROR: Unknown object class '%s' for the property named '%s'!", originalProperty->object_class()->GetName(), originalProperty->GetName());
	}
};

struct FunctionArgumentDescription
{
	ScriptProperty* originalProperty;
	std::string name;
	int offset;
	bool out_param;

	FunctionArgumentDescription(ScriptProperty* originalProperty_)
	{
		originalProperty = originalProperty_;
		name = originalProperty->GetName();
		offset = originalProperty->offset;
		out_param = (originalProperty->property_flags & ScriptProperty::kPropOutParm) != 0;
	}

	void WriteDeclaration(IndentedStreamWriter* wtr)
	{
		if (out_param)
			wtr->Write("%s& %s", GetTypeNameForProperty(originalProperty).c_str(), name.c_str());
		else
			wtr->Write("%s %s", GetTypeNameForProperty(originalProperty).c_str(), name.c_str());
	}

	void WriteLoadToBuffer(IndentedStreamWriter* wtr, const char* bufName)
	{
		auto tnfp = GetTypeNameForProperty(originalProperty);
		if (offset != 0)
		{
			if (!strcmp(tnfp.c_str(), "byte"))
				wtr->WriteLine("*(%s + %i) = %s;", bufName, offset, name.c_str());
			else
				wtr->WriteLine("*(%s*)(%s + %i) = %s;", tnfp.c_str(), bufName, offset, name.c_str());
		}
		else
		{
			if (!strcmp(tnfp.c_str(), "byte"))
				wtr->WriteLine("*%s = %s;", bufName, name.c_str());
			else
				wtr->WriteLine("*(%s*)%s = %s;", tnfp.c_str(), bufName, name.c_str());
		}
	}

	void WriteLoadFromBuffer(IndentedStreamWriter* wtr, const char* bufName)
	{
		auto tnfp = GetTypeNameForProperty(originalProperty);
		if (out_param)
		{
			if (offset != 0)
			{
				if (!strcmp(tnfp.c_str(), "byte"))
					wtr->WriteLine("%s = *(%s + %i);", name.c_str(), bufName, offset);
				else
					wtr->WriteLine("%s = *(%s*)(%s + %i);", name.c_str(), tnfp.c_str(), bufName, offset);
			}
			else
			{
				if (!strcmp(tnfp.c_str(), "byte"))
					wtr->WriteLine("%s = *%s;", name.c_str(), bufName);
				else
					wtr->WriteLine("%s = *(%s*)%s;", name.c_str(), tnfp.c_str(), bufName);
			}
		}
	}
};

struct FunctionDescription
{
	ScriptFunction* originalFunction;
	std::vector<FunctionArgumentDescription> arguments;
	ScriptProperty* returnProperty;

	FunctionDescription(ScriptFunction* originalFunction_)
	{
		originalFunction = originalFunction_;
		returnProperty = NULL;

		for (ScriptProperty* functionArgument = (ScriptProperty*)originalFunction->children(); functionArgument; functionArgument = (ScriptProperty*)functionArgument->next())
		{
			if (functionArgument->property_flags & ScriptProperty::kPropReturnParm)
				returnProperty = functionArgument;
			else if (functionArgument->property_flags & ScriptProperty::kPropParm)
				arguments.push_back(FunctionArgumentDescription(functionArgument));
			else
			{
				// Well, something is odd at this point....
			}
		}
	}

	void RequireTypes(ClassDependencyManager* classDepMgr)
	{
		if (returnProperty)
			classDepMgr->ProcessProperty(returnProperty);
		for (unsigned int i = 0; i < arguments.size(); i++)
			classDepMgr->ProcessProperty(arguments[i].originalProperty);
	}

	void WriteToStream(IndentedStreamWriter* wtr)
	{
		if (returnProperty)
			wtr->Write("%s", GetTypeNameForProperty(returnProperty).c_str());
		else
			wtr->Write("void");
		wtr->Write(" %s(", originalFunction->GetName());

		int paramSize = 0;
		for (unsigned int i = 0; i < arguments.size(); i++)
		{
			arguments[i].WriteDeclaration(wtr);
			paramSize += arguments[i].originalProperty->element_size;
			if (i != arguments.size() - 1)
				wtr->Write(", ");
		}
		if (returnProperty)
			paramSize += returnProperty->element_size;

		wtr->WriteLine(")");
		wtr->WriteLine("{");
		wtr->Indent++;

		wtr->WriteLine("static ScriptFunction* function = ScriptObject::Find<ScriptFunction>(\"%s\");", originalFunction->GetFullName());
		if (paramSize > 0)
			wtr->WriteLine("byte* params = (byte*)malloc(%i);", paramSize);

		for (unsigned int i = 0; i < arguments.size(); i++)
			arguments[i].WriteLoadToBuffer(wtr, "params");

		wtr->Write("((ScriptObject*)this)->ProcessEvent(function, ");
		if (paramSize > 0)
			wtr->Write("params");
		else
			wtr->Write("NULL");
		wtr->WriteLine(", NULL);");

		for (unsigned int i = 0; i < arguments.size(); i++)
			arguments[i].WriteLoadFromBuffer(wtr, "params");

		if (returnProperty)
		{
			auto tnfp = GetTypeNameForProperty(returnProperty);
			if (originalFunction->return_val_offset() != 0)
			{
				if (!strcmp(tnfp.c_str(), "byte"))
					wtr->WriteLine("auto returnVal = *(params + %i);", originalFunction->return_val_offset());
				else
					wtr->WriteLine("auto returnVal = *(%s*)(params + %i);", tnfp.c_str(), originalFunction->return_val_offset());
			}
			else
			{
				if (!strcmp(tnfp.c_str(), "byte"))
					wtr->WriteLine("auto returnVal = *params;");
				else
					wtr->WriteLine("auto returnVal = *(%s*)params;", tnfp.c_str());
			}
		}
		
		if (paramSize > 0)
			wtr->WriteLine("free(params);");

		if (returnProperty)
			wtr->WriteLine("return returnVal;");

		wtr->Indent--;
		wtr->WriteLine("}");
	}
};

struct ClassDescription
{
	ScriptStruct* originalClass;
	std::vector<ClassDescription> nestedStructs;
	int primitivePropertyCount;
	int structPropertyCount;
	int objectPropertyCount;
	std::vector<PropertyDescription> properties;
	std::vector<FunctionDescription> functions;
	ClassDependencyManager dependencyManager;

	ClassDescription(ScriptStruct* originalClass_)
	{
		originalClass = originalClass_; 
		primitivePropertyCount = 0;
		structPropertyCount = 0;
		objectPropertyCount = 0;
		dependencyManager.parentClass = originalClass;

		for (int i = 0; i < originalClass->object_array()->count(); i++)
		{
			ScriptObject* object = (*originalClass->object_array())(i);
		
			if(object && object->outer() == originalClass)
			{
				if (!strcmp(object->object_class()->GetName(), "Function"))
					functions.push_back(FunctionDescription((ScriptFunction*)object));
				else if (!strcmp(object->object_class()->GetName(), "ScriptStruct"))
					nestedStructs.push_back((ScriptClass*)object);
				else
				{
					auto prop = PropertyDescription((ScriptProperty*)object);
					bool unknownProperty = false;
					if (prop.IsPrimitiveProperty())
						primitivePropertyCount++;
					else if (prop.IsStructProperty())
						structPropertyCount++;
					else if (prop.IsObjectProperty())
						objectPropertyCount++;
					else
					{
						// This isn't good, but we'll figure it out eventually.
						printf("Unknown property!");
						unknownProperty = true;
					}
					if (!unknownProperty)
						properties.push_back(prop);
				}
			}
		}
		
		if (!strcmp(originalClass->object_class()->GetName(), "Class"))
			this->RequireTypes(&dependencyManager);
	}

	void RequireTypes(ClassDependencyManager* classDepMgr)
	{
		if (originalClass->super())
			classDepMgr->RequireType(originalClass->super());

		for (unsigned int i = 0; i < properties.size(); i++)
			properties[i].RequireTypes(classDepMgr);
		for (unsigned int i = 0; i < functions.size(); i++)
			functions[i].RequireTypes(classDepMgr);
	}

	void Write(IndentedStreamWriter* wtr)
	{
		if (!strcmp(originalClass->object_class()->GetName(), "Class"))
		{
			wtr->WriteLine("#pragma once");
		
			dependencyManager.WriteToStream(wtr);

			wtr->WriteLine("namespace UnrealScript");
			wtr->WriteLine("{");
			wtr->Indent++;
		}

		if (originalClass->super())
			wtr->WriteLine("class %s : public %s", originalClass->GetName(), originalClass->super()->GetName());
		else
			wtr->WriteLine("class %s", originalClass->GetName());
		wtr->WriteLine("{");
		if (properties.size() > 0 || functions.size() > 0 || nestedStructs.size() > 0)
			wtr->WriteLine("public:");
		wtr->Indent++;

		
		for (unsigned int i = 0; i < nestedStructs.size(); i++)
			nestedStructs[i].Write(wtr);
		//wtr->WriteLine("// Here would be the struct '%s'", nestedStructs[i].originalClass->GetName());

		std::string propertyPrefix = originalClass->GetName();
		for (auto outer = originalClass->outer(); outer; outer = outer->outer())
		{
			propertyPrefix.insert(0, ".");
			propertyPrefix.insert(0, outer->GetName());
		}
		if (primitivePropertyCount > 0)
		{
			wtr->WriteLine("#define ADD_VAR(x, y, z) (x) get_##y() \\");
			wtr->WriteLine("{ \\");
			wtr->Indent++;
			wtr->WriteLine("static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x \" %s.\" #y); \\", propertyPrefix.c_str());
			wtr->WriteLine("return (##x(this, script_property->offset, z)); \\");
			wtr->Indent--;
			wtr->WriteLine("} \\");
			wtr->WriteLine("__declspec(property(get=get_##y)) x y;");
		}

		if (structPropertyCount > 0)
		{
			wtr->WriteLine("#define ADD_STRUCT(x, y, z) (x) get_##y() \\");
			wtr->WriteLine("{ \\");
			wtr->Indent++;
			wtr->WriteLine("static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(\"StructProperty %s.\" #y); \\", propertyPrefix.c_str());
			wtr->WriteLine("return (##x(this, script_property->offset, z)); \\");
			wtr->Indent--;
			wtr->WriteLine("} \\");
			wtr->WriteLine("__declspec(property(get=get_##y)) x y;");
		}

		if (objectPropertyCount > 0)
		{
			wtr->WriteLine("#define ADD_OBJECT(x, y) (class x*) get_##y() \\");
			wtr->WriteLine("{ \\");
			wtr->Indent++;
			wtr->WriteLine("static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(\"ObjectProperty %s.\" #y); \\", propertyPrefix.c_str());
			wtr->WriteLine("return *(x**)(this + script_property->offset); \\");
			wtr->Indent--;
			wtr->WriteLine("} \\");
			wtr->WriteLine("__declspec(property(get=get_##y)) class x* y;");
		}

		for (unsigned int i = 0; i < properties.size(); i++)
			properties[i].WriteToStream(wtr);
		for (unsigned int i = 0; i < functions.size(); i++)
			functions[i].WriteToStream(wtr);

		if (primitivePropertyCount > 0)
			wtr->WriteLine("#undef ADD_VAR");
		if (structPropertyCount > 0)
			wtr->WriteLine("#undef ADD_STRUCT");
		if (objectPropertyCount > 0)
			wtr->WriteLine("#undef ADD_OBJECT");

		wtr->Indent--;
		wtr->WriteLine("};");
		
		if (!strcmp(originalClass->object_class()->GetName(), "Class"))
		{
			wtr->Indent--;
			wtr->WriteLine("}");
		}
	}
};

void ScriptObject::GenerateHeader()
{
	auto cd = new ClassDescription((ScriptClass*)this);
	auto headerName = GetHeaderName(cd->originalClass);
	headerName.insert(0, REPO_ROOT "TribesAscendSDK\\HeaderDump\\");
	auto wtr = new IndentedStreamWriter(headerName.c_str());
	cd->Write(wtr);
	delete wtr;
	delete cd;
}

void ScriptObject::GenerateHeaders()
{
	static ScriptClass* core_class = ScriptObject::Find<ScriptClass>("Class Core.Class");
	for (int i = 0; i < object_array()->count(); i++)
	{
		ScriptObject* class_object = (*object_array())(i);
		if(class_object && class_object->object_class() == core_class)
			class_object->GenerateHeader();
	}

	OutputLog("Finished.\n");
}

char *ScriptObject::GetName()
{
	return name().GetName();
}

const char *ScriptObject::GetFullName()
{
	if( object_class() && outer() )
	{
		static std::string full_name;
		full_name = GetName();

		for( ScriptObject *object_outer = outer(); object_outer != NULL; object_outer = object_outer->outer() )
		{
			full_name.insert( 0, "." );
			full_name.insert( 0, object_outer->GetName() );
		}

		full_name.insert( 0, " " );
		full_name.insert( 0, object_class()->GetName() );

		return full_name.c_str();
	}

	return "Failed to get name";
}



ScriptArray< ScriptObject* > *ScriptObject::object_array_ = NULL;
ScriptArray< ScriptNameEntry* > *ScriptName::name_array_ = NULL;