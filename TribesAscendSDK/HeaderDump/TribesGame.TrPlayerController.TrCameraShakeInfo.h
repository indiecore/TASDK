#pragma once
#include "Engine.CameraShake.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrPlayerController.TrCameraShakeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrPlayerController.TrCameraShakeInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCameraShakeInfo
	{
	public:
		ADD_VAR(::NameProperty, ShakeName, 0xFFFFFFFF)
		ADD_OBJECT(CameraShake, Shake)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
