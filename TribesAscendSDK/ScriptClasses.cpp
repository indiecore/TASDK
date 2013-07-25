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
	if (!strcmp(prop->object_class()->GetName(), "ObjectProperty"))
	{
		std::string tp = "class ";
		tp += ((ScriptObjectProperty*)prop)->property_class->GetName();
		tp += "*";
		return tp;
	}
	else if (!strcmp(prop->object_class()->GetName(), "StructProperty"))
	{
		auto objProp = (ScriptObjectProperty*)prop;
		if (!strcmp(objProp->property_class->GetName(), "Vector"))
			return "Vector";
		else if (!strcmp(objProp->property_class->GetName(), "Rotator"))
			return "Rotator";
		else
		{
			std::string tp = "\n// WARNING: Unknown structure type '";
			tp += objProp->property_class->GetFullName();
			tp += "'!\nvoid*";
			return tp;
		}
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
		file_name.insert(0, "__");
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
		if (!strcmp(prop->object_class()->GetName(), "ObjectProperty"))
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
				writer->WriteLine("ADD_STRUCT(::VectorProperty, %s, 0xFFFFFFFF", originalProperty->GetName());
			else if (!strcmp(objectProperty->property_class->GetName(), "Rotator"))
				writer->WriteLine("ADD_STRUCT(::RotatorProperty, %s, 0xFFFFFFFF", originalProperty->GetName());
			else
				writer->WriteLine("// WARNING: Unknown structure type '%s' for the property named '%s'!", objectProperty->property_class->GetFullName(), originalProperty->GetName());
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
		auto tnfp = GetTypeNameForProperty(originalProperty).c_str();
		if (offset != 0)
		{
			if (!strcmp(tnfp, "byte"))
				wtr->WriteLine("*(%s + %i) = %s;", bufName, offset, name.c_str());
			else
				wtr->WriteLine("*(%s*)(%s + %i) = %s;", tnfp, bufName, offset, name.c_str());
		}
		else
		{
			if (!strcmp(tnfp, "byte"))
				wtr->WriteLine("*%s = %s;", bufName, name.c_str());
			else
				wtr->WriteLine("*(%s*)%s = %s;", tnfp, bufName, name.c_str());
		}
	}

	void WriteLoadFromBuffer(IndentedStreamWriter* wtr, const char* bufName)
	{
		auto tnfp = GetTypeNameForProperty(originalProperty).c_str();
		if (out_param)
		{
			if (offset != 0)
			{
				if (!strcmp(tnfp, "byte"))
					wtr->WriteLine("%s = *(%s + %i);", name.c_str(), bufName, offset);
				else
					wtr->WriteLine("%s = *(%s*)(%s + %i);", name.c_str(), tnfp, bufName, offset);
			}
			else
			{
				if (!strcmp(tnfp, "byte"))
					wtr->WriteLine("%s = *%s;", name.c_str(), bufName);
				else
					wtr->WriteLine("%s = *(%s*)%s;", name.c_str(), tnfp, bufName);
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
			auto tnfp = GetTypeNameForProperty(returnProperty).c_str();
			if (originalFunction->return_val_offset() != 0)
			{
				if (!strcmp(tnfp, "byte"))
					wtr->WriteLine("return *(params + %i);", originalFunction->return_val_offset());
				else
					wtr->WriteLine("return *(%s*)(params + %i);", tnfp, originalFunction->return_val_offset());
			}
			else
			{
				if (!strcmp(tnfp, "byte"))
					wtr->WriteLine("return *params;");
				else
					wtr->WriteLine("return *(%s*)params;", tnfp);
			}
		}

		wtr->Indent--;
		wtr->WriteLine("}");
	}
};

struct ClassDescription
{
	ScriptClass* originalClass;
	int primitivePropertyCount;
	int structPropertyCount;
	int objectPropertyCount;
	std::vector<PropertyDescription> properties;
	std::vector<FunctionDescription> functions;
	ClassDependencyManager dependencyManager;

	ClassDescription(ScriptClass* originalClass_)
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

