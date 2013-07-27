#pragma once
#include "GameFramework.GameCrowdAgentBehavior.h"
#include "GameFramework.SeqAct_PlayAgentAnimation.h"
#include "Engine.Actor.h"
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.AnimNodeSequence.h"
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
	class GameCrowdBehavior_PlayAnimation : public GameCrowdAgentBehavior
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, AnimationList, 84)
		ADD_STRUCT(int, AnimationIndex, 124)
		ADD_OBJECT(SeqAct_PlayAgentAnimation, AnimSequence, 120)
		ADD_STRUCT(float, LoopTime, 116)
		ADD_STRUCT(int, LoopIndex, 112)
		ADD_OBJECT(Actor, CustomActionTarget, 108)
		ADD_BOOL(bBlendBetweenAnims, 104, 0x8)
		ADD_BOOL(bLooping, 104, 0x4)
		ADD_BOOL(bLookAtPlayer, 104, 0x2)
		ADD_BOOL(bUseRootMotion, 104, 0x1)
		ADD_STRUCT(float, BlendOutTime, 100)
		ADD_STRUCT(float, BlendInTime, 96)
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.InitBehavior");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishedTargetRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.FinishedTargetRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSequenceOutput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.SetSequenceOutput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.OnAnimEnd");
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAgentAnimationNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.PlayAgentAnimationNow");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.GetBehaviorString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
