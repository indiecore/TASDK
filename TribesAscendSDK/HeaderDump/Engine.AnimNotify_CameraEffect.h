#pragma once
#include "Engine.AnimNotify.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_CameraEffect : public AnimNotify
	{
	public:
		ADD_OBJECT(ScriptClass, CameraLensEffect, 64)
	};
}
#undef ADD_OBJECT
