#pragma once
#include "UTGame.UTHUD.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTeamHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTTeamHUD : public UTHUD
	{
	public:
		ADD_VAR(::FloatProperty, TeamScaleModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldRightScore, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldLeftScore, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RightTeamPulseTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftTeamPulseTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, TeamIconCenterPoints, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ScoreTransitionTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastScores, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowDirectional, 0x1)
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
			byte* params = (byte*)malloc(5);
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		class Actor* GetDirectionalDest(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.GetDirectionalDest");
			byte* params = (byte*)malloc(5);
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		void DisplayTeamLogos(byte TeamIndex, Vector2D pos, float DestScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.DisplayTeamLogos");
			byte* params = (byte*)malloc(13);
			*params = TeamIndex;
			*(Vector2D*)(params + 4) = pos;
			*(float*)(params + 12) = DestScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDirectionIndicator(byte TeamIndex, Vector2D pos, class Actor* destActor, float DestScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamHUD.DisplayDirectionIndicator");
			byte* params = (byte*)malloc(17);
			*params = TeamIndex;
			*(Vector2D*)(params + 4) = pos;
			*(class Actor**)(params + 12) = destActor;
			*(float*)(params + 16) = DestScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
