#pragma once
#include "UTGame.UTTeamHUD.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "UTGame.UTGameReplicationInfo.h"
#include "UTGame.UTCTFBase.h"
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
	class UTCTFHUD : public UTTeamHUD
	{
	public:
		ADD_STRUCT(UTGameReplicationInfo::EFlagState, FlagStates, 2748)
		ADD_OBJECT(UTCTFBase, FlagBases, 2740)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayTeamLogos(byte TeamIndex, Object::Vector2D pos, float DestScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.DisplayTeamLogos");
			byte params[13] = { NULL };
			params[0] = TeamIndex;
			*(Object::Vector2D*)&params[4] = pos;
			*(float*)&params[12] = DestScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetDirectionalDest(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFHUD.GetDirectionalDest");
			byte params[5] = { NULL };
			params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
