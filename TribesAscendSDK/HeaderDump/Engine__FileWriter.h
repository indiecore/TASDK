#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FileWriter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FileWriter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FileWriter." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FileWriter : public Info
	{
	public:
			bool OpenFile( ScriptArray< wchar_t > InFilename, byte InFileType, ScriptArray< wchar_t > InExtension, bool bUnique, bool bIncludeTimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FileWriter.OpenFile" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = InFilename;
				*( byte* )( params + 12 ) = InFileType;
				*( ScriptArray< wchar_t >* )( params + 16 ) = InExtension;
				*( bool* )( params + 28 ) = bUnique;
				*( bool* )( params + 32 ) = bIncludeTimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CloseFile(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FileWriter.CloseFile" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Logf( ScriptArray< wchar_t > logString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FileWriter.Logf" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = logString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FileWriter.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::StrProperty, Filename, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FileType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bFlushEachWrite, 0x1 )
			ADD_VAR( ::BoolProperty, bWantsAsyncWrites, 0x2 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
