#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrPromptMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrPromptMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrPromptMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPromptMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, YourJackalGrenadesHaveBeenDestroyed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnterVehicle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ObjectiveUpgradeDeniedMaxLevel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ObjectiveUpgradeDeniedNoCredits, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KickWarning, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, UpgradeObjective, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EquipRepairGun, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, UpgradeDeniedSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
