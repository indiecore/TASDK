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
		// Here lies the not-yet-implemented method 'InitBehavior'
		// Here lies the not-yet-implemented method 'FinishedTargetRotation'
		// Here lies the not-yet-implemented method 'SetSequenceOutput'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'PlayAgentAnimationNow'
		// Here lies the not-yet-implemented method 'StopBehavior'
		// Here lies the not-yet-implemented method 'GetBehaviorString'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
