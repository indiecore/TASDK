#pragma once
#include "Engine__SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_AIMoveToActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_AIMoveToActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_AIMoveToActor : public SeqAct_Latent
	{
	public:
		ADD_VAR(::IntProperty, LastDestinationChoice, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LookAt)
		ADD_VAR(::FloatProperty, MovementSpeedModifier, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPickClosest, 0x2)
		ADD_VAR(::BoolProperty, bInterruptable, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
