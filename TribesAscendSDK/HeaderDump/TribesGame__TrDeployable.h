#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable : public TrGameObjective
	{
	public:
			ADD_OBJECT( Controller, m_Controller )
			ADD_VAR( ::IntProperty, m_nIconStackId, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vDeathCamStartOffset, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, r_OwnerPRI )
			ADD_VAR( ::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeScalePlayRate, m_AnimNodeScale )
			ADD_OBJECT( Actor, m_LastViewer )
			ADD_OBJECT( PlayerController, m_LastRealViewer )
			ADD_VAR( ::FloatProperty, m_fNetRelevancyTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_DeploySound )
			ADD_OBJECT( TrPowerGenerator, m_MyMainGenerator )
			ADD_OBJECT( Pawn, r_TargetPawn )
			ADD_VAR( ::ByteProperty, r_FlashCount, 0xFFFFFFFF )
			ADD_OBJECT( TrSubDevice, m_Weapon )
			ADD_OBJECT( TrTurretPawn, m_WeaponHolder )
			ADD_VAR( ::FloatProperty, m_fAlwaysRelevantDistanceSquared, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fNewDetectionRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageRadius, 0xFFFFFFFF )
			ADD_OBJECT( TrDeployableCollisionProxy, m_CollisionProxy )
			ADD_VAR( ::FloatProperty, m_fOverriddenTargetComponentHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_TargetCollisionTraceDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFiringArcCheckValue, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_PlacementOrientationVector, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nFiringArcDegrees, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bBlocksFriendlies, 0x80 )
			ADD_VAR( ::BoolProperty, m_bCanBeSpottedByVGS, 0x40 )
			ADD_VAR( ::BoolProperty, m_bIsXRay, 0x20 )
			ADD_VAR( ::BoolProperty, m_bCachedRelevant, 0x10 )
			ADD_VAR( ::BoolProperty, m_bOverrideTargetComponentHeight, 0x8 )
			ADD_VAR( ::BoolProperty, m_bUsesArmoredMultiplier, 0x4 )
			ADD_VAR( ::BoolProperty, m_bRequireLOS, 0x2 )
			ADD_VAR( ::BoolProperty, m_bIsDeployed, 0x1 )
			ADD_VAR( ::FloatProperty, m_fTimeToDeploySecs, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemoteActivationTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBuildupTime, 0xFFFFFFFF )
			ADD_OBJECT( TrPawn, m_TouchedPlayer )
			ADD_VAR( ::FloatProperty, m_TimeCreated, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxDeployablesOut, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
