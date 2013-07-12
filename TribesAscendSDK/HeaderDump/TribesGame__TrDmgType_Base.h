#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDmgType_Base." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDmgType_Base." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDmgType_Base." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDmgType_Base : public UTDamageType
	{
	public:
			ADD_VAR( ::IntProperty, DBWeaponId, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstArmor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstNonArmoredObjectives, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EnergyDrainAmount, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_RingingSound )
			ADD_VAR( ::NameProperty, m_nmTakeHitSoundMode, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bCausesGib, 0x1 )
			ADD_VAR( ::FloatProperty, m_fGibRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fGibStrength, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_GibFalloff, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bEnableMotors, 0x2 )
			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstGenerators, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nKillIconIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_nmCameraShake, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOffhandType, 0x10 )
			ADD_VAR( ::BoolProperty, m_bImpulsesFlags, 0x8 )
			ADD_VAR( ::BoolProperty, m_bIgnoreDamageFalloff, 0x4 )
			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstShrike, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBulletDamageRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinDamagePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinDamageRangePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxDamageRangePct, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponTypeId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponBaseId, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
