#pragma once
#include "Engine.PrimitiveComponent.h"
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
	class CylinderComponent : public PrimitiveComponent
	{
	public:
		ADD_BOOL(bAlwaysRenderIfSelected, 500, 0x4)
		ADD_BOOL(bDrawNonColliding, 500, 0x2)
		ADD_BOOL(bDrawBoundingBox, 500, 0x1)
		ADD_STRUCT(Object::Color, CylinderColor, 496)
		ADD_STRUCT(float, CollisionRadius, 492)
		ADD_STRUCT(float, CollisionHeight, 488)
		void SetCylinderSize(float NewRadius, float NewHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CylinderComponent.SetCylinderSize");
			byte params[8] = { NULL };
			*(float*)&params[0] = NewRadius;
			*(float*)&params[4] = NewHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
