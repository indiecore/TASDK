#pragma once
#include "GameFramework.GameAICommand.h"
#include "Engine.FileLog.h"
#include "Engine.AIController.h"
#include "Engine.AITree.AITreeHandle.h"
#include "Engine.AITree.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameAIController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameAIController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameAIController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameAIController : public AIController
	{
	public:
		ADD_VAR(::StrProperty, DemoActionString, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CommandHistoryNum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DebugTextMaxLen, 0xFFFFFFFF)
		ADD_OBJECT(FileLog, AILogFile)
		ADD_OBJECT(GameAICommand, CommandList)
		ADD_VAR(::BoolProperty, bAIBroken, 0x80)
		ADD_VAR(::BoolProperty, bAIDrawDebug, 0x40)
		ADD_VAR(::BoolProperty, bMapBasedLogName, 0x20)
		ADD_VAR(::BoolProperty, bFlushAILogEachLine, 0x10)
		ADD_VAR(::BoolProperty, bAILogToWindow, 0x8)
		ADD_VAR(::BoolProperty, bAILogging, 0x4)
		ADD_VAR(::BoolProperty, bHasRunawayCommandList, 0x2)
		ADD_VAR(::BoolProperty, bUseAITree, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<AITreeHandle>, AITreeHandle, 0xFFFFFFFF)
		ADD_OBJECT(AITree, AITree)
		void AllCommands(ScriptClass* BaseClass, class GameAICommand*& Cmd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.AllCommands");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = BaseClass;
			*(class GameAICommand**)(params + 4) = Cmd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Cmd = *(class GameAICommand**)(params + 4);
			free(params);
		}
		void PushCommand(class GameAICommand* NewCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.PushCommand");
			byte* params = (byte*)malloc(4);
			*(class GameAICommand**)params = NewCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopCommand(class GameAICommand* ToBePoppedCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.PopCommand");
			byte* params = (byte*)malloc(4);
			*(class GameAICommand**)params = ToBePoppedCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AbortCommand(class GameAICommand* AbortCmd, ScriptClass* AbortClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.AbortCommand");
			byte* params = (byte*)malloc(12);
			*(class GameAICommand**)params = AbortCmd;
			*(ScriptClass**)(params + 4) = AbortClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		class GameAICommand* GetActiveCommand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetActiveCommand");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameAICommand**)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = SearchClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameAICommand**)(params + 4);
			free(params);
			return returnVal;
		}
		class GameAICommand* GetAICommandInStack(ScriptClass* InClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetAICommandInStack");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = InClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameAICommand**)(params + 4);
			free(params);
			return returnVal;
		}
		float GetDestinationOffset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetDestinationOffset");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
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
		void RecordDemoAILog(ScriptArray<wchar_t> LogText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.RecordDemoAILog");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = LogText;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AILog_Internal(ScriptArray<wchar_t> LogText, ScriptName LogCategory, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.AILog_Internal");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = LogText;
			*(ScriptName*)(params + 12) = LogCategory;
			*(bool*)(params + 20) = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDesiredRotation(Rotator TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.SetDesiredRotation");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = TargetDesiredRotation;
			*(bool*)(params + 12) = InLockDesiredRotation;
			*(bool*)(params + 16) = InUnlockWhenReached;
			*(float*)(params + 20) = InterpolationTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetActionString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAIController.GetActionString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
