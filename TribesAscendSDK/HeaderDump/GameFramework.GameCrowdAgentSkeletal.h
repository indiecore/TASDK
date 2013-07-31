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
		struct GameCrowdAttachmentInfo
		{
		public:
			ADD_STRUCT(Vector, Scale3D, 8)
			ADD_STRUCT(float, Chance, 4)
			ADD_OBJECT(StaticMesh, StaticMesh, 0)
		};
		struct GameCrowdAttachmentList
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31167);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLighting(bool bEnableLightEnvironment, LightComponent::LightingChannelContainer AgentLightingChannel, bool bCastShadows)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31168);
			byte params[12] = { NULL };
			*(bool*)params = bEnableLightEnvironment;
			*(LightComponent::LightingChannelContainer*)&params[4] = AgentLightingChannel;
			*(bool*)&params[8] = bCastShadows;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDeath(Vector KillMomentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31172);
			byte params[12] = { NULL };
			*(Vector*)params = KillMomentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRootMotion(bool bRootMotionEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31174);
			byte params[4] = { NULL };
			*(bool*)params = bRootMotionEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayAgentAnimation(class SeqAct_PlayAgentAnimation* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31176);
			byte params[4] = { NULL };
			*(class SeqAct_PlayAgentAnimation**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLatentAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31178);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayIdleAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31179);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopIdleAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31180);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31181);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateAttachments()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31185);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
