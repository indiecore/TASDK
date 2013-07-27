#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.h"
#include "Engine.ForceFieldShape.h"
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
	class NxForceFieldComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<Object::Pointer>, ConvexMeshes, 516)
		ADD_STRUCT(ScriptArray<Object::Pointer>, ExclusionShapes, 528)
		ADD_STRUCT(ScriptArray<Object::Pointer>, ExclusionShapePoses, 540)
		ADD_STRUCT(Object::Pointer, RBPhysScene, 564)
		ADD_STRUCT(float, ElapsedTime, 556)
		ADD_STRUCT(int, SceneIndex, 552)
		ADD_STRUCT(Object::Pointer, ForceField, 512)
		ADD_STRUCT(float, Duration, 508)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, CollideWithChannels, 504)
		ADD_BOOL(bDestroyWhenInactive, 500, 0x2)
		ADD_BOOL(bForceActive, 500, 0x1)
		ADD_STRUCT(int, ExcludeChannel, 496)
		ADD_OBJECT(ForceFieldShape, Shape, 488)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceFieldComponent.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
