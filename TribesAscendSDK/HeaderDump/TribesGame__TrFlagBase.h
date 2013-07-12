#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrFlagBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrFlagBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrFlagBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrFlagBase : public UTCarriedObject
	{
	public:
			ADD_VAR( ::FloatProperty, m_fRageRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageMomentumDampingWhileFalling, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nDropFlagPingThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTeammatePassMaxDistanceSq, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNumBounces, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNumBouncesBeforeSlide, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fIgnoreSameTeamTouch, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxyLevel3 )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxyLevel2 )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxyLevel1 )
			ADD_VAR( ::FloatProperty, m_fBounceDampingPercent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fForwardThrowVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInheritVelocityPct, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_TimeAwaySeconds, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastCameraPos, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastCameraDir, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastScreenLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_FlagIconAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFriction, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMass, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastLocationPingTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, HoverboardingClothVelClamp, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RunningClothVelClamp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bPassToTeammatesEnabled, 0x80 )
			ADD_VAR( ::BoolProperty, m_bBounceSlideEnabled, 0x40 )
			ADD_VAR( ::BoolProperty, bWasFlagReturned, 0x20 )
			ADD_VAR( ::BoolProperty, bWasClothEnabled, 0x10 )
			ADD_VAR( ::BoolProperty, bRespawning, 0x8 )
			ADD_VAR( ::BoolProperty, bFadingOut, 0x4 )
			ADD_VAR( ::BoolProperty, bBringDownFromBright, 0x2 )
			ADD_VAR( ::BoolProperty, bBringUpBright, 0x1 )
			ADD_OBJECT( ParticleSystem, RespawnEffect )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
