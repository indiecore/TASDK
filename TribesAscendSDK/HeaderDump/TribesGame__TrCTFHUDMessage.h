#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrCTFHUDMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrCTFHUDMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrCTFHUDMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCTFHUDMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, YouHaveFlagReminderString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BothFlagsString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyHasFlagString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouHaveFlagString, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
