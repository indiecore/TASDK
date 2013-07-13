#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployableMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployableMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployableMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployableMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, DeployableAmmoDepleted, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DeployableAmmoRemaining, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DeployableHologramInvalidDeploySpot, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DeployableHologramOnlyOutside, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DeployableHologramTooCloseToAnotherDeployable, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DeployableHologramTooCloseToEnemyBase, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
