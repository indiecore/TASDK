#pragma once
#include "GameFramework__GamePlayerCamera.h"
#include "GameFramework__GameCameraBase.h"
#include "Engine__Actor.h"
#include "GameFramework__GameThirdPersonCameraMode.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameThirdPersonCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameThirdPersonCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameThirdPersonCamera." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameThirdPersonCamera : public GameCameraBase
	{
	public:
		ADD_STRUCT(::VectorProperty, LastOffsetAdjustment, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, LastPreModifierCameraRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastPreModifierCameraLoc, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastWorstLocationLocal, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WorstLocInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirectLookInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DirectLookYaw, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastPostCamTurnYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnTotalTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TurnEndAngle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TurnStartAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnCurTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDebugChangedCameraMode, 0x40)
		ADD_VAR(::BoolProperty, bDoingDirectLook, 0x20)
		ADD_VAR(::BoolProperty, bDrawDebug, 0x10)
		ADD_VAR(::BoolProperty, bTurnAlignTargetWhenFinished, 0x8)
		ADD_VAR(::BoolProperty, bDoingACameraTurn, 0x4)
		ADD_VAR(::BoolProperty, bFocusPointSuccessful, 0x2)
		ADD_VAR(::BoolProperty, bFocusPointSet, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameThirdPersonCamera.CamFocusPointParams' for the property named 'FocusPoint'!
		ADD_STRUCT(::VectorProperty, LastFocusPointLoc, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ActualFocusPointWorldLoc, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LastFocusChangeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Focus_FastAdjustKickInTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Focus_MaxTries, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Focus_StepHeightAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Focus_BackOffStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftoverPitchAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastYawAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPitchAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHeightAdjustment, 0xFFFFFFFF)
		ADD_OBJECT(GameThirdPersonCameraMode, CurrentCamMode)
		ADD_OBJECT(ScriptClass, ThirdPersonCamDefaultClass)
		ADD_OBJECT(GameThirdPersonCameraMode, ThirdPersonCamDefault)
		ADD_VAR(::FloatProperty, LastCamFOV, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastViewOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, OriginOffsetInterpSpeed, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LastActualCameraOriginRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastActualOriginOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, PenetrationExtentScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PenetrationBlockedPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PenetrationBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PenetrationBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WorstLocPenetrationExtentScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WorstLocBlockedPct, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastActualCameraOrigin, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'CreateCameraMode'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'GetDesiredFOV'
		// Here lies the not-yet-implemented method 'UpdateCamera'
		// Here lies the not-yet-implemented method 'UpdateCameraMode'
		// Here lies the not-yet-implemented method 'PlayerUpdateCamera'
		// Here lies the not-yet-implemented method 'BeginTurn'
		// Here lies the not-yet-implemented method 'EndTurn'
		// Here lies the not-yet-implemented method 'AdjustTurn'
		// Here lies the not-yet-implemented method 'SetFocusOnLoc'
		// Here lies the not-yet-implemented method 'SetFocusOnActor'
		// Here lies the not-yet-implemented method 'GetFocusActor'
		// Here lies the not-yet-implemented method 'ClearFocusPoint'
		// Here lies the not-yet-implemented method 'UpdateFocusPoint'
		// Here lies the not-yet-implemented method 'GetActualFocusLocation'
		// Here lies the not-yet-implemented method 'AdjustFocusPointInterpolation'
		// Here lies the not-yet-implemented method 'FindBestCameraMode'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'OnBecomeActive'
		// Here lies the not-yet-implemented method 'ModifyPostProcessSettings'
		// Here lies the not-yet-implemented method 'ResetInterpolation'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
