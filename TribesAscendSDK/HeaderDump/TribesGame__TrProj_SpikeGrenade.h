#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrProj_SpikeGrenade." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrProj_SpikeGrenade." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrProj_SpikeGrenade." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_SpikeGrenade : public TrProj_Grenade
	{
	public:
			ADD_OBJECT( SoundCue, m_FractalExplosionSound )
			ADD_OBJECT( ParticleSystem, m_FractalBeamTemplate )
			ADD_OBJECT( ParticleSystem, m_FractalExplosionTemplate )
			ADD_VAR( ::FloatProperty, m_fFractalDamageRadius, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nFractalDamage, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_vFlashExplosionLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vAscentLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fZFractalShotDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFractalShotDistance, 0xFFFFFFFF )
			ADD_OBJECT( SkelControlSingleBone, m_AscendControl )
			ADD_STRUCT( ::VectorProperty, m_CachedHitNormal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAscentHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAscentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFractalInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFractalTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingFractalTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bStartedFractal, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
