#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.SeqAct_Toggle.h"
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
	class NxForceField : public Actor
	{
	public:
		ADD_STRUCT(ScriptArray<Object::Pointer>, ConvexMeshes, 496)
		ADD_STRUCT(ScriptArray<Object::Pointer>, ExclusionShapes, 508)
		ADD_STRUCT(ScriptArray<Object::Pointer>, ExclusionShapePoses, 520)
		ADD_STRUCT(int, SceneIndex, 536)
		ADD_STRUCT(Object::Pointer, U2NRotation, 532)
		ADD_STRUCT(Object::Pointer, ForceField, 492)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, RBChannel, 488)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, CollideWithChannels, 484)
		ADD_BOOL(bForceActive, 480, 0x1)
		ADD_STRUCT(int, ExcludeChannel, 476)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceField.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceField.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
