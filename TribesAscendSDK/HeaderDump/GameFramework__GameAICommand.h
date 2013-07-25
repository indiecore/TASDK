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
		// Here lies the not-yet-implemented method 'InitCommandUserActor'
		// Here lies the not-yet-implemented method 'InitCommand'
		// Here lies the not-yet-implemented method 'InternalPrePushed'
		// Here lies the not-yet-implemented method 'InternalPushed'
		// Here lies the not-yet-implemented method 'InternalPopped'
		// Here lies the not-yet-implemented method 'InternalPaused'
		// Here lies the not-yet-implemented method 'InternalResumed'
		// Here lies the not-yet-implemented method 'InternalTick'
		// Here lies the not-yet-implemented method 'ShouldIgnoreNotifies'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'AllowTransitionTo'
		// Here lies the not-yet-implemented method 'AllowStateTransitionTo'
		// Here lies the not-yet-implemented method 'PrePushed'
		// Here lies the not-yet-implemented method 'PostPopped'
		// Here lies the not-yet-implemented method 'Pushed'
		// Here lies the not-yet-implemented method 'Popped'
		// Here lies the not-yet-implemented method 'Paused'
		// Here lies the not-yet-implemented method 'Resumed'
		// Here lies the not-yet-implemented method 'GetDumpString'
		// Here lies the not-yet-implemented method 'DrawDebug'
		// Here lies the not-yet-implemented method 'GetDebugOverheadText'
		// Here lies the not-yet-implemented method 'GetDebugVerboseText'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
