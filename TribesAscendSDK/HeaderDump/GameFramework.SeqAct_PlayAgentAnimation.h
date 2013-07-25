#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
#include "GameFramework.GameCrowdAgentSkeletal.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqAct_PlayAgentAnimation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqAct_PlayAgentAnimation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_PlayAgentAnimation : public SeqAct_Latent
	{
	public:
		ADD_OBJECT(Actor, ActionTarget)
		ADD_VAR(::FloatProperty, LoopTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LoopIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBlendBetweenAnims, 0x8)
		ADD_VAR(::BoolProperty, bLooping, 0x4)
		ADD_VAR(::BoolProperty, bFaceActionTargetFirst, 0x2)
		ADD_VAR(::BoolProperty, bUseRootMotion, 0x1)
		ADD_VAR(::FloatProperty, BlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_PlayAgentAnimation.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SetCurrentAnimationActionFor(class GameCrowdAgentSkeletal* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_PlayAgentAnimation.SetCurrentAnimationActionFor");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgentSkeletal**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
