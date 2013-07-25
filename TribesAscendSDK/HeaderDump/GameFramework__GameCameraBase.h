#pragma once
#include "Core__Object.h"
#include "GameFramework__GamePlayerCamera.h"
#include "Engine__Pawn.h"
#include "Engine__Actor.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCameraBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCameraBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCameraBase : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bResetCameraInterpolation, 0x1)
		ADD_OBJECT(GamePlayerCamera, PlayerCamera)
		// Here lies the not-yet-implemented method 'OnBecomeActive'
		// Here lies the not-yet-implemented method 'OnBecomeInActive'
		// Here lies the not-yet-implemented method 'ResetInterpolation'
		// Here lies the not-yet-implemented method 'UpdateCamera'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'ModifyPostProcessSettings'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
