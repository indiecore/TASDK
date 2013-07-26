#pragma once
#include "Engine.SequenceEvent.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_ParticleEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqEvent_ParticleEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_ParticleEvent : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, UseRelfectedImpactVector, 0x1)
		ADD_STRUCT(::VectorProperty, EventNormal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EventParticleTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EventVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EventEmitterTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EventPosition, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EventType, 0xFFFFFFFF)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_ParticleEvent.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
