#pragma once
#include "GameFramework.GameCrowdAgent.h"
#include "Core.Object.h"
#include "Engine.AnimTree.h"
#include "Engine.LightComponent.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.AnimNodeSlot.h"
#include "Engine.AnimNodeBlend.h"
#include "GameFramework.SeqAct_PlayAgentAnimation.h"
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
	class GameCrowdAgentSkeletal : public GameCrowdAgent
	{
	public:
		class GameCrowdAttachmentInfo
		{
		public:
			ADD_STRUCT(Object::Vector, Scale3D, 8)
			ADD_STRUCT(float, Chance, 4)
			ADD_OBJECT(StaticMesh, StaticMesh, 0)
		};
		class GameCrowdAttachmentList
		{
		public:
			ADD_STRUCT(ScriptArray<GameCrowdAgentSkeletal::GameCrowdAttachmentInfo>, List, 8)
			ADD_STRUCT(ScriptName, SocketName, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptName>, WalkAnimNames, 992)
		ADD_STRUCT(ScriptArray<ScriptName>, RunAnimNames, 1004)
		ADD_STRUCT(ScriptArray<ScriptName>, IdleAnimNames, 1016)
		ADD_STRUCT(ScriptArray<ScriptName>, DeathAnimNames, 1028)
		ADD_STRUCT(ScriptArray<GameCrowdAgentSkeletal::GameCrowdAttachmentList>, Attachments, 1064)
		ADD_STRUCT(float, MaxAnimationDistanceSq, 1088)
		ADD_STRUCT(float, MaxAnimationDistance, 1084)
		ADD_BOOL(bAnimateThisTick, 1080, 0x8)
		ADD_BOOL(bIsPlayingDeathAnimation, 1080, 0x4)
		ADD_BOOL(bIsPlayingIdleAnimation, 1080, 0x2)
		ADD_BOOL(bUseRootMotionVelocity, 1080, 0x1)
		ADD_STRUCT(float, MaxTargetAcquireTime, 1076)
		ADD_STRUCT(ScriptName, MoveSyncGroupName, 1056)
		ADD_STRUCT(float, MaxSpeedBlendChangeSpeed, 1052)
		ADD_STRUCT(float, AnimVelRate, 1048)
		ADD_STRUCT(float, SpeedBlendEnd, 1044)
		ADD_STRUCT(float, SpeedBlendStart, 1040)
		ADD_OBJECT(AnimTree, AgentTree, 988)
		ADD_OBJECT(AnimNodeSequence, RunSeqNode, 984)
		ADD_OBJECT(AnimNodeSequence, WalkSeqNode, 980)
		ADD_OBJECT(AnimNodeSequence, ActionSeqNode, 976)
		ADD_OBJECT(AnimNodeSlot, FullBodySlot, 972)
		ADD_OBJECT(AnimNodeBlend, SpeedBlendNode, 968)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLighting(bool bEnableLightEnvironment, LightComponent::LightingChannelContainer AgentLightingChannel, bool bCastShadows)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.SetLighting");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bEnableLightEnvironment;
			*(LightComponent::LightingChannelContainer*)&params[4] = AgentLightingChannel;
			*(bool*)&params[8] = bCastShadows;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDeath(Object::Vector KillMomentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.PlayDeath");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = KillMomentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRootMotion(bool bRootMotionEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.SetRootMotion");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bRootMotionEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayAgentAnimation(class SeqAct_PlayAgentAnimation* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.OnPlayAgentAnimation");
			byte params[4] = { NULL };
			*(class SeqAct_PlayAgentAnimation**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateAttachments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentSkeletal.CreateAttachments");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
