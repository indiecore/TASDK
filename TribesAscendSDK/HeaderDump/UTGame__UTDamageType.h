#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTDamageType." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTDamageType." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTDamageType." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDamageType : public DamageType
	{
	public:
			ADD_OBJECT( CameraAnim, DamageCameraAnim )
			ADD_VAR( ::BoolProperty, bLocationalHit, 0x2 )
			ADD_VAR( ::BoolProperty, bDirectDamage, 0x10 )
			ADD_VAR( ::BoolProperty, bHeadGibCamera, 0x40000 )
			ADD_VAR( ::FloatProperty, GibPerterbation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseDamageBasedDeathEffects, 0x2000 )
			ADD_VAR( ::NameProperty, DeathAnim, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAnimateHipsForDeathAnim, 0x8000 )
			ADD_VAR( ::FloatProperty, DeathAnimRate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSeversHead, 0x20 )
			ADD_VAR( ::FloatProperty, MotorDecayTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StopAnimAfterDamageInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageOverlayTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, XRayEffectTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCausesBloodSplatterDecals, 0x80000 )
			ADD_VAR( ::BoolProperty, bCausesBlood, 0x1 )
			ADD_VAR( ::FloatProperty, PhysicsTakeHitMomentumThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSpecialDeathCamera, 0x4000 )
			ADD_VAR( ::BoolProperty, bThrowRagdoll, 0x100 )
			ADD_VAR( ::BoolProperty, bOverrideHitEffectColor, 0x20000 )
			ADD_VAR( ::StrProperty, MaleSuicide, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FemaleSuicide, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DeathString, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CustomTauntIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, RewardEvent, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RewardAnnouncementSwitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RewardCount, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SuicideStatsName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DeathStatsName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, KillStatsName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NodeDamageScaling, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, GibTrail )
			ADD_VAR( ::IntProperty, DamageWeaponFireMode, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AlwaysGibDamageThreshold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinAccumulateDamageThreshold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GibThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDontHurtInstigator, 0x100000 )
			ADD_VAR( ::BoolProperty, bComplainFriendlyFire, 0x10000 )
			ADD_VAR( ::BoolProperty, bSelfDestructDamage, 0x1000 )
			ADD_VAR( ::BoolProperty, bVehicleHit, 0x800 )
			ADD_VAR( ::BoolProperty, bBulletHit, 0x400 )
			ADD_VAR( ::BoolProperty, bLeaveBodyEffect, 0x200 )
			ADD_VAR( ::BoolProperty, bUseTearOffMomentum, 0x80 )
			ADD_VAR( ::BoolProperty, bCauseConvulsions, 0x40 )
			ADD_VAR( ::BoolProperty, bNeverGibs, 0x8 )
			ADD_VAR( ::BoolProperty, bAlwaysGibs, 0x4 )
			ADD_VAR( ::FloatProperty, DeathOverlayTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
