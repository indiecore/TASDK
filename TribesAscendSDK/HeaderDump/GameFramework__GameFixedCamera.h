#pragma once
#include "GameFramework__GamePlayerCamera.h"
#include "GameFramework__GameCameraBase.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameFixedCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameFixedCamera : public GameCameraBase
	{
	public:
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'UpdateCamera'
		// Here lies the not-yet-implemented method 'OnBecomeActive'
	};
}
#undef ADD_VAR
