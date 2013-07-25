#pragma once
#include "Engine__SequenceEvent.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_Touch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Touch : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bAllowDeadPawns, 0x4)
		ADD_VAR(::BoolProperty, bUseInstigator, 0x2)
		ADD_VAR(::BoolProperty, bForceOverlapping, 0x1)
		bool CheckTouchActivate(class Actor* InOriginator, class Actor* InInstigator, bool bTest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.CheckTouchActivate");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = InOriginator;
			*(class Actor**)(params + 4) = InInstigator;
			*(bool*)(params + 8) = bTest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CheckUnTouchActivate(class Actor* InOriginator, class Actor* InInstigator, bool bTest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.CheckUnTouchActivate");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = InOriginator;
			*(class Actor**)(params + 4) = InInstigator;
			*(bool*)(params + 8) = bTest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void Toggled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.Toggled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTouchingPawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.NotifyTouchingPawnDied");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
