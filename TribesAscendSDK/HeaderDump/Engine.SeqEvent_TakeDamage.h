#pragma once
#include "Engine.SequenceEvent.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_TakeDamage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_TakeDamage : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bResetDamageOnToggle, 0x1)
		ADD_VAR(::FloatProperty, CurrentDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinDamageAmount, 0xFFFFFFFF)
		bool IsValidDamageType(ScriptClass* inDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_TakeDamage.IsValidDamageType");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = inDamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void HandleDamage(class Actor* InOriginator, class Actor* InInstigator, ScriptClass* inDamageType, int inAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_TakeDamage.HandleDamage");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = InOriginator;
			*(class Actor**)(params + 4) = InInstigator;
			*(ScriptClass**)(params + 8) = inDamageType;
			*(int*)(params + 12) = inAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_TakeDamage.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_TakeDamage.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void Toggled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_TakeDamage.Toggled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
