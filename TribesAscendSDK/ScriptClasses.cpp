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


std::string GetTypeNameForProperty(ScriptObject* prop)
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
	else if (
		   !strcmp(prop->object_class()->GetName(), "Const")
		|| !strcmp(prop->object_class()->GetName(), "Class")
		|| !strcmp(prop->object_class()->GetName(), "Enum")
		|| !strcmp(prop->object_class()->GetName(), "ScriptStruct")
	)
	{
		std::string tp = prop->GetName();
		for (auto outer = prop->outer(); outer->outer(); outer = outer->outer())
		{
			tp.insert(0, "::");
			tp.insert(0, outer->GetName());
		}
		return tp;
	}
	else if (!strcmp(prop->object_class()->GetName(), "ArrayProperty"))
	{
		auto aProp = (ScriptArrayProperty*)prop;
		std::string tp = "ScriptArray<";
		tp += GetTypeNameForProperty(aProp->inner_property);
		tp += ">";
		return tp;
	}
	else if (!strcmp(prop->object_class()->GetName(), "ByteProperty"))
	{
		auto bProp = (ScriptByteProperty*)prop;
		if (bProp->enum_type)
			return GetTypeNameForProperty(bProp->enum_type);
		else
			return "byte";
	}
	else if (!strcmp(prop->object_class()->GetName(), "IntProperty"))
		return "int";
	else if (!strcmp(prop->object_class()->GetName(), "FloatProperty"))
		return "float";
	else if (!strcmp(prop->object_class()->GetName(), "BoolProperty"))
		return "bool";
	else if (!strcmp(prop->object_class()->GetName(), "StrProperty"))
		return "ScriptString*";
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
	std::vector<ScriptObject*> requiredChildren;
	std::unordered_map<std::string, int> requiredHeaders;
	ScriptObject* parentClass;

	~ClassDependencyManager()
	{
		for each (auto h in requiredHeaders)
			h.first.~basic_string();
	}

	void ProcessProperty(ScriptProperty* prop)
	{
		if (
			   !strcmp(prop->object_class()->GetName(), "ObjectProperty")
			|| !strcmp(prop->object_class()->GetName(), "StructProperty")
		)
		{
			RequireType(((ScriptObjectProperty*)prop)->property_class);
		}
		else if (!strcmp(prop->object_class()->GetName(), "ByteProperty") && ((ScriptByteProperty*)prop)->enum_type)
			RequireType(((ScriptByteProperty*)prop)->enum_type);
		else if (!strcmp(prop->object_class()->GetName(), "ArrayProperty"))
			ProcessProperty(((ScriptArrayProperty*)prop)->inner_property);
	}

	void RequireType(ScriptObject* objType)
	{
		if (objType == parentClass)
			return;
		if (objType->outer()->outer())
		{
			// Ensure that we only require the class-level
			// include.
			requiredChildren.push_back(objType);
			RequireType(objType->outer());
			return;
		}
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

	// TODO: Add support for DelegateProperty, MapProperty, FixedArrayProperty, PointerProperty, InterfaceProperty, and ComponentProperty

	bool IsBoolProperty()
	{
		return !strcmp(originalProperty->object_class()->GetName(), "BoolProperty");
	}

	bool IsPrimitiveProperty()
	{
		return
			   !strcmp(originalProperty->object_class()->GetName(), "ByteProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "IntProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "FloatProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "StrProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "NameProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "ArrayProperty")
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
		if (!strcmp(originalProperty->object_class()->GetName(), "BoolProperty"))
			writer->WriteLine("ADD_BOOL(%s, %i, 0x%X)", originalProperty->GetName(), originalProperty->offset, ((ScriptBoolProperty*)originalProperty)->bit_mask);
		else if (!strcmp(originalProperty->object_class()->GetName(), "ObjectProperty"))
			writer->WriteLine("ADD_OBJECT(%s, %s, %i)", ((ScriptObjectProperty*)originalProperty)->property_class->GetName(), originalProperty->GetName(), originalProperty->offset);
		else if (!strcmp(originalProperty->object_class()->GetName(), "StringRefProperty"))
			writer->WriteLine("ADD_OBJECT(void, %s, %i)", originalProperty->GetName(), originalProperty->offset);
		else if (!strcmp(originalProperty->object_class()->GetName(), "ClassProperty"))
			writer->WriteLine("ADD_OBJECT(ScriptClass, %s, %i)", originalProperty->GetName(), originalProperty->offset);
		else if (
			   !strcmp(originalProperty->object_class()->GetName(), "StructProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "ByteProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "IntProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "FloatProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "StrProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "NameProperty")
			|| !strcmp(originalProperty->object_class()->GetName(), "ArrayProperty")
		)
		{
			writer->WriteLine("ADD_STRUCT(%s, %s, %i)", GetTypeNameForProperty(originalProperty).c_str(), originalProperty->GetName(), originalProperty->offset);
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
				wtr->WriteLine("%s[%i] = %s;", bufName, offset, name.c_str());
			else
				wtr->WriteLine("*(%s*)&%s[%i] = %s;", tnfp.c_str(), bufName, offset, name.c_str());
		}
		else
		{
			if (!strcmp(tnfp.c_str(), "byte"))
				wtr->WriteLine("%s[0] = %s;", bufName, name.c_str());
			else
				wtr->WriteLine("*(%s*)&%s[0] = %s;", tnfp.c_str(), bufName, name.c_str());
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
					wtr->WriteLine("%s = %s[%i];", name.c_str(), bufName, offset);
				else
					wtr->WriteLine("%s = *(%s*)&%s[%i];", name.c_str(), tnfp.c_str(), bufName, offset);
			}
			else
			{
				if (!strcmp(tnfp.c_str(), "byte"))
					wtr->WriteLine("%s = %s[0];", name.c_str(), bufName);
				else
					wtr->WriteLine("%s = *(%s*)&%s[0];", name.c_str(), tnfp.c_str(), bufName);
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
			wtr->WriteLine("byte params[%i] = { NULL };", paramSize);

		for (unsigned int i = 0; i < arguments.size(); i++)
			arguments[i].WriteLoadToBuffer(wtr, "params");

		wtr->Write("((ScriptObject*)this)->ProcessEvent(function, ");
		if (paramSize > 0)
			wtr->Write("&params");
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
					wtr->WriteLine("return params[%i];", originalFunction->return_val_offset());
				else
					wtr->WriteLine("return *(%s*)&params[%i];", tnfp.c_str(), originalFunction->return_val_offset());
			}
			else
			{
				if (!strcmp(tnfp.c_str(), "byte"))
					wtr->WriteLine("return params[0];");
				else
					wtr->WriteLine("return *(%s*)&params[0];", tnfp.c_str());
			}
		}

		wtr->Indent--;
		wtr->WriteLine("}");
	}
};

struct ConstDescription
{
	ScriptConst* originalConst;
	std::string valueString;
	const char* typeString;
	bool nonIntegral;
	bool alreadyHasFloatSpec;

	ConstDescription(ScriptConst* originalConst_)
	{
		originalConst = originalConst_;
		valueString = std::string(originalConst->value().c_str());
		nonIntegral = true;
		if (valueString.find('.') != std::string::npos)
		{
			typeString = "float";
			alreadyHasFloatSpec = valueString.find('f') != std::string::npos;
		}
		else if (valueString.find('"') != std::string::npos)
			typeString = "const char*";
		else if (valueString.find('t') != std::string::npos || valueString.find('s') != std::string::npos) // [t]rue/fal[s]e
			typeString = "bool";
		else
		{
			typeString = "auto";
			nonIntegral = false;
		}
	}

	void WriteDeclaration(IndentedStreamWriter* wtr)
	{
		if (nonIntegral)
			wtr->WriteLine("static const %s %s;", typeString, originalConst->GetName());
		else
			wtr->WriteLine("static const %s %s = %s;", typeString, originalConst->GetName(), valueString.c_str());
	}

	void WriteImplementation(IndentedStreamWriter* wtr)
	{
		if (nonIntegral)
		{
			if (!strcmp(typeString, "float") && !alreadyHasFloatSpec)
				wtr->WriteLine("const %s %s::%s = %sf;", typeString, GetTypeNameForProperty(originalConst->outer()).c_str(), originalConst->GetName(), valueString.c_str());
			else
				wtr->WriteLine("const %s %s::%s = %s;", typeString, GetTypeNameForProperty(originalConst->outer()).c_str(), originalConst->GetName(), valueString.c_str());
		}
	}
};

struct EnumDescription
{
	ScriptEnum* originalEnum;

	EnumDescription(ScriptEnum* originalEnum_)
	{
		originalEnum = originalEnum_;
	}

	void WriteToStream(IndentedStreamWriter* wtr)
	{
		wtr->WriteLine("enum %s : byte", originalEnum->GetName());
		wtr->WriteLine("{");
		wtr->Indent++;

		for (int i = 0; i < originalEnum->value_names().count(); i++)
			wtr->WriteLine("%s = %i,", originalEnum->value_names().data()[i].GetName(), i);
		
		wtr->Indent--;
		wtr->WriteLine("};");
	}
};

struct ClassDescription
{
	ScriptStruct* originalClass;
	std::vector<ConstDescription> nestedConstants;
	std::vector<EnumDescription> nestedEnums;
	std::vector<ClassDescription> nestedStructs;
	int boolPropertyCount;
	int primitivePropertyCount;
	int structPropertyCount;
	int objectPropertyCount;
	std::vector<PropertyDescription> properties;
	std::vector<FunctionDescription> functions;
	ClassDependencyManager dependencyManager;

	ClassDescription(ScriptStruct* originalClass_)
	{
		originalClass = originalClass_; 
		boolPropertyCount = 0;
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
					nestedStructs.push_back(ClassDescription((ScriptStruct*)object));
				else if (!strcmp(object->object_class()->GetName(), "Enum"))
					nestedEnums.push_back(EnumDescription((ScriptEnum*)object));
				else if (!strcmp(object->object_class()->GetName(), "Const"))
					nestedConstants.push_back(ConstDescription((ScriptConst*)object));
				else
				{
					auto prop = PropertyDescription((ScriptProperty*)object);
					bool unknownProperty = false;
					if (prop.IsBoolProperty())
						boolPropertyCount++;
					else if (prop.IsPrimitiveProperty())
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

		for (unsigned int i = 0; i < nestedStructs.size(); i++)
		{
			boolPropertyCount += nestedStructs[i].boolPropertyCount;
			primitivePropertyCount += nestedStructs[i].primitivePropertyCount;
			structPropertyCount += nestedStructs[i].structPropertyCount;
			objectPropertyCount += nestedStructs[i].objectPropertyCount;
		}
		
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

			if (boolPropertyCount > 0)
			{
				wtr->WriteLine("#define ADD_BOOL(name, offset, mask) \\");
				wtr->WriteLine("bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \\");
				wtr->WriteLine("void set_##name(bool val) \\");
				wtr->WriteLine("{ \\");
				wtr->Indent++;
				wtr->WriteLine("if (val) \\");
				wtr->Indent++;
				wtr->WriteLine("*(DWORD*)(this + offset) |= mask; \\");
				wtr->Indent--;
				wtr->WriteLine("else \\");
				wtr->Indent++;
				wtr->WriteLine("*(DWORD*)(this + offset) &= ~mask; \\");
				wtr->Indent--;
				wtr->Indent--;
				wtr->WriteLine("} \\");
				wtr->WriteLine("__declspec(property(get=get_##name, put=set_##name)) bool name;");
			}

			if (structPropertyCount > 0 || primitivePropertyCount > 0)
			{
				wtr->WriteLine("#define ADD_STRUCT(x, y, offset) \\");
				wtr->WriteLine("x get_##y() { return *(x*)(this + offset); } \\");
				wtr->WriteLine("void set_##y(x val) { *(x*)(this + offset) = val; } \\");
				wtr->WriteLine("__declspec(property(get=get_##y, put=set_##y)) x y;");
			}

			if (objectPropertyCount > 0)
			{
				wtr->WriteLine("#define ADD_OBJECT(x, y, offset) \\");
				wtr->WriteLine("class x* get_##y() { return *(class x**)(this + offset); } \\");
				wtr->WriteLine("void set_##y(x* val) { *(class x**)(this + offset) = val; } \\");
				wtr->WriteLine("__declspec(property(get=get_##y, put=set_##y)) class x* y;");
			}

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


		for (unsigned int i = 0; i < nestedConstants.size(); i++)
			nestedConstants[i].WriteDeclaration(wtr);
		for (unsigned int i = 0; i < nestedEnums.size(); i++)
			nestedEnums[i].WriteToStream(wtr);

		// BEWARE: This code will run in an infinite loop if
		// there is a circular reference.
		if (nestedStructs.size() > 0)
		{
			std::unordered_map<const char*, int> definedStructsTable;
			std::vector<ClassDescription*> definedStructs;
			std::deque<ClassDescription*> delayedStructs;

			for (unsigned int i = 0; i < nestedStructs.size(); i++)
			{
				auto ns = &nestedStructs[i];
				bool add = true;
				for each (auto rc in ns->dependencyManager.requiredChildren)
				{
					if (!strcmp(rc->outer()->GetName(), originalClass->GetName()))
					{
						if (definedStructsTable.count(rc->GetName()) == 0)
						{
							add = false;
							delayedStructs.push_back(ns);
							break;
						}
					}
				}
				
				if (add)
				{
					definedStructs.push_back(ns);
					definedStructsTable[ns->originalClass->GetName()] = 1;
				}
			}

			while (delayedStructs.size() > 0)
			{
				auto ns = delayedStructs.front();
				delayedStructs.pop_front();
				bool add = true;
				for each (auto rc in ns->dependencyManager.requiredChildren)
				{
					if (strcmp(rc->object_class()->GetName(), "Enum") && !strcmp(rc->outer()->GetName(), originalClass->GetName()))
					{
						if (definedStructsTable.count(rc->GetName()) == 0)
						{
							add = false;
							delayedStructs.push_back(ns);
							break;
						}
					}
				}
				
				if (add)
				{
					definedStructs.push_back(ns);
					definedStructsTable[ns->originalClass->GetName()] = 1;
				}
			}

			for (unsigned int i = 0; i < definedStructs.size(); i++)
				definedStructs[i]->Write(wtr);
		}

		for (unsigned int i = 0; i < properties.size(); i++)
			properties[i].WriteToStream(wtr);
		for (unsigned int i = 0; i < functions.size(); i++)
			functions[i].WriteToStream(wtr);

		wtr->Indent--;
		wtr->WriteLine("};");

		for (unsigned int i = 0; i < nestedConstants.size(); i++)
			nestedConstants[i].WriteImplementation(wtr);
		
		if (!strcmp(originalClass->object_class()->GetName(), "Class"))
		{
			wtr->Indent--;
			wtr->WriteLine("}");
			
			if (boolPropertyCount > 0)
				wtr->WriteLine("#undef ADD_BOOL");
			if (structPropertyCount > 0 || primitivePropertyCount > 0)
				wtr->WriteLine("#undef ADD_STRUCT");
			if (objectPropertyCount > 0)
				wtr->WriteLine("#undef ADD_OBJECT");
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

char* ScriptName::GetName()
{
	if(index_ >= name_array()->count())
	{
		return "Failed to get name";
	}

	if (instance_number_ <= 0)
		return (*name_array())(index_)->name();
	else
	{
		static std::string nm;
		nm = (*name_array())(index_)->name();
		nm += "_";
		char buf[16] = { NULL };
		sprintf_s(buf, "%i", instance_number_ - 1); // Because UE is just weird like that.
		nm += buf;
		return (char*)nm.c_str();
	}
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