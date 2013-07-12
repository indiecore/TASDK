#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTGame." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTGame." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTGame." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGame : public UDKGame
	{
	public:
			ADD_OBJECT( UTVehicle, VehicleList )
			ADD_VAR( ::IntProperty, ResetTimeDelay, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWarmupRound, 0x1000 )
			ADD_VAR( ::IntProperty, WarmupTime, 0xFFFFFFFF )
			ADD_OBJECT( GameplayEventsWriter, GameplayEventsWriter )
			ADD_VAR( ::StrProperty, GameplayEventsWriterClassName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, MidgameScorePanelTag, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, Sniper )
			ADD_VAR( ::FloatProperty, LastManDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastEncouragementTime, 0xFFFFFFFF )
			ADD_OBJECT( SpeechRecognition, SpeechRecognitionData )
			ADD_VAR( ::StrProperty, EndOfMatchRulesTemplateStr_Time, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EndOfMatchRulesTemplateStr_ScoringSingle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EndOfMatchRulesTemplateStr_Scoring, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, ScriptedStartSpot )
			ADD_VAR( ::IntProperty, MapCycleIndex, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DemoPrefix, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyRosterName, 0xFFFFFFFF )
			ADD_OBJECT( UTTeamInfo, EnemyRoster )
			ADD_VAR( ::IntProperty, ResetCountDown, 0xFFFFFFFF )
			ADD_OBJECT( Actor, EndGameFocus )
			ADD_VAR( ::StrProperty, GameUMenuType, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesMenuType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EndMessageCounter, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EndMessageWait, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndTime, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, LastStartSpot )
			ADD_OBJECT( NavigationPoint, LastPlayerStartSpot )
			ADD_VAR( ::IntProperty, PlayerDeaths, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerKills, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustedDifficulty, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CountDown, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PendingMatchElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LateEntryLives, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DefaultMaxLives, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnProtectionTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DesiredPlayerCount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, WeaponTauntUsed, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, StartupStage, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, WarmupRemaining, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RestartWait, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinNetPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ClientProcessingTimeout, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NetWait, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BotRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndTimeDelay, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ServerSkillLevel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Description, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Acronym, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGivePhysicsGun, 0x40 )
			ADD_VAR( ::BoolProperty, bLogGameplayEvents, 0x20 )
			ADD_VAR( ::BoolProperty, bUseClassicHUD, 0x10 )
			ADD_VAR( ::BoolProperty, bIgnoreTeamForVoiceChat, 0x8 )
			ADD_VAR( ::BoolProperty, bNecrisLocked, 0x4 )
			ADD_VAR( ::BoolProperty, bForceMidGameMenuAtStart, 0x2 )
			ADD_VAR( ::BoolProperty, bMidGameHasMap, 0x1 )
			ADD_VAR( ::BoolProperty, bPlayedOneKill, 0x80000000 )
			ADD_VAR( ::BoolProperty, bPlayedFiveKills, 0x40000000 )
			ADD_VAR( ::BoolProperty, bPlayedTenKills, 0x20000000 )
			ADD_VAR( ::BoolProperty, bScoreDeaths, 0x10000000 )
			ADD_VAR( ::BoolProperty, bAllowKeyboardAndMouse, 0x8000000 )
			ADD_VAR( ::BoolProperty, bConsoleServer, 0x4000000 )
			ADD_VAR( ::BoolProperty, bAllowHoverboard, 0x2000000 )
			ADD_VAR( ::BoolProperty, bStartWithLockerWeaps, 0x1000000 )
			ADD_VAR( ::BoolProperty, bUndrivenVehicleDamage, 0x800000 )
			ADD_VAR( ::BoolProperty, bDemoMode, 0x400000 )
			ADD_VAR( ::BoolProperty, bMustJoinBeforeStart, 0x200000 )
			ADD_VAR( ::BoolProperty, bPlayerBecameActive, 0x100000 )
			ADD_VAR( ::BoolProperty, bMustHaveMultiplePlayers, 0x80000 )
			ADD_VAR( ::BoolProperty, bOverTimeBroadcast, 0x40000 )
			ADD_VAR( ::BoolProperty, bFinalStartup, 0x20000 )
			ADD_VAR( ::BoolProperty, bStartedCountDown, 0x10000 )
			ADD_VAR( ::BoolProperty, bSkipPlaySound, 0x8000 )
			ADD_VAR( ::BoolProperty, bQuickStart, 0x4000 )
			ADD_VAR( ::BoolProperty, bFirstBlood, 0x2000 )
			ADD_VAR( ::BoolProperty, bShouldWaitForNetPlayers, 0x800 )
			ADD_VAR( ::BoolProperty, bWaitForNetPlayers, 0x400 )
			ADD_VAR( ::BoolProperty, bTempForceRespawn, 0x200 )
			ADD_VAR( ::BoolProperty, bForceRespawn, 0x100 )
			ADD_VAR( ::BoolProperty, bPlayersMustBeReady, 0x80 )
			ADD_VAR( ::BoolProperty, bAutoNumBots, 0x40 )
			ADD_VAR( ::BoolProperty, bCustomBots, 0x20 )
			ADD_VAR( ::BoolProperty, bPlayersVsBots, 0x10 )
			ADD_VAR( ::BoolProperty, bSoaking, 0x8 )
			ADD_VAR( ::BoolProperty, bTeamScoreRounds, 0x4 )
			ADD_VAR( ::BoolProperty, bWeaponStay, 0x2 )
			ADD_VAR( ::BoolProperty, bExportMenuData, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