		if (originalClass->super())
			dependencyManager.RequireType(originalClass->super());

		for (unsigned int i = 0; i < properties.size(); i++)
			properties[i].RequireTypes(&dependencyManager);
		for (unsigned int i = 0; i < functions.size(); i++)
			functions[i].RequireTypes(&dependencyManager);
	}

	void Write()
	{
		auto headerName = GetHeaderName(originalClass);
		headerName.insert(0, REPO_ROOT "TribesAscendSDK\\HeaderDump\\");
		auto wtr = new IndentedStreamWriter(headerName.c_str());

		wtr->WriteLine("#pragma once");
		
		dependencyManager.WriteToStream(wtr);

		if (primitivePropertyCount > 0)
		{
			wtr->WriteLine("#define ADD_VAR(x, y, z) (x) get_##y() \\");
			wtr->WriteLine("{ \\");
			wtr->Indent++;
			wtr->WriteLine("static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x \" %s.%s.\" #y); \\", originalClass->outer()->GetName(), originalClass->GetName());
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
			wtr->WriteLine("static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(\"StructProperty %s.%s.\" #y); \\", originalClass->outer()->GetName(), originalClass->GetName());
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
			wtr->WriteLine("static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(\"ObjectProperty %s.%s.\" #y); \\", originalClass->outer()->GetName(), originalClass->GetName());
			wtr->WriteLine("return *(x**)(this + script_property->offset); \\");
			wtr->Indent--;
			wtr->WriteLine("} \\");
			wtr->WriteLine("__declspec(property(get=get_##y)) class x* y;");
		}

		wtr->WriteLine("namespace UnrealScript");
		wtr->WriteLine("{");
		wtr->Indent++;

		if (originalClass->super())
			wtr->WriteLine("class %s : public %s", originalClass->GetName(), originalClass->super()->GetName());
		else
			wtr->WriteLine("class %s", originalClass->GetName());
		wtr->WriteLine("{");

		if (properties.size() > 0 || functions.size() > 0)
			wtr->WriteLine("public:");

		wtr->Indent++;

		for (unsigned int i = 0; i < properties.size(); i++)
			properties[i].WriteToStream(wtr);
		for (unsigned int i = 0; i < functions.size(); i++)
			functions[i].WriteToStream(wtr);

		wtr->Indent--;
		wtr->WriteLine("};");

		wtr->Indent--;
		wtr->WriteLine("}");

		if (primitivePropertyCount > 0)
			wtr->WriteLine("#undef ADD_VAR");
		if (structPropertyCount > 0)
			wtr->WriteLine("#undef ADD_STRUCT");
		if (objectPropertyCount > 0)
			wtr->WriteLine("#undef ADD_OBJECT");

		delete wtr;
	}
};

struct FuncArg
{
	FuncArg( std::string name_, std::string type_, int offset_, bool out_param_ )
	{
		name = name_;
		type = type_;
		offset = offset_;
		out_param = out_param_;
	}

	std::string name;
	std::string type;
	int offset;
	bool out_param;
};

