#pragma once
#include "Engine__Actor.h"
#include "Engine__SequenceOp.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SequenceEvent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SequenceEvent : public SequenceOp
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::IntProperty, MaxTriggerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TriggerCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPlayerOnly, 0x2)
		ADD_VAR(::IntProperty, MaxWidth, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClientSideOnly, 0x8)
		ADD_VAR(::BoolProperty, bRegistered, 0x4)
		ADD_VAR(::FloatProperty, ReTriggerDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ActivationTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Instigator)
		ADD_OBJECT(Actor, Originator)
		bool CheckActivate(class Actor* InOriginator, class Actor* InInstigator, bool bTest, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActivateIndices, bool bPushTop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceEvent.CheckActivate");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = InOriginator;
			*(class Actor**)(params + 4) = InInstigator;
			*(bool*)(params + 8) = bTest;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = ActivateIndices;
			*(bool*)(params + 24) = bPushTop;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ActivateIndices = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void RegisterEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceEvent.RegisterEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceEvent.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Toggled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceEvent.Toggled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
