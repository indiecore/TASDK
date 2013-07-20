#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GenericParamListStatEntry." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GenericParamListStatEntry." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GenericParamListStatEntry." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GenericParamListStatEntry : public Object
	{
	public:
			ADD_OBJECT( GameplayEventsWriter, Writer )
			void AddFloat( ScriptName ParamName, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.AddFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParamName;
				*( float* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddInt( ScriptName ParamName, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.AddInt" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParamName;
				*( int* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddVector( ScriptName ParamName, Vector Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.AddVector" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ParamName;
				*( Vector* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddString( ScriptName ParamName, ScriptArray< wchar_t > Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.AddString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ParamName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetFloat( ScriptName ParamName, float &out_Float )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.GetFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParamName;
				*( float* )( params + 8 ) = out_Float;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Float = *( float* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetInt( ScriptName ParamName, int &out_int )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.GetInt" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ParamName;
				*( int* )( params + 8 ) = out_int;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_int = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetVector( ScriptName ParamName, Vector &out_vector )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.GetVector" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ParamName;
				*( Vector* )( params + 8 ) = out_vector;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_vector = *( Vector* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetString( ScriptName ParamName, ScriptArray< wchar_t > &out_string )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.GetString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ParamName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = out_string;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_string = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CommitToDisk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GenericParamListStatEntry.CommitToDisk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
