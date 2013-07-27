#pragma once
#include "UTGame.UTHUD.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class UTTeamHUD : public UTHUD
	{
	public:
		ADD_STRUCT(float, TeamScaleModifier, 2736)
		ADD_STRUCT(float, OldRightScore, 2732)
		ADD_STRUCT(float, OldLeftScore, 2728)
		ADD_STRUCT(float, RightTeamPulseTime, 2724)
		ADD_STRUCT(float, LeftTeamPulseTime, 2720)
		ADD_STRUCT(Object::Vector2D, TeamIconCenterPoints, 2704)
		ADD_STRUCT(int, ScoreTransitionTime, 2696)
		ADD_STRUCT(int, LastScores, 2688)
		ADD_BOOL(bShowDirectional, 2684, 0x1)
		void DisplayScoring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.DisplayScoring");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayTeamScore()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.DisplayTeamScore");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetTeamScore(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.GetTeamScore");
			byte params[5] = { NULL };
			params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class Actor* GetDirectionalDest(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.GetDirectionalDest");
			byte params[5] = { NULL };
			params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void DisplayTeamLogos(byte TeamIndex, Object::Vector2D pos, float DestScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.DisplayTeamLogos");
			byte params[13] = { NULL };
			params[0] = TeamIndex;
			*(Object::Vector2D*)&params[4] = pos;
			*(float*)&params[12] = DestScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDirectionIndicator(byte TeamIndex, Object::Vector2D pos, class Actor* destActor, float DestScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.DisplayDirectionIndicator");
			byte params[17] = { NULL };
			params[0] = TeamIndex;
			*(Object::Vector2D*)&params[4] = pos;
			*(class Actor**)&params[12] = destActor;
			*(float*)&params[16] = DestScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
