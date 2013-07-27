#pragma once
#include "UTGame.UTCarriedObject.h"
#include "Engine.TeamInfo.h"
#include "UTGame.UTCharInfo.h"
#include "UTGame.UTTeamAI.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Controller.h"
#include "UTGame.UTBot.h"
#include "Core.Object.h"
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
	class UTTeamInfo : public TeamInfo
	{
	public:
		ADD_STRUCT(ScriptString*, Faction, 520)
		ADD_OBJECT(UTCarriedObject, TeamFlag, 516)
		ADD_OBJECT(UTTeamAI, AI, 508)
		ADD_OBJECT(UTGameObjective, HomeBase, 512)
		ADD_STRUCT(ScriptString*, TeamColorNames, 548)
		ADD_STRUCT(Object::Color, BaseTeamColor, 532)
		ADD_STRUCT(int, DesiredTeamSize, 504)
		UTCharInfo::CharacterInfo GetBotInfo(ScriptString* BotName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetBotInfo");
			byte params[124] = { NULL };
			*(ScriptString**)&params[0] = BotName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTCharInfo::CharacterInfo*)&params[12];
		}
		bool AllBotsSpawned()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.AllBotsSpawned");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Color GetHUDColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetHUDColor");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[0];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialize(int NewTeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.Initialize");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewTeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NeedsBotMoreThan(class UTTeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.NeedsBotMoreThan");
			byte params[8] = { NULL };
			*(class UTTeamInfo**)&params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetBotOrders(class UTBot* NewBot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.SetBotOrders");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = NewBot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFromTeam(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.RemoveFromTeam");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BotNameTaken(ScriptString* BotName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.BotNameTaken");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = BotName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void GetAvailableBotList(ScriptArray<int>& AvailableBots, ScriptString* FactionFilter, bool bMalesOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetAvailableBotList");
			byte params[28] = { NULL };
			*(ScriptArray<int>*)&params[0] = AvailableBots;
			*(ScriptString**)&params[12] = FactionFilter;
			*(bool*)&params[24] = bMalesOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			AvailableBots = *(ScriptArray<int>*)&params[0];
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
