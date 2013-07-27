#pragma once
#include "Core.Object.h"
#include "Engine.InterpGroup.h"
#include "Engine.PostProcessVolume.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class CameraAnim : public Object
	{
	public:
		ADD_STRUCT(float, BaseFOV, 320)
		ADD_STRUCT(float, BasePPSettingsAlpha, 316)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, BasePPSettings, 96)
		ADD_STRUCT(Object::Box, BoundingBox, 68)
		ADD_STRUCT(float, AnimLength, 64)
		ADD_OBJECT(InterpGroup, CameraInterpGroup, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
