#pragma once
#include "Engine.ApexStaticComponent.h"
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
	class ApexStaticDestructibleComponent : public ApexStaticComponent
	{
	public:
		ADD_BOOL(bIsThumbnailComponent, 536, 0x1)
		ADD_STRUCT(Object::Pointer, ApexDestructiblePreview, 532)
		ADD_STRUCT(Object::Pointer, ApexDestructibleActor, 528)
		ADD_STRUCT(float, SleepDamping, 524)
		ADD_STRUCT(float, SleepEnergyThreshold, 520)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
