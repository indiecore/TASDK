#pragma once
#include "Engine__Actor.h"
#include "GameFramework__GameCrowdAgentBehavior.h"
#include "GameFramework__SeqAct_PlayAgentAnimation.h"
#include "GameFramework__GameCrowdAgent.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdBehavior_PlayAnimation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdBehavior_PlayAnimation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdBehavior_PlayAnimation : public GameCrowdAgentBehavior
	{
	public:
		ADD_VAR(::IntProperty, AnimationIndex, 0xFFFFFFFF)
		ADD_OBJECT(SeqAct_PlayAgentAnimation, AnimSequence)
		ADD_VAR(::FloatProperty, LoopTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LoopIndex, 0xFFFFFFFF)
		ADD_OBJECT(Actor, CustomActionTarget)
		ADD_VAR(::BoolProperty, bBlendBetweenAnims, 0x8)
		ADD_VAR(::BoolProperty, bLooping, 0x4)
		ADD_VAR(::BoolProperty, bLookAtPlayer, 0x2)
		ADD_VAR(::BoolProperty, bUseRootMotion, 0x1)
		ADD_VAR(::FloatProperty, BlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.InitBehavior");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		ScriptArray<wchar_t> GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_PlayAnimation.GetBehaviorString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
