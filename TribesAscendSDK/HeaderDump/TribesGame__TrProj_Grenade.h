#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrProj_Grenade." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrProj_Grenade." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrProj_Grenade." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_Grenade : public TrProjectile
	{
	public:
			ADD_VAR( ::BoolProperty, m_bStuckOnPlayer, 0x1 )
			ADD_VAR( ::FloatProperty, m_fProxyDetonationHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fProxyDetonationRadius, 0xFFFFFFFF )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxy )
			ADD_VAR( ::FloatProperty, m_fStuckMomentumMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fStuckDamageMultiplier, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_OverloadHitNormal, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_StuckOnPawnLoopingSound )
			ADD_OBJECT( ParticleSystem, m_StuckOnTargetTemplate )
			ADD_VAR( ::FloatProperty, m_fExplosionTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bSpawnProxyOnInit, 0x80 )
			ADD_VAR( ::BoolProperty, m_bScanProxyOnInit, 0x40 )
			ADD_VAR( ::BoolProperty, m_bFullyInheritVelocity, 0x20 )
			ADD_VAR( ::BoolProperty, m_bDoRandSpin, 0x10 )
			ADD_VAR( ::BoolProperty, m_bBounceRequiredForExplode, 0x8 )
			ADD_VAR( ::BoolProperty, m_bExplodeOnTouchEvent, 0x4 )
			ADD_VAR( ::BoolProperty, m_bTimedExplosion, 0x2 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
