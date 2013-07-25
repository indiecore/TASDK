#pragma once
#include "Engine__SequenceAction.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ParticleEventGenerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_ParticleEventGenerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_ParticleEventGenerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ParticleEventGenerator : public SequenceAction
	{
	public:
		ADD_STRUCT(::VectorProperty, EventNormal, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, EventVelocity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, EventDirection, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, EventLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, EventTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Instigator)
		ADD_VAR(::BoolProperty, bUseEmitterLocation, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
