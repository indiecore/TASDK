#pragma once
#include "Engine.AnimNotify.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNotify_CameraEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_CameraEffect : public AnimNotify
	{
	public:
		ADD_OBJECT(ScriptClass, CameraLensEffect)
	};
}
#undef ADD_OBJECT
