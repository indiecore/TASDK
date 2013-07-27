#pragma once
#include "Core.Object.h"
#include "Engine.MaterialInterface.h"
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
	class SpeedTree : public Object
	{
	public:
		ADD_STRUCT(Object::Guid, LightingGuid, 112)
		ADD_STRUCT(Vector, WindDirection, 100)
		ADD_STRUCT(float, WindStrength, 96)
		ADD_OBJECT(MaterialInterface, BillboardMaterial, 92)
		ADD_OBJECT(MaterialInterface, LeafMeshMaterial, 88)
		ADD_OBJECT(MaterialInterface, LeafCardMaterial, 84)
		ADD_OBJECT(MaterialInterface, FrondMaterial, 80)
		ADD_OBJECT(MaterialInterface, Branch2Material, 76)
		ADD_OBJECT(MaterialInterface, Branch1Material, 72)
		ADD_STRUCT(float, LeafStaticShadowOpacity, 68)
		ADD_STRUCT(Object::Pointer, SRH, 64)
		ADD_BOOL(bLegacySpeedTree, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
