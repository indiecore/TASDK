#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrServerSettingsInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrServerSettingsInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrServerSettingsInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrServerSettingsInfo : public Info
	{
	public:
			ADD_VAR( ::BoolProperty, bObjectiveUpgrades, 0x4 )
			ADD_VAR( ::BoolProperty, bPreplacedObjectives, 0x20 )
			ADD_VAR( ::BoolProperty, bFriendlyFireDeployables, 0x100 )
			ADD_VAR( ::BoolProperty, bPoweredDeployables, 0x8 )
			ADD_VAR( ::BoolProperty, bFriendlyFireBaseAssets, 0x80 )
			ADD_VAR( ::IntProperty, BaseDestructionLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxSpeedWithFlagLight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxSpeedWithFlagMedium, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxSpeedWithFlagHeavy, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DecelerationRateWithFlag, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSupplyDropAmmoOnly, 0x200 )
			ADD_VAR( ::FloatProperty, fEnergyMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTeamCredits, 0x800 )
			ADD_VAR( ::IntProperty, RespawnTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TeamAssignType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VehiclePrices, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FFKillLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FFDamageLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CallinPrices, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CallinBuildups, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CallinCooldowns, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TimeLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OvertimeLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, WarmupTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoBalanceInGame, 0x2 )
			ADD_VAR( ::FloatProperty, fFriendlyFireDamageMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ArenaRounds, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GameScores, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCTFBlitzAllFlagsMove, 0x2000 )
			ADD_VAR( ::BoolProperty, bFriendlyFire, 0x1 )
			ADD_VAR( ::BoolProperty, bPoweredCallins, 0x400 )
			ADD_VAR( ::BoolProperty, bSkiEnabled, 0x1000 )
			ADD_VAR( ::IntProperty, SpawnType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGeneratorAutoRegen, 0x10 )
			ADD_VAR( ::BoolProperty, bGenDestroyable, 0x40 )
			ADD_VAR( ::FloatProperty, fAoEDamageMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fAoESizeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, fVehicleHealthMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CallinsDenied, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VehicleLimits, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ClassCounts, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ScoreLimit, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
