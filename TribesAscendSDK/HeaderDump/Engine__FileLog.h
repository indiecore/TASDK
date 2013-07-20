#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FileLog." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FileLog." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FileLog." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FileLog : public FileWriter
	{
	public:
			void OpenLog( ScriptArray< wchar_t > LogFilename, ScriptArray< wchar_t > extension, bool bUnique )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FileLog.OpenLog" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = LogFilename;
				*( ScriptArray< wchar_t >* )( params + 12 ) = extension;
				*( bool* )( params + 24 ) = bUnique;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CloseLog(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FileLog.CloseLog" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
