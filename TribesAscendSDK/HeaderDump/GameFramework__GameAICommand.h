#pragma once
#include "Engine__AICommandBase.h"
#include "GameFramework__GameAIController.h"
#include "Engine__Actor.h"
#include "Engine__HUD.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameAICommand." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameAICommand." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameAICommand : public AICommandBase
	{
	public:
		ADD_VAR(::BoolProperty, bPendingPop, 0x20)
		ADD_VAR(::BoolProperty, bIgnoreStepAside, 0x10)
		ADD_VAR(::BoolProperty, bIgnoreNotifies, 0x8)
		ADD_VAR(::BoolProperty, bAborted, 0x4)
		ADD_VAR(::BoolProperty, bReplaceActiveSameClassInstance, 0x2)
		ADD_VAR(::BoolProperty, bAllowNewSameClassInstance, 0x1)
		ADD_VAR(::NameProperty, Status, 0xFFFFFFFF)
		ADD_OBJECT(GameAIController, GameAIOwner)
		ADD_VAR(::NameProperty, ChildStatus, 0xFFFFFFFF)
		ADD_OBJECT(GameAICommand, ChildCommand)
		bool InitCommandUserActor(class GameAIController* AI, class Actor* UserActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InitCommandUserActor");
			byte* params = (byte*)malloc(12);
			*(class GameAIController**)params = AI;
			*(class Actor**)(params + 4) = UserActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool InitCommand(class GameAIController* AI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InitCommand");
			byte* params = (byte*)malloc(8);
			*(class GameAIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void InternalPrePushed(class GameAIController* AI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalPrePushed");
			byte* params = (byte*)malloc(4);
			*(class GameAIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InternalPushed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalPushed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InternalPopped()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalPopped");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InternalPaused(class GameAICommand* NewCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalPaused");
			byte* params = (byte*)malloc(4);
			*(class GameAICommand**)params = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InternalResumed(ScriptName OldCommandName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalResumed");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = OldCommandName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InternalTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalTick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldIgnoreNotifies()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.ShouldIgnoreNotifies");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowTransitionTo(ScriptClass* AttemptCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.AllowTransitionTo");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = AttemptCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowStateTransitionTo(ScriptName StateName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.AllowStateTransitionTo");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = StateName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void PrePushed(class GameAIController* AI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.PrePushed");
			byte* params = (byte*)malloc(4);
			*(class GameAIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostPopped()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.PostPopped");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pushed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.Pushed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Popped()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.Popped");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Paused(class GameAICommand* NewCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.Paused");
			byte* params = (byte*)malloc(4);
			*(class GameAICommand**)params = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Resumed(ScriptName OldCommandName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.Resumed");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = OldCommandName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetDumpString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.GetDumpString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void DrawDebug(class HUD* H, ScriptName Category)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.DrawDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = H;
			*(ScriptName*)(params + 4) = Category;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetDebugOverheadText(class PlayerController* PC, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.GetDebugOverheadText");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = OutText;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutText = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		ScriptArray<wchar_t> GetDebugVerboseText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.GetDebugVerboseText");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
