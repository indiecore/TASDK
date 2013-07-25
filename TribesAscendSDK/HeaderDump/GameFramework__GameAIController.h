#pragma once
#include "Engine__AIController.h"
#include "Engine__FileLog.h"
#include "GameFramework__GameAICommand.h"
#include "Engine__AITree.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle' for the property named 'AITreeHandle'!
		ADD_OBJECT(AITree, AITree)
		// Here lies the not-yet-implemented method 'AllCommands'
		// Here lies the not-yet-implemented method 'PushCommand'
		// Here lies the not-yet-implemented method 'PopCommand'
		// Here lies the not-yet-implemented method 'AbortCommand'
		// Here lies the not-yet-implemented method 'GetActiveCommand'
		// Here lies the not-yet-implemented method 'CheckCommandCount'
		// Here lies the not-yet-implemented method 'DumpCommandStack'
		// Here lies the not-yet-implemented method 'FindCommandOfClass'
		// Here lies the not-yet-implemented method 'GetAICommandInStack'
		// Here lies the not-yet-implemented method 'GetDestinationOffset'
		// Here lies the not-yet-implemented method 'ReachedMoveGoal'
		// Here lies the not-yet-implemented method 'ReachedIntermediateMoveGoal'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'RecordDemoAILog'
		// Here lies the not-yet-implemented method 'AILog_Internal'
		// Here lies the not-yet-implemented method 'SetDesiredRotation'
		// Here lies the not-yet-implemented method 'GetActionString'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
