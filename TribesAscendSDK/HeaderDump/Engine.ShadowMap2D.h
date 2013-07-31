#pragma once
#include "Core.Object.h"
#include "Engine.ShadowMapTexture2D.h"
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
	class ShadowMap2D : public Object
	{
	public:
		ADD_STRUCT(int, InstanceIndex, 104)
		ADD_BOOL(bIsShadowFactorTexture, 96, 0x1)
		ADD_STRUCT(Object::Guid, LightGuid, 80)
		ADD_STRUCT(Object::Vector2D, CoordinateBias, 72)
		ADD_STRUCT(Object::Vector2D, CoordinateScale, 64)
		ADD_OBJECT(ShadowMapTexture2D, Texture, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
