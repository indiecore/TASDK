#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
#include "GameFramework.GameCrowdAgentSkeletal.h"
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
	class SeqAct_PlayAgentAnimation : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, AnimationList, 248)
		ADD_OBJECT(Actor, ActionTarget, 280)
		ADD_STRUCT(float, LoopTime, 276)
		ADD_STRUCT(int, LoopIndex, 272)
		ADD_BOOL(bBlendBetweenAnims, 268, 0x8)
		ADD_BOOL(bLooping, 268, 0x4)
		ADD_BOOL(bFaceActionTargetFirst, 268, 0x2)
		ADD_BOOL(bUseRootMotion, 268, 0x1)
		ADD_STRUCT(float, BlendOutTime, 264)
		ADD_STRUCT(float, BlendInTime, 260)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_PlayAgentAnimation.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void SetCurrentAnimationActionFor(class GameCrowdAgentSkeletal* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_PlayAgentAnimation.SetCurrentAnimationActionFor");
			byte params[4] = { NULL };
			*(class GameCrowdAgentSkeletal**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
