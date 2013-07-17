#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Core.Commandlet." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Core.Commandlet." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Core.Commandlet." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Commandlet : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, ShowErrorCount, 0x10 )
			ADD_VAR( ::BoolProperty, LogToConsole, 0x8 )
			ADD_VAR( ::BoolProperty, IsEditor, 0x4 )
			ADD_VAR( ::BoolProperty, IsClient, 0x2 )
			ADD_VAR( ::BoolProperty, IsServer, 0x1 )
			ADD_VAR( ::StrProperty, HelpWebLink, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpUsage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpDescription, 0xFFFFFFFF )
			int Main( ScriptArray< wchar_t > Params )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.Commandlet.Main" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Params;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
