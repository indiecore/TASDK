#pragma once
#include "Engine.FracturedBaseComponent.h"
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
	class FracturedSkinnedMeshComponent : public FracturedBaseComponent
	{
	public:
		ADD_STRUCT(ScriptArray<Object::Matrix>, FragmentTransforms, 644)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, DependentComponents, 656)
		ADD_BOOL(bFragmentTransformsChanged, 668, 0x2)
		ADD_BOOL(bBecameVisible, 668, 0x1)
		ADD_STRUCT(Object::Pointer, ComponentSkinResources, 640)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
