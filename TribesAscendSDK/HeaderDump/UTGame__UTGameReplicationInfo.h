#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__GameReplicationInfo.h"
#include "UTGame__UTPlayerController.h"
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
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'InOrder'
		// Here lies the not-yet-implemented method 'SortPRIArray'
		// Here lies the not-yet-implemented method 'CharacterProcessingComplete'
		// Here lies the not-yet-implemented method 'SetFlagHome'
		// Here lies the not-yet-implemented method 'FlagIsHome'
		// Here lies the not-yet-implemented method 'FlagsAreHome'
		// Here lies the not-yet-implemented method 'SetFlagHeldFriendly'
		// Here lies the not-yet-implemented method 'FlagIsHeldFriendly'
		// Here lies the not-yet-implemented method 'SetFlagHeldEnemy'
		// Here lies the not-yet-implemented method 'FlagIsHeldEnemy'
		// Here lies the not-yet-implemented method 'SetFlagDown'
		// Here lies the not-yet-implemented method 'FlagIsDown'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'ShowMidGameMenu'
		// Here lies the not-yet-implemented method 'SetHudShowScores'
		// Here lies the not-yet-implemented method 'AddGameRule'
	};
}
#undef ADD_VAR
