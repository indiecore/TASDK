#pragma once
#include "Engine__HUD.h"
#include "Engine__Camera.h"
#include "Engine__Actor.h"
#include "GameFramework__GameCameraBase.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GamePlayerCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GamePlayerCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GamePlayerCamera." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GamePlayerCamera : public Camera
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'LastTargetBaseTM'!
		ADD_OBJECT(Actor, LastTargetBase)
		ADD_VAR(::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastViewTarget)
		ADD_VAR(::FloatProperty, ForcedCamFOV, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bResetInterp, 0x4)
		ADD_VAR(::BoolProperty, bInterpolateCamChanges, 0x2)
		ADD_VAR(::BoolProperty, bUseForcedCamFOV, 0x1)
		ADD_OBJECT(GameCameraBase, CurrentCamera)
		ADD_OBJECT(ScriptClass, FixedCameraClass)
		ADD_OBJECT(GameCameraBase, FixedCam)
		ADD_OBJECT(ScriptClass, ThirdPersonCameraClass)
		ADD_OBJECT(GameCameraBase, ThirdPersonCam)
		// Here lies the not-yet-implemented method 'CreateCamera'
		// Here lies the not-yet-implemented method 'CacheLastTargetBaseInfo'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'FindBestCameraType'
		// Here lies the not-yet-implemented method 'ShouldConstrainAspectRatio'
		// Here lies the not-yet-implemented method 'UpdateViewTarget'
		// Here lies the not-yet-implemented method 'AdjustFOVForViewport'
		// Here lies the not-yet-implemented method 'UpdateCameraLensEffects'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'SetColorScale'
		// Here lies the not-yet-implemented method 'ResetInterpolation'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
