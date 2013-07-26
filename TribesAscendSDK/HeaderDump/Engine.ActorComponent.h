#pragma once
#include "Core.Component.h"
#include "Engine.Actor.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ActorComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorComponent : public Component
	{
	public:
		ADD_VAR(::ByteProperty, TickGroup, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeedsUpdateTransform, 0x8)
		ADD_VAR(::BoolProperty, bNeedsReattach, 0x4)
		ADD_VAR(::BoolProperty, bTickInEditor, 0x2)
		ADD_VAR(::BoolProperty, bAttached, 0x1)
		ADD_OBJECT(Actor, Owner)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Scene, 0xFFFFFFFF)
		void SetTickGroup(byte NewTickGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ActorComponent.SetTickGroup");
			byte* params = (byte*)malloc(1);
			*params = NewTickGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetComponentRBFixed(bool bFixed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ActorComponent.SetComponentRBFixed");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFixed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceUpdate(bool bTransformOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ActorComponent.ForceUpdate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bTransformOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachFromAny()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ActorComponent.DetachFromAny");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
