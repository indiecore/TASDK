#pragma once
#include "Engine__CameraShake.h"
#include "Engine__PlayerController.h"
#include "GameFramework__GameCrowdAgent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GamePlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GamePlayerController : public PlayerController
	{
	public:
		ADD_VAR(::NameProperty, CurrentSoundMode, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AgentAwareRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsWarmupPaused, 0x4)
		ADD_VAR(::BoolProperty, bDebugCrowdAwareness, 0x2)
		ADD_VAR(::BoolProperty, bWarnCrowdMembers, 0x1)
		// Here lies the not-yet-implemented method 'GetUIPlayerIndex'
		// Here lies the not-yet-implemented method 'NotifyCrowdAgentRefresh'
		// Here lies the not-yet-implemented method 'NotifyCrowdAgentInRadius'
		// Here lies the not-yet-implemented method 'DoForceFeedbackForScreenShake'
		// Here lies the not-yet-implemented method 'SetSoundMode'
		// Here lies the not-yet-implemented method 'ShowLoadingMovie'
		// Here lies the not-yet-implemented method 'KeepPlayingLoadingMovie'
		// Here lies the not-yet-implemented method 'ClientPlayMovie'
		// Here lies the not-yet-implemented method 'ClientStopMovie'
		// Here lies the not-yet-implemented method 'GetCurrentMovie'
		// Here lies the not-yet-implemented method 'CanUnpauseWarmup'
		// Here lies the not-yet-implemented method 'WarmupPause'
		// Here lies the not-yet-implemented method 'DoMemLeakChecking'
		// Here lies the not-yet-implemented method 'StopMemLeakChecking'
		// Here lies the not-yet-implemented method 'CallMemLeakCheck'
		// Here lies the not-yet-implemented method 'ClientColorFade'
	};
}
#undef ADD_VAR
