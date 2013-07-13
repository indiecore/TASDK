#include <Windows.h>
#include "TASDK.h"

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

void ScriptObject::GenerateHeader()
{
	ScriptClass *class_scriptclass = ( ScriptClass* )( this );

	std::string file_name = this->GetName();
	file_name.append( ".h" );

	for( ScriptObject *outer = this->outer(); outer; outer = outer->outer() )
	{
		file_name.insert( 0, "__" );
		file_name.insert( 0, outer->GetName() );
	}

	OutputLogTo( "..\\..\\..\\src\\TribesAscendSDK\\HeaderDump\\HeaderDump.h", "#include \"%s\"\n", file_name.c_str() );

	file_name.insert( 0, "..\\..\\..\\src\\TribesAscendSDK\\HeaderDump\\" );
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
			else if( !strcmp( object->object_class()->GetName(), "Function" ) )
			{
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
			else if( !strcmp( object->object_class()->GetName(), "StringRefProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_OBJECT( void, %s, 0xFFFFFFFF )\n", object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "NameProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "StructProperty" ) ) 
			{
				ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( object );
				if( !strcmp( object_property->property_class->GetName(), "Vector" ) )
					OutputLogTo( file_name.c_str(), "\t\t\tADD_STRUCT( ::VectorProperty, %s, 0xFFFFFFFF )\n", object->GetName() );
				else if( !strcmp( object_property->property_class->GetName(), "Rotator" ) )
					OutputLogTo( file_name.c_str(), "\t\t\tADD_STRUCT( ::RotatorProperty, %s, 0xFFFFFFFF )\n", object->GetName() );
			}
		}
	}
	OutputLogTo( file_name.c_str(), "\t};\n" );
	OutputLogTo( file_name.c_str(), "}\n\n" );

	OutputLogTo( file_name.c_str(), "#undef ADD_VAR\n" );
	OutputLogTo( file_name.c_str(), "#undef ADD_STRUCT\n" );
	OutputLogTo( file_name.c_str(), "#undef ADD_OBJECT\n" );

	ScriptClass *core_class = ScriptObject::Find< ScriptClass >( "Class Core.Class" );
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

ShortVector Vector::ToShortVector()
{
	return ShortVector( ( short )( ( x / 360.0f ) * 65535.0f ), ( short )( ( y / 360.0f ) * 65535.0f ), ( short )( ( z / 360.0f ) * 65535.0f ) );
}

Vector ShortVector::ToFloatVector()
{
	return Vector( ( 360.0f * x ) / 65535.0f, ( 360.0f * y ) / 65535.0f, ( 360.0f * z ) / 65535.0f );
}

ScriptArray< ScriptObject* > *ScriptObject::object_array_ = NULL;
ScriptArray< ScriptNameEntry* > *ScriptName::name_array_ = NULL;