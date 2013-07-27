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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30573);
			byte params[12] = { NULL };
			*(class GameAIController**)params = AI;
			*(class Actor**)&params[4] = UserActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool InitCommand(class GameAIController* AI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30577);
			byte params[8] = { NULL };
			*(class GameAIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InternalPrePushed(class GameAIController* AI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30581);
			byte params[4] = { NULL };
			*(class GameAIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InternalPushed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30583);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InternalPopped()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30584);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InternalPaused(class GameAICommand* NewCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30585);
			byte params[4] = { NULL };
			*(class GameAICommand**)params = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InternalResumed(ScriptName OldCommandName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30587);
			byte params[8] = { NULL };
			*(ScriptName*)params = OldCommandName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InternalTick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30589);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldIgnoreNotifies()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30591);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30593);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTransitionTo(ScriptClass* AttemptCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30595);
			byte params[8] = { NULL };
			*(ScriptClass**)params = AttemptCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowStateTransitionTo(ScriptName StateName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30598);
			byte params[12] = { NULL };
			*(ScriptName*)params = StateName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PrePushed(class GameAIController* AI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30601);
			byte params[4] = { NULL };
			*(class GameAIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostPopped()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30603);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pushed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30604);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Popped()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30605);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Paused(class GameAICommand* NewCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30606);
			byte params[4] = { NULL };
			*(class GameAICommand**)params = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Resumed(ScriptName OldCommandName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30608);
			byte params[8] = { NULL };
			*(ScriptName*)params = OldCommandName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDumpString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30610);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void DrawDebug(class HUD* H, ScriptName Category)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30623);
			byte params[12] = { NULL };
			*(class HUD**)params = H;
			*(ScriptName*)&params[4] = Category;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetDebugOverheadText(class PlayerController* PC, ScriptArray<ScriptString*>& OutText)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30626);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			*(ScriptArray<ScriptString*>*)&params[4] = OutText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutText = *(ScriptArray<ScriptString*>*)&params[4];
		}
		ScriptString* GetDebugVerboseText()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30630);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
