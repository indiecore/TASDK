#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_TrackingMissile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_TrackingMissile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_TrackingMissile." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_TrackingMissile : public TrProjectile
	{
	public:
			ADD_VAR( ::FloatProperty, m_fLoseTightTrackingDistance, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_MissileCaratRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fStage1MinGroundDist, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vLastKnownTargetLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInitialLocationZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinHeightGainForGoodLOS, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fIdealHeightAboveTargetForGoodLOS, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAdjustingForGoodLOSAccelRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTrackingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTrackingDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLOSDelay, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bLostTightHoming, 0x2 )
			ADD_VAR( ::BoolProperty, m_bHasBentToTarget, 0x1 )
			ADD_VAR( ::ByteProperty, m_MissileStage, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
