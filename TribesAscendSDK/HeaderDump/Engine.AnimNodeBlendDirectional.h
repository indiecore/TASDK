#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendDirectional : public AnimNodeBlendBase
	{
	public:
		ADD_BOOL(bUseAcceleration, 268, 0x1)
		ADD_STRUCT(Object::Rotator, RotationOffset, 256)
		ADD_STRUCT(int, SingleAnimAtOrAboveLOD, 252)
		ADD_STRUCT(float, DirAngle, 248)
		ADD_STRUCT(float, DirDegreesPerSecond, 244)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
