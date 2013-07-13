#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameThirdPersonCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameThirdPersonCamera." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameThirdPersonCamera." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameThirdPersonCamera : public GameCameraBase
	{
	public:
			ADD_STRUCT( ::VectorProperty, LastOffsetAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LastPreModifierCameraRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastPreModifierCameraLoc, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastWorstLocationLocal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WorstLocInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirectLookInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DirectLookYaw, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastPostCamTurnYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnTotalTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TurnEndAngle, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TurnStartAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnCurTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDebugChangedCameraMode, 0x40 )
			ADD_VAR( ::BoolProperty, bDoingDirectLook, 0x20 )
			ADD_VAR( ::BoolProperty, bDrawDebug, 0x10 )
			ADD_VAR( ::BoolProperty, bTurnAlignTargetWhenFinished, 0x8 )
			ADD_VAR( ::BoolProperty, bDoingACameraTurn, 0x4 )
			ADD_VAR( ::BoolProperty, bFocusPointSuccessful, 0x2 )
			ADD_VAR( ::BoolProperty, bFocusPointSet, 0x1 )
			ADD_STRUCT( ::VectorProperty, LastFocusPointLoc, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ActualFocusPointWorldLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastFocusChangeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Focus_FastAdjustKickInTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Focus_MaxTries, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Focus_StepHeightAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Focus_BackOffStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftoverPitchAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastYawAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPitchAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHeightAdjustment, 0xFFFFFFFF )
			ADD_OBJECT( GameThirdPersonCameraMode, CurrentCamMode )
			ADD_OBJECT( GameThirdPersonCameraMode, ThirdPersonCamDefault )
			ADD_VAR( ::FloatProperty, LastCamFOV, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastViewOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OriginOffsetInterpSpeed, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LastActualCameraOriginRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastActualOriginOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationExtentScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationBlockedPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PenetrationBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WorstLocPenetrationExtentScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WorstLocBlockedPct, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastActualCameraOrigin, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
