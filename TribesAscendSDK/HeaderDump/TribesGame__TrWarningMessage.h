#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrWarningMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrWarningMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrWarningMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrWarningMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, RequiresPowerToFire, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RequiresCreditsToFire, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SuicidePenalty, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MissileIntercepted, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MissileTargetingYou, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MissileLockedOnToYou, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SaberLauncherNeedsTargetToFire, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FumbledFlag, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
