#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Material.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DrawSphereComponent : public PrimitiveComponent
	{
	public:
		ADD_BOOL(bDrawOnlyIfSelected, 504, 0x4)
		ADD_BOOL(bDrawLitSphere, 504, 0x2)
		ADD_BOOL(bDrawWireSphere, 504, 0x1)
		ADD_STRUCT(int, SphereSides, 500)
		ADD_STRUCT(float, SphereRadius, 496)
		ADD_OBJECT(Material, SphereMaterial, 492)
		ADD_STRUCT(Object::Color, SphereColor, 488)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
