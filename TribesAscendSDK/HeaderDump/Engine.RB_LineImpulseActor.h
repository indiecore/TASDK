#pragma once
#include "Engine.RigidBodyBase.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_LineImpulseActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_LineImpulseActor : public RigidBodyBase
	{
	public:
		ADD_VAR(::ByteProperty, ImpulseCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCauseFracture, 0x4)
		ADD_VAR(::BoolProperty, bStopAtFirstHit, 0x2)
		ADD_VAR(::BoolProperty, bVelChange, 0x1)
		ADD_VAR(::FloatProperty, ImpulseRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpulseStrength, 0xFFFFFFFF)
		void FireLineImpulse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_LineImpulseActor.FireLineImpulse");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_LineImpulseActor.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_LineImpulseActor.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
