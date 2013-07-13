#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameInfo : public Info
	{
	public:
			ADD_VAR( ::IntProperty, NumPlayers, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultPlayerName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxTimeMargin, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRequiresPushToTalk, 0x400000 )
			ADD_VAR( ::BoolProperty, bTeamGame, 0x4 )
			ADD_VAR( ::BoolProperty, bWaitingToStartMatch, 0x40 )
			ADD_VAR( ::IntProperty, ArbitratedLeaderboardId, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GameDifficulty, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TimeLimit, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CauseEventCommand, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasNetworkError, 0x200000 )
			ADD_VAR( ::BoolProperty, bRestartLevel, 0x1 )
			ADD_VAR( ::IntProperty, AdjustedNetSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxDynamicBandwidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GameSpeed, 0xFFFFFFFF )
			ADD_OBJECT( GameReplicationInfo, GameReplicationInfo )
			ADD_OBJECT( CoverReplicator, CoverReplicatorBase )
			ADD_VAR( ::StrProperty, GameName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGameEnded, 0x8 )
			ADD_VAR( ::BoolProperty, bOverTime, 0x10 )
			ADD_OBJECT( BroadcastHandler, BroadcastHandler )
			ADD_VAR( ::BoolProperty, bDoFearCostFallOff, 0x80000 )
			ADD_OBJECT( AccessControl, AccessControl )
			ADD_VAR( ::IntProperty, NumTravellingPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxPlayersAllowed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxSpectators, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxSpectatorsAllowed, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bFixedPlayerStart, 0x40000 )
			ADD_OBJECT( AutoTestManager, MyAutoTestManager )
			ADD_VAR( ::StrProperty, BugLocString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BugRotString, 0xFFFFFFFF )
			ADD_OBJECT( Mutator, BaseMutator )
			ADD_OBJECT( OnlineSubsystem, OnlineSub )
			ADD_VAR( ::BoolProperty, bUsingArbitration, 0x2000 )
			ADD_VAR( ::StrProperty, ServerOptions, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLevelChange, 0x800 )
			ADD_VAR( ::BoolProperty, bUseSeamlessTravel, 0x100000 )
			ADD_VAR( ::BoolProperty, bHasArbitratedHandshakeBegun, 0x4000 )
			ADD_VAR( ::IntProperty, NumSpectators, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDelayedStart, 0x20 )
			ADD_VAR( ::FloatProperty, LastNetSpeedUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TotalNetBandwidth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinDynamicBandwidth, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasEndGameHandshakeBegun, 0x20000 )
			ADD_VAR( ::BoolProperty, bIsEndGameHandshakeComplete, 0x10000 )
			ADD_VAR( ::BoolProperty, bGameRestarted, 0x400 )
			ADD_VAR( ::BoolProperty, bChangeLevels, 0x80 )
			ADD_VAR( ::BoolProperty, bAlreadyChanged, 0x100 )
			ADD_VAR( ::IntProperty, LeaderboardId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxLives, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPauseable, 0x2 )
			ADD_VAR( ::BoolProperty, bAdminCanPause, 0x200 )
			ADD_VAR( ::IntProperty, NumBots, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ArbitrationHandshakeTimeout, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNeedsEndGameHandshake, 0x8000 )
			ADD_VAR( ::BoolProperty, bKickLiveIdlers, 0x1000 )
			ADD_VAR( ::BoolProperty, bIsStandbyCheckingEnabled, 0x800000 )
			ADD_VAR( ::BoolProperty, bIsStandbyCheckingOn, 0x1000000 )
			ADD_VAR( ::BoolProperty, bHasStandbyCheatTriggered, 0x2000000 )
			ADD_VAR( ::IntProperty, GoreLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentID, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FearCostFallOff, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GoalScore, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxIdleTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeMarginSlack, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinTimeMargin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StandbyRxCheatTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StandbyTxCheatTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BadPingThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PercentMissingForRxStandby, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PercentMissingForTxStandby, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PercentForBadPing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, JoinInProgressStandbyWaitTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultGameType, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
