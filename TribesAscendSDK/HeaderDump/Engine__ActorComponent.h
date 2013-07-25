#pragma once
#include "Engine__Actor.h"
#include "Core__Component.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Scene'!
		// Here lies the not-yet-implemented method 'SetTickGroup'
		// Here lies the not-yet-implemented method 'SetComponentRBFixed'
		// Here lies the not-yet-implemented method 'ForceUpdate'
		// Here lies the not-yet-implemented method 'DetachFromAny'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
