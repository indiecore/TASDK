#pragma once
#include "Core.Object.h"
#include "Engine.InterpTrackInst.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstMove : public InterpTrackInst
	{
	public:
		ADD_STRUCT(Object::Quat, InitialQuat, 160)
		ADD_STRUCT(Object::Matrix, InitialTM, 96)
		ADD_STRUCT(Rotator, ResetRotation, 72)
		ADD_STRUCT(Vector, ResetLocation, 60)
	};
}
#undef ADD_STRUCT