void ScriptObject::GenerateHeader()
{
	ScriptClass *class_scriptclass = ( ScriptClass* )( this );

	auto cd = new ClassDescription(class_scriptclass);
	cd->Write();
	delete cd;

	/*std::string file_name = this->GetName();
	file_name.append( ".h" );

	for( ScriptObject *outer = this->outer(); outer; outer = outer->outer() )
	{
		file_name.insert( 0, "__" );
		file_name.insert( 0, outer->GetName() );
	}

	OutputLogTo( REPO_ROOT "TribesAscendSDK\\HeaderDump\\HeaderDump.h", "#include \"%s\"\n", file_name.c_str() );

	file_name.insert( 0, REPO_ROOT "TribesAscendSDK\\HeaderDump\\" );
	InitLoggingTo( file_name.c_str() );

	OutputLogTo( file_name.c_str(), "#pragma once\n" );

	OutputLogTo( file_name.c_str(), "#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \\\n" );
	OutputLogTo( file_name.c_str(), "{ \\\n" );
	OutputLogTo( file_name.c_str(), "\tstatic ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x \" %s.%s.\" #y ); \\\n", this->outer()->GetName(), this->GetName() );
	OutputLogTo( file_name.c_str(), "\treturn ( ##x( this, script_property->offset, z ) ); \\\n" );
	OutputLogTo( file_name.c_str(), "}\n" );

	OutputLogTo( file_name.c_str(), "#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \\\n" );
	OutputLogTo( file_name.c_str(), "{ \\\n" );
	OutputLogTo( file_name.c_str(), "\tstatic ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( \"StructProperty %s.%s.\" #y ); \\\n", this->outer()->GetName(), this->GetName() );
	OutputLogTo( file_name.c_str(), "\treturn ( ##x( this, script_property->offset, z ) ); \\\n" );
	OutputLogTo( file_name.c_str(), "}\n" );

	OutputLogTo( file_name.c_str(), "#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \\\n" );
	OutputLogTo( file_name.c_str(), "{ \\\n" );
	OutputLogTo( file_name.c_str(), "\tstatic ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( \"ObjectProperty %s.%s.\" #y ); \\\n", this->outer()->GetName(), this->GetName() );
	OutputLogTo( file_name.c_str(), "\treturn *( x** )( this + script_property->offset ); \\\n" );
	OutputLogTo( file_name.c_str(), "}\n" );

	OutputLogTo( file_name.c_str(), "namespace UnrealScript\n" );
	OutputLogTo( file_name.c_str(), "{\n" );

	if( class_scriptclass->super() )
		OutputLogTo( file_name.c_str(), "\tclass %s : public %s\n", class_scriptclass->GetName(), class_scriptclass->super()->GetName() );
	else
		OutputLogTo( file_name.c_str(), "\tclass %s\n", class_scriptclass->GetName() );

	OutputLogTo( file_name.c_str(), "\t{\n" );
	OutputLogTo( file_name.c_str(), "\tpublic:\n" );

	for( int i = 0; i < object_array()->count(); i++ )
	{
		ScriptObject *object = ( *object_array() )( i );
		
		if( object && object->outer() == this )
		{
			if( !strcmp( object->object_class()->GetName(), "ObjectProperty" ) )
			{
				ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( object );
				OutputLogTo( file_name.c_str(), "\t\t\tADD_OBJECT( %s, %s )\n", object_property->property_class->GetName(), object->GetName() );
			}
			else if( !strcmp( object->object_class()->GetName(), "ByteProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "IntProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "FloatProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "BoolProperty" ) )
			{
				ScriptBoolProperty *bool_property = ( ScriptBoolProperty* )( object );
				OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0x%X )\n", object->object_class()->GetName(), object->GetName(), bool_property->bit_mask );
			}
			else if( !strcmp( object->object_class()->GetName(), "StrProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "StringRefProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_OBJECT( void, %s )\n", object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "ClassProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_OBJECT( ScriptClass, %s )\n", object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "NameProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "StructProperty" ) ) 
			{
				ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( object );
				if( !strcmp( object_property->property_class->GetName(), "Vector" ) )
					OutputLogTo( file_name.c_str(), "\t\t\tADD_STRUCT( ::VectorProperty, %s, 0xFFFFFFFF )\n", object->GetName() );
				else if( !strcmp( object_property->property_class->GetName(), "Rotator" ) )
					OutputLogTo( file_name.c_str(), "\t\t\tADD_STRUCT( ::RotatorProperty, %s, 0xFFFFFFFF )\n", object->GetName() );
			}
			else if( !strcmp( object->object_class()->GetName(), "Function" ) ) 
			{
				bool return_val = false;
				std::string return_type;

				ScriptFunction *script_function = ( ScriptFunction* )( object );
				for( ScriptProperty *script_property = ( ScriptProperty* )( script_function->children() ); script_property; script_property = ( ScriptProperty* )( script_property->next() ) )
				{
					if( script_property->property_flags & ScriptProperty::kPropReturnParm )
					{
						if( !strcmp( script_property->object_class()->GetName(), "ObjectProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							std::string type = "class ";
							type += object_property->property_class->GetName();
							type += "*";
							return_type = type.c_str();
						}
						else if( !strcmp( script_property->object_class()->GetName(), "ByteProperty" ) ) return_type = "byte";
						else if( !strcmp( script_property->object_class()->GetName(), "IntProperty" ) ) return_type = "int";
						else if( !strcmp( script_property->object_class()->GetName(), "FloatProperty" ) ) return_type = "float";
						else if( !strcmp( script_property->object_class()->GetName(), "BoolProperty" ) ) return_type = "bool";
						else if( !strcmp( script_property->object_class()->GetName(), "StrProperty" ) ) return_type = "ScriptArray< wchar_t >";
						else if( !strcmp( script_property->object_class()->GetName(), "StringRefProperty" ) ) return_type = "void*";
						else if( !strcmp( script_property->object_class()->GetName(), "NameProperty" ) ) return_type = "ScriptName";
						else if( !strcmp( script_property->object_class()->GetName(), "ClassProperty" ) ) return_type = "ScriptClass*";
						else if( !strcmp( script_property->object_class()->GetName(), "StructProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							if( !strcmp( object_property->property_class->GetName(), "Vector" ) )
								return_type = "Vector";
							else if( !strcmp( object_property->property_class->GetName(), "Rotator" ) )
								return_type = "Rotator";
							else
								return_type = "void*";
						}
						else
						{
							return_type = "void*";
						}

						return_val = true;

						break;
					}
				}

				int param_size = 0;

				if( !return_val )
					OutputLogTo( file_name.c_str(), "\t\t\tvoid " );
				else
					OutputLogTo( file_name.c_str(), "\t\t\t%s ", return_type.c_str() );

				OutputLogTo( file_name.c_str(), "%s( ", object->GetName() );
				
				std::deque< FuncArg > arg_list;

				for( ScriptProperty *script_property = ( ScriptProperty* )( script_function->children() ); script_property; script_property = ( ScriptProperty* )( script_property->next() ) )
				{
					if( script_property->property_flags & ScriptProperty::kPropParm && !( script_property->property_flags & ScriptProperty::kPropReturnParm ) )
					{
						bool out_param = ( script_property->property_flags & ScriptProperty::kPropOutParm ) != 0;

						std::string property_name = script_property->GetName();

						for( DWORD i = 0; i < arg_list.size(); i++ )
						{
							if( arg_list[ i ].name == property_name )
								property_name += "_";
						}

						if( !strcmp( script_property->object_class()->GetName(), "ObjectProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							std::string type = "class ";
							type += object_property->property_class->GetName();
							type += "*";
							arg_list.push_back( FuncArg( property_name, type, script_property->offset, out_param ) );
						}
						else if( !strcmp( script_property->object_class()->GetName(), "ByteProperty" ) ) arg_list.push_back( FuncArg( property_name, "byte", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "IntProperty" ) ) arg_list.push_back( FuncArg( property_name, "int", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "FloatProperty" ) ) arg_list.push_back( FuncArg( property_name, "float", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "BoolProperty" ) ) arg_list.push_back( FuncArg( property_name, "bool", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "StrProperty" ) ) arg_list.push_back( FuncArg( property_name, "ScriptArray< wchar_t >", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "StringRefProperty" ) ) arg_list.push_back( FuncArg( property_name, "void*", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "NameProperty" ) ) arg_list.push_back( FuncArg( property_name, "ScriptName", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "ClassProperty" ) ) arg_list.push_back( FuncArg( property_name, "ScriptClass*", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "StructProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							if( !strcmp( object_property->property_class->GetName(), "Vector" ) )
								arg_list.push_back( FuncArg( property_name, "Vector", script_property->offset, out_param ) );
							else if( !strcmp( object_property->property_class->GetName(), "Rotator" ) )
								arg_list.push_back( FuncArg( property_name, "Rotator", script_property->offset, out_param ) );
							else
								arg_list.push_back( FuncArg( property_name, "void*", script_property->offset, out_param ) );
						}

						param_size += script_property->element_size;
					}
				}

				for( DWORD i = 0; i < arg_list.size(); i++ )
				{
					if( arg_list[ i ].out_param )
					{
						if( i < arg_list.size() - 1 )
							OutputLogTo( file_name.c_str(), "%s &%s, ", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
						else
							OutputLogTo( file_name.c_str(), "%s &%s", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
					}
					else
					{
						if( i < arg_list.size() - 1 )
							OutputLogTo( file_name.c_str(), "%s %s, ", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
						else
							OutputLogTo( file_name.c_str(), "%s %s", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
					}
				}

				OutputLogTo( file_name.c_str(), " )\n\t\t\t{\n" );
				OutputLogTo( file_name.c_str(), "\t\t\t\tstatic ScriptFunction *function = ScriptObject::Find< ScriptFunction >( \"%s\" );\n", object->GetFullName() );
				OutputLogTo( file_name.c_str(), "\t\t\t\tbyte *params = ( byte* )( malloc( %i ) );\n", param_size );

				for( DWORD i = 0; i < arg_list.size(); i++ )
				{
					if ( arg_list[ i ].offset > 0 )
						OutputLogTo( file_name.c_str(), "\t\t\t\t*( %s* )( params + %i ) = %s;\n", arg_list[ i ].type.c_str(), arg_list[ i ].offset, arg_list[ i ].name.c_str() );
					else
						OutputLogTo( file_name.c_str(), "\t\t\t\t*( %s* )params = %s;\n", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
				}

				OutputLogTo( file_name.c_str(), "\t\t\t\tScriptObject *object = ( ScriptObject* )( this );\n" );
				OutputLogTo( file_name.c_str(), "\t\t\t\tobject->ProcessEvent( function, params, NULL );\n" );

				for( DWORD i = 0; i < arg_list.size(); i++ )
				{
					if( arg_list[ i ].out_param )
					{
						if ( arg_list[ i ].offset > 0 )
							OutputLogTo( file_name.c_str(), "\t\t\t\t%s = *( %s* )( params + %i );\n", arg_list[ i ].name.c_str(), arg_list[ i ].type.c_str(), arg_list[ i ].offset );
						else
							OutputLogTo( file_name.c_str(), "\t\t\t\t%s = *( %s* )params;\n", arg_list[ i ].name.c_str(), arg_list[ i ].type.c_str() );
					}
				}

				if( return_val )
				{
					OutputLogTo( file_name.c_str(), "\t\t\t\treturn *( %s* )( params + function->return_val_offset() );\n", return_type.c_str() );
				}

				OutputLogTo( file_name.c_str(), "\t\t\t}\n\n" );

			}
		}
	}
	OutputLogTo( file_name.c_str(), "\t};\n" );
	OutputLogTo( file_name.c_str(), "}\n\n" );

	OutputLogTo( file_name.c_str(), "#undef ADD_VAR\n" );
	OutputLogTo( file_name.c_str(), "#undef ADD_STRUCT\n" );
	OutputLogTo( file_name.c_str(), "#undef ADD_OBJECT\n" );*/

	static ScriptClass *core_class = ScriptObject::Find< ScriptClass >( "Class Core.Class" );
	for( int i = 0; i < object_array()->count(); i++ )
	{
		ScriptObject *class_object = ( *object_array() )( i );
		ScriptClass *class_scriptclass = ( ScriptClass* )( class_object );

		if( class_object && class_object->object_class() == core_class && class_scriptclass->super() == this
			&& strcmp( class_object->outer()->GetName(), "UnrealEd" )
			&& strcmp( class_object->GetName(), "GenericBrowserType_GFxMovie" )
			&& strcmp( class_object->GetName(), "TrRank" )
			)
		{
			class_object->GenerateHeader();
		}
	}
}

void ScriptObject::GenerateHeaders()
{
	InitLoggingTo( "..\\..\\..\\src\\TribesAscendSDK\\HeaderDump\\HeaderDump.h" );
	
	Find< ScriptObject >( "Class Core.Object" )->GenerateHeader();

	OutputLog( "Finished.\n" );
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