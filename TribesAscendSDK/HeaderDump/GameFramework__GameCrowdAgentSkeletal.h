#pragma once
#include "GameFramework__GameCrowdAgent.h"
#include "Engine__AnimTree.h"
#include "Engine__AnimNodeSequence.h"
#include "GameFramework__SeqAct_PlayAgentAnimation.h"
#include "Engine__AnimNodeBlend.h"
#include "Engine__AnimNodeSlot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdAgentSkeletal." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdAgentSkeletal." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdAgentSkeletal : public GameCrowdAgent
	{
	public:
		ADD_VAR(::FloatProperty, MaxAnimationDistanceSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxAnimationDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAnimateThisTick, 0x8)
		ADD_VAR(::BoolProperty, bIsPlayingDeathAnimation, 0x4)
		ADD_VAR(::BoolProperty, bIsPlayingIdleAnimation, 0x2)
		ADD_VAR(::BoolProperty, bUseRootMotionVelocity, 0x1)
		ADD_VAR(::FloatProperty, MaxTargetAcquireTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, MoveSyncGroupName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSpeedBlendChangeSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimVelRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpeedBlendEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpeedBlendStart, 0xFFFFFFFF)
		ADD_OBJECT(AnimTree, AgentTree)
		ADD_OBJECT(AnimNodeSequence, RunSeqNode)
		ADD_OBJECT(AnimNodeSequence, WalkSeqNode)
		ADD_OBJECT(AnimNodeSequence, ActionSeqNode)
		ADD_OBJECT(AnimNodeSlot, FullBodySlot)
		ADD_OBJECT(AnimNodeBlend, SpeedBlendNode)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetLighting'
		// Here lies the not-yet-implemented method 'PlayDeath'
		// Here lies the not-yet-implemented method 'SetRootMotion'
		// Here lies the not-yet-implemented method 'OnPlayAgentAnimation'
		// Here lies the not-yet-implemented method 'ClearLatentAnimation'
		// Here lies the not-yet-implemented method 'PlayIdleAnimation'
		// Here lies the not-yet-implemented method 'StopIdleAnimation'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'CreateAttachments'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
