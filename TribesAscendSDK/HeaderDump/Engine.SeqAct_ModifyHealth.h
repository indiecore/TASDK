#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ModifyHealth." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_ModifyHealth." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ModifyHealth : public SequenceAction
	{
	public:
		ADD_OBJECT(Actor, Instigator)
		ADD_VAR(::BoolProperty, bHeal, 0x1)
		ADD_VAR(::FloatProperty, Amount, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DamageType)
		ADD_VAR(::FloatProperty, Momentum, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFalloff, 0x4)
		ADD_VAR(::BoolProperty, bRadial, 0x2)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_ModifyHealth.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
