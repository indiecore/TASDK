#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerController : public Controller
	{
	public:
			ADD_VAR( ::FloatProperty, LODDistanceFactor, 0xFFFFFFFF )
			ADD_OBJECT( Player, Player )
			ADD_OBJECT( Actor, ViewTarget )
			ADD_OBJECT( Camera, PlayerCamera )
			ADD_VAR( ::BoolProperty, bIsExternalUIOpen, 0x400000 )
			ADD_VAR( ::BoolProperty, bPendingDestroy, 0x200 )
			ADD_VAR( ::BoolProperty, bIsControllerConnected, 0x800000 )
			ADD_OBJECT( CoverReplicator, MyCoverReplicator )
			ADD_VAR( ::FloatProperty, MaxTimeMargin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxResponseTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastActiveTime, 0xFFFFFFFF )
			ADD_OBJECT( OnlineSubsystem, OnlineSub )
			ADD_OBJECT( OnlineGameSearch, MigratedSearchToJoin )
			ADD_VAR( ::FloatProperty, TimeMargin, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShortConnectTimeOut, 0x100 )
			ADD_OBJECT( HUD, myHUD )
			ADD_VAR( ::FloatProperty, WaitDelay, 0xFFFFFFFF )
			ADD_OBJECT( SavedMove, SavedMoves )
			ADD_OBJECT( SavedMove, PendingMove )
			ADD_OBJECT( PlayerInput, PlayerInput )
			ADD_VAR( ::StrProperty, ForceFeedbackManagerClassName, 0xFFFFFFFF )
			ADD_OBJECT( ForceFeedbackManager, ForceFeedbackManager )
			ADD_OBJECT( UIDataStore_OnlinePlayerData, OnlinePlayerData )
			ADD_VAR( ::BoolProperty, bFrozen, 0x1 )
			ADD_OBJECT( Pawn, AcknowledgedPawn )
			ADD_VAR( ::FloatProperty, FOVAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultFOV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DesiredFOV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastBroadcastTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, LastBroadcastString, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWasSpeedHack, 0x400 )
			ADD_VAR( ::FloatProperty, LastSpeedHackLog, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ServerTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDoubleJump, 0x4 )
			ADD_VAR( ::IntProperty, ClientCap, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPingUpdate, 0xFFFFFFFF )
			ADD_OBJECT( SavedMove, FreeMoves )
			ADD_STRUCT( ::VectorProperty, LastAckedAccel, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUpdatePosition, 0x8 )
			ADD_VAR( ::ByteProperty, bRun, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bDuck, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPressedJump, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdating, 0x10 )
			ADD_VAR( ::FloatProperty, ClientUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCinematicMode, 0x10000 )
			ADD_VAR( ::FloatProperty, InteractDistance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAimingHelp, 0x1000 )
			ADD_VAR( ::BoolProperty, bClientSimulatingViewTarget, 0x2000 )
			ADD_VAR( ::ByteProperty, DoubleClickDir, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GroundPitch, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCheatFlying, 0x40 )
			ADD_VAR( ::FloatProperty, LastSpectatorStateSynchTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpectatorCameraSpeed, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, RealViewTarget )
			ADD_VAR( ::FloatProperty, MinRespawnDelay, 0xFFFFFFFF )
			ADD_OBJECT( NetConnection, PendingSwapConnection )
			ADD_VAR( ::ByteProperty, bIgnoreMoveInput, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bIgnoreLookInput, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCinemaDisableInputMove, 0x20000 )
			ADD_VAR( ::BoolProperty, bCinemaDisableInputLook, 0x40000 )
			ADD_VAR( ::BoolProperty, bHasVoiceHandshakeCompleted, 0x8000 )
			ADD_VAR( ::ByteProperty, NetPlayerIndex, 0xFFFFFFFF )
			ADD_OBJECT( CheatManager, CheatManager )
			ADD_VAR( ::BoolProperty, bNeverSwitchOnPickup, 0x20 )
			ADD_VAR( ::BoolProperty, bCameraPositionLocked, 0x80 )
			ADD_VAR( ::BoolProperty, bWasSaturated, 0x800 )
			ADD_VAR( ::BoolProperty, bPreventRespawn, 0x4000 )
			ADD_VAR( ::BoolProperty, bIgnoreNetworkMessages, 0x80000 )
			ADD_VAR( ::BoolProperty, bReplicateAllPawns, 0x100000 )
			ADD_VAR( ::BoolProperty, bIsUsingStreamingVolumes, 0x200000 )
			ADD_VAR( ::BoolProperty, bCheckSoundOcclusion, 0x1000000 )
			ADD_VAR( ::BoolProperty, bDebugCameraAnims, 0x2000000 )
			ADD_VAR( ::BoolProperty, bBlockCameraAnimsFromOverridingPostProcess, 0x4000000 )
			ADD_VAR( ::BoolProperty, bLogHearSoundOverflow, 0x8000000 )
			ADD_VAR( ::BoolProperty, bCheckRelevancyThroughPortals, 0x10000000 )
			ADD_VAR( ::BoolProperty, bDebugClientAdjustPosition, 0x20000000 )
			ADD_OBJECT( InterpTrackInstDirector, ControllingDirTrackInst )
			ADD_STRUCT( ::RotatorProperty, TargetViewRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetEyeHeight, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, BlendedTargetViewRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DynamicPingThreshold, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FailedPathStart, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DelayedJoinSessionName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxConcurrentHearSounds, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
