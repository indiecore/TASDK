#pragma once
#include "UTGame.UTCarriedObject.h"
#include "Engine.TeamInfo.h"
#include "UTGame.UTTeamAI.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Controller.h"
#include "UTGame.UTBot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamInfo : public TeamInfo
	{
	public:
		ADD_VAR(::StrProperty, Faction, 0xFFFFFFFF)
		ADD_OBJECT(UTCarriedObject, TeamFlag)
		ADD_OBJECT(UTTeamAI, AI)
		ADD_OBJECT(UTGameObjective, HomeBase)
		ADD_VAR(::StrProperty, TeamColorNames, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BaseTeamColor'!
		ADD_VAR(::IntProperty, DesiredTeamSize, 0xFFFFFFFF)
		
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void* GetBotInfo(ScriptArray<wchar_t> BotName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetBotInfo");
			byte* params = (byte*)malloc(124);
			*(ScriptArray<wchar_t>*)params = BotName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		bool AllBotsSpawned()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.AllBotsSpawned");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* GetHUDColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetHUDColor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params;
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialize(int NewTeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.Initialize");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewTeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NeedsBotMoreThan(class UTTeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.NeedsBotMoreThan");
			byte* params = (byte*)malloc(8);
			*(class UTTeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetBotOrders(class UTBot* NewBot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.SetBotOrders");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = NewBot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveFromTeam(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.RemoveFromTeam");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool BotNameTaken(ScriptArray<wchar_t> BotName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.BotNameTaken");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = BotName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void GetAvailableBotList(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& AvailableBots, ScriptArray<wchar_t> FactionFilter, bool bMalesOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.GetAvailableBotList");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = AvailableBots;
			*(ScriptArray<wchar_t>*)(params + 12) = FactionFilter;
			*(bool*)(params + 24) = bMalesOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			AvailableBots = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamInfo.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
