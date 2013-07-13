#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameThirdPersonCameraMode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameThirdPersonCameraMode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameThirdPersonCameraMode." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameThirdPersonCameraMode : public Object
	{
	public:
			ADD_OBJECT( GameThirdPersonCamera, ThirdPersonCam )
			ADD_VAR( ::ByteProperty, CurrentViewportType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OffsetAdjustmentInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewOffsetInterp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_RadiusFalloff, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DOFTraceExtent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOFDistanceInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDOFDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDOFRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_MaxFarBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_MaxNearBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_FocusInnerRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_BlurKernelSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DOF_FalloffExponent, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetRelativeCameraOriginOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, WorstLocOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastRunOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RunOffsetInterpSpeedOut, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RunOffsetInterpSpeedIn, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RunOffsetScalingThreshold, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RunBackAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RunFwdAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastStrafeOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafeOffsetInterpSpeedOut, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafeOffsetInterpSpeedIn, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafeOffsetScalingThreshold, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StrafeRightAdjustment, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StrafeLeftAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OriginRotInterpSpeed, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PerAxisOriginLocInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OriginLocInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingCameraVelThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingInterpSpeed_Roll, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingInterpSpeed_Yaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowingInterpSpeed_Pitch, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInterpViewOffsetOnlyForCamTransition, 0x8000 )
			ADD_VAR( ::BoolProperty, bNoFOVPostProcess, 0x4000 )
			ADD_VAR( ::BoolProperty, bDOFUpdated, 0x2000 )
			ADD_VAR( ::BoolProperty, bAdjustDOF, 0x1000 )
			ADD_VAR( ::BoolProperty, bApplyDeltaViewOffset, 0x800 )
			ADD_VAR( ::BoolProperty, bSmoothViewOffsetPitchChanges, 0x400 )
			ADD_VAR( ::BoolProperty, bSkipCameraCollision, 0x200 )
			ADD_VAR( ::BoolProperty, bValidateWorstLoc, 0x100 )
			ADD_VAR( ::BoolProperty, bDoPredictiveAvoidance, 0x80 )
			ADD_VAR( ::BoolProperty, bRotInterpSpeedConstant, 0x40 )
			ADD_VAR( ::BoolProperty, bInterpRotation, 0x20 )
			ADD_VAR( ::BoolProperty, bUsePerAxisOriginLocInterp, 0x10 )
			ADD_VAR( ::BoolProperty, bInterpLocation, 0x8 )
			ADD_VAR( ::BoolProperty, bFollowTarget, 0x4 )
			ADD_VAR( ::BoolProperty, bDirectLook, 0x2 )
			ADD_VAR( ::BoolProperty, bLockedToViewTarget, 0x1 )
			ADD_VAR( ::FloatProperty, BlendTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FOVAngle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
