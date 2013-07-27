#pragma once
#include "Engine.HUD.h"
#include "Engine.AICommandBase.h"
#include "GameFramework.GameAIController.h"
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameAICommand : public AICommandBase
	{
	public:
		ADD_BOOL(bPendingPop, 84, 0x20)
		ADD_BOOL(bIgnoreStepAside, 84, 0x10)
		ADD_BOOL(bIgnoreNotifies, 84, 0x8)
		ADD_BOOL(bAborted, 84, 0x4)
		ADD_BOOL(bReplaceActiveSameClassInstance, 84, 0x2)
		ADD_BOOL(bAllowNewSameClassInstance, 84, 0x1)
		ADD_STRUCT(ScriptName, Status, 76)
		ADD_OBJECT(GameAIController, GameAIOwner, 72)
		ADD_STRUCT(ScriptName, ChildStatus, 64)
		ADD_OBJECT(GameAICommand, ChildCommand, 60)
		bool InitCommandUserActor(class GameAIController* AI, class Actor* UserActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InitCommandUserActor");
			byte params[12] = { NULL };
			*(class GameAIController**)&params[0] = AI;
			*(class Actor**)&params[4] = UserActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool InitCommand(class GameAIController* AI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InitCommand");
			byte params[8] = { NULL };
			*(class GameAIController**)&params[0] = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InternalPrePushed(class GameAIController* AI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalPrePushed");
			byte params[4] = { NULL };
			*(class GameAIController**)&params[0] = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class GameAICommand**)&params[0] = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InternalResumed(ScriptName OldCommandName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalResumed");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = OldCommandName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InternalTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.InternalTick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldIgnoreNotifies()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.ShouldIgnoreNotifies");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTransitionTo(ScriptClass* AttemptCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.AllowTransitionTo");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = AttemptCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowStateTransitionTo(ScriptName StateName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.AllowStateTransitionTo");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = StateName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PrePushed(class GameAIController* AI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.PrePushed");
			byte params[4] = { NULL };
			*(class GameAIController**)&params[0] = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class GameAICommand**)&params[0] = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Resumed(ScriptName OldCommandName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.Resumed");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = OldCommandName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDumpString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.GetDumpString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void DrawDebug(class HUD* H, ScriptName Category)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.DrawDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = H;
			*(ScriptName*)&params[4] = Category;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetDebugOverheadText(class PlayerController* PC, ScriptArray<ScriptString*>& OutText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.GetDebugOverheadText");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(ScriptArray<ScriptString*>*)&params[4] = OutText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutText = *(ScriptArray<ScriptString*>*)&params[4];
		}
		ScriptString* GetDebugVerboseText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICommand.GetDebugVerboseText");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
