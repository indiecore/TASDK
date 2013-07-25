#pragma once
#include "Engine__GameReplicationInfo.h"
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
	};
}
#undef ADD_VAR
