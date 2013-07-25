#pragma once
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.AnimTree.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.AnimNodeSlot.h"
#include "Engine.AnimNodeBlend.h"
#include "GameFramework.SeqAct_PlayAgentAnimation.h"
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
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLighting(bool bEnableLightEnvironment, 
// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer'!
void* AgentLightingChannel, bool bCastShadows)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.SetLighting");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bEnableLightEnvironment;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer'!
void**)(params + 4) = AgentLightingChannel;
			*(bool*)(params + 8) = bCastShadows;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDeath(Vector KillMomentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.PlayDeath");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = KillMomentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRootMotion(bool bRootMotionEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.SetRootMotion");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bRootMotionEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayAgentAnimation(class SeqAct_PlayAgentAnimation* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.OnPlayAgentAnimation");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_PlayAgentAnimation**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLatentAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.ClearLatentAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayIdleAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.PlayIdleAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopIdleAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.StopIdleAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateAttachments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.CreateAttachments");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
