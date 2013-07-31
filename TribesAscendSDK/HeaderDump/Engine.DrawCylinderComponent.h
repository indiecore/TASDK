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
	class DrawCylinderComponent : public PrimitiveComponent
	{
	public:
		ADD_BOOL(bDrawOnlyIfSelected, 516, 0x4)
		ADD_BOOL(bDrawLitCylinder, 516, 0x2)
		ADD_BOOL(bDrawWireCylinder, 516, 0x1)
		ADD_STRUCT(int, CylinderSides, 512)
		ADD_STRUCT(float, CylinderHeightOffset, 508)
		ADD_STRUCT(float, CylinderHeight, 504)
		ADD_STRUCT(float, CylinderTopRadius, 500)
		ADD_STRUCT(float, CylinderRadius, 496)
		ADD_OBJECT(Material, CylinderMaterial, 492)
		ADD_STRUCT(Object::Color, CylinderColor, 488)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
