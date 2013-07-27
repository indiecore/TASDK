#pragma once
#include "GameFramework.GameAICommand.h"
#include "Engine.FileLog.h"
#include "GameFramework.GameTypes.h"
#include "Engine.AIController.h"
#include "Core.Object.h"
#include "Engine.AITree.h"
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
	class GameAIController : public AIController
	{
	public:
		ADD_STRUCT(ScriptArray<GameTypes::AICmdHistoryItem>, CommandHistory, 992)
		ADD_STRUCT(ScriptArray<ScriptName>, AILogFilter, 1008)
		ADD_STRUCT(ScriptString*, DemoActionString, 1020)
		ADD_STRUCT(int, CommandHistoryNum, 1004)
		ADD_STRUCT(float, DebugTextMaxLen, 988)
		ADD_OBJECT(FileLog, AILogFile, 984)
		ADD_OBJECT(GameAICommand, CommandList, 980)
		ADD_BOOL(bAIBroken, 976, 0x80)
		ADD_BOOL(bAIDrawDebug, 976, 0x40)
		ADD_BOOL(bMapBasedLogName, 976, 0x20)
		ADD_BOOL(bFlushAILogEachLine, 976, 0x10)
		ADD_BOOL(bAILogToWindow, 976, 0x8)
		ADD_BOOL(bAILogging, 976, 0x4)
		ADD_BOOL(bHasRunawayCommandList, 976, 0x2)
		ADD_BOOL(bUseAITree, 976, 0x1)
		ADD_STRUCT(AITree::AITreeHandle, AITreeHandle, 928)
		ADD_OBJECT(AITree, AITree, 924)
		void AllCommands(ScriptClass* BaseClass, class GameAICommand*& Cmd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.AllCommands");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class GameAICommand**)&params[4] = Cmd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Cmd = *(class GameAICommand**)&params[4];
		}
		void PushCommand(class GameAICommand* NewCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.PushCommand");
			byte params[4] = { NULL };
			*(class GameAICommand**)&params[0] = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopCommand(class GameAICommand* ToBePoppedCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.PopCommand");
			byte params[4] = { NULL };
			*(class GameAICommand**)&params[0] = ToBePoppedCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AbortCommand(class GameAICommand* AbortCmd, ScriptClass* AbortClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.AbortCommand");
			byte params[12] = { NULL };
			*(class GameAICommand**)&params[0] = AbortCmd;
			*(ScriptClass**)&params[4] = AbortClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class GameAICommand* GetActiveCommand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetActiveCommand");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameAICommand**)&params[0];
		}
		void CheckCommandCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.CheckCommandCount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpCommandStack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.DumpCommandStack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GameAICommand* FindCommandOfClass(ScriptClass* SearchClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.FindCommandOfClass");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = SearchClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameAICommand**)&params[4];
		}
		class GameAICommand* GetAICommandInStack(ScriptClass* InClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetAICommandInStack");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = InClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameAICommand**)&params[4];
		}
		float GetDestinationOffset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetDestinationOffset");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void ReachedMoveGoal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.ReachedMoveGoal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReachedIntermediateMoveGoal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.ReachedIntermediateMoveGoal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecordDemoAILog(ScriptString* LogText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.RecordDemoAILog");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = LogText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AILog_Internal(ScriptString* LogText, ScriptName LogCategory, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.AILog_Internal");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = LogText;
			*(ScriptName*)&params[12] = LogCategory;
			*(bool*)&params[20] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDesiredRotation(Object::Rotator TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.SetDesiredRotation");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = TargetDesiredRotation;
			*(bool*)&params[12] = InLockDesiredRotation;
			*(bool*)&params[16] = InUnlockWhenReached;
			*(float*)&params[20] = InterpolationTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetActionString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetActionString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
