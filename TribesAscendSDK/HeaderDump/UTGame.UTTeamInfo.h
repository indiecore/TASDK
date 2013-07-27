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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44823);
			byte params[124] = { NULL };
			*(ScriptString**)params = BotName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTCharInfo::CharacterInfo*)&params[12];
		}
		bool AllBotsSpawned()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45171);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Object::Color GetHUDColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45835);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)params;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47144);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47147);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47149);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialize(int NewTeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47150);
			byte params[4] = { NULL };
			*(int*)params = NewTeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NeedsBotMoreThan(class UTTeamInfo* T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47152);
			byte params[8] = { NULL };
			*(class UTTeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetBotOrders(class UTBot* NewBot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47155);
			byte params[4] = { NULL };
			*(class UTBot**)params = NewBot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFromTeam(class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47157);
			byte params[4] = { NULL };
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BotNameTaken(ScriptString* BotName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47159);
			byte params[16] = { NULL };
			*(ScriptString**)params = BotName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void GetAvailableBotList(ScriptArray<int>& AvailableBots, ScriptString* FactionFilter, bool bMalesOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47165);
			byte params[28] = { NULL };
			*(ScriptArray<int>*)params = AvailableBots;
			*(ScriptString**)&params[12] = FactionFilter;
			*(bool*)&params[24] = bMalesOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			AvailableBots = *(ScriptArray<int>*)params;
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47176);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
