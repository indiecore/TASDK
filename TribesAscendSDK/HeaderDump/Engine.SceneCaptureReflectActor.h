#pragma once
#include "Engine.SceneCaptureActor.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SceneCaptureReflectActor : public SceneCaptureActor
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, ReflectMaterialInst, 484)
	};
}
#undef ADD_OBJECT
