#pragma once
#include "Engine.GameReplicationInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGameReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTGameReplicationInfo : public GameReplicationInfo
	{
	public:
		ADD_VAR(::BoolProperty, bStoryMode, 0x4)
		ADD_VAR(::BoolProperty, bAnnouncementsDisabled, 0x20)
		ADD_VAR(::StrProperty, MessageOfTheDay, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bConsoleServer, 0x8)
		ADD_VAR(::BoolProperty, bAllowKeyboardAndMouse, 0x10)
		ADD_VAR(::IntProperty, BotDifficulty, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinNetPlayers, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRequireReady, 0x40)
		ADD_VAR(::StrProperty, MutatorList, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesString, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWarmupRound, 0x1)
		ADD_VAR(::ByteProperty, FlagState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBerserk, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceDefaultCharacter, 0x2)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool InOrder(class PlayerReplicationInfo* P1, class PlayerReplicationInfo* P2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.InOrder");
			byte* params = (byte*)malloc(12);
			*(class PlayerReplicationInfo**)params = P1;
			*(class PlayerReplicationInfo**)(params + 4) = P2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SortPRIArray()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.SortPRIArray");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CharacterProcessingComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.CharacterProcessingComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFlagHome(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.SetFlagHome");
			byte* params = (byte*)malloc(4);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool FlagIsHome(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.FlagIsHome");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FlagsAreHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.FlagsAreHome");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetFlagHeldFriendly(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.SetFlagHeldFriendly");
			byte* params = (byte*)malloc(4);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool FlagIsHeldFriendly(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.FlagIsHeldFriendly");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetFlagHeldEnemy(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.SetFlagHeldEnemy");
			byte* params = (byte*)malloc(4);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool FlagIsHeldEnemy(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.FlagIsHeldEnemy");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetFlagDown(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.SetFlagDown");
			byte* params = (byte*)malloc(4);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool FlagIsDown(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.FlagIsDown");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowMidGameMenu(class UTPlayerController* InstigatorPC, ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.ShowMidGameMenu");
			byte* params = (byte*)malloc(16);
			*(class UTPlayerController**)params = InstigatorPC;
			*(ScriptName*)(params + 4) = TabTag;
			*(bool*)(params + 12) = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHudShowScores(bool bShow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.SetHudShowScores");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddGameRule(ScriptArray<wchar_t> Rule)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameReplicationInfo.AddGameRule");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Rule;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
