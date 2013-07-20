#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPlayerController : public UTPlayerController
	{
	public:
			ADD_VAR( ::BoolProperty, m_bShowHUDCracks, 0x100000 )
			int GetLanguageFontIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetLanguageFontIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool InTraining(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.InTraining" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrEquipInterface, m_TrEquipInterface )
			ScriptClass* GetFamilyInfoFromId( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetFamilyInfoFromId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bShowSpectatorHUD, 0x10000000 )
			ADD_VAR( ::BoolProperty, m_bShowSpectatorControls, 0x8000000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDVisor, 0x100 )
			ADD_VAR( ::BoolProperty, m_bShowHUDHealthBar, 0x80 )
			ADD_VAR( ::BoolProperty, m_bShowHUDHeroText, 0x2000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDKillbox, 0x800 )
			ADD_VAR( ::BoolProperty, m_bShowHUDCombatLog, 0x400 )
			ADD_VAR( ::BoolProperty, m_bShowHUDSkiBars, 0x10000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDCredits, 0x8 )
			ADD_VAR( ::BoolProperty, m_bShowHUDReticule, 0x4 )
			ADD_VAR( ::BoolProperty, m_bShowHUDChat, 0x200 )
			ADD_VAR( ::BoolProperty, m_bShowHUDPromptPanel, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDDeathcam, 0x1000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDRespawnTimer, 0x8000 )
			ADD_VAR( ::FloatProperty, r_fRespawnTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bIsRovingSpectating, 0x20000000 )
			ADD_VAR( ::BoolProperty, m_bViewThroughDeathCamera, 0x400000 )
			class TrDevice* GetDeviceByEquipPoint( byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetDeviceByEquipPoint" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrDevice** )( params + function->return_val_offset() );
			}

			byte GetZoomedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetZoomedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool InRovingSpectate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.InRovingSpectate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( AlienFXManager, AlienFX )
			ADD_VAR( ::BoolProperty, EnableAlienFX, 0x800000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDScores, 0x40 )
			ADD_VAR( ::IntProperty, m_nLastDamagerUpgradeLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLastDamagerHealthPercent, 0xFFFFFFFF )
			ADD_OBJECT( TrStrings, Strings )
			ADD_OBJECT( TrInventoryHelper, m_TrInventoryHelper )
			ADD_VAR( ::BoolProperty, m_bShowHUDBadges, 0x20 )
			ADD_VAR( ::BoolProperty, m_bShowHUDAccolades, 0x10 )
			bool IsTrPlayerMuted( ScriptArray< wchar_t > PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsTrPlayerMuted" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetActiveClassId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetActiveClassId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, r_bNeedTeam, 0x8000 )
			ADD_VAR( ::BoolProperty, r_bNeedLoadout, 0x10000 )
			ADD_VAR( ::BoolProperty, r_bDailyCompleted, 0x2000000 )
			int GetTeamClassCount( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetTeamClassCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, m_RequestedTeam, 0xFFFFFFFF )
			bool RegisterPendingClass( int ClassId, int Loadout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.RegisterPendingClass" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Loadout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetAllowedClassCount( byte ClassType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetAllowedClassCount" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = ClassType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool SendPrivateChatMessage( ScriptArray< wchar_t > PlayerName, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SendPrivateChatMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BroadcastChatMessage( byte Channel, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.BroadcastChatMessage" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = Channel;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bAutoRevertSetting, 0x2000000 )
			ADD_VAR( ::FloatProperty, m_fLastHitEnemyTime, 0xFFFFFFFF )
			bool ServerRequestPickTeam( byte RequestedTeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestPickTeam" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = RequestedTeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ChooseBloodEagle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ChooseBloodEagle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ChooseDiamondSword(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ChooseDiamondSword" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetVehicleCost( ScriptClass* VehicleClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetVehicleCost" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = VehicleClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetCurrentCredits(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetCurrentCredits" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrPlayerController, m_LastKilledBy )
			ADD_VAR( ::ByteProperty, r_nHitEnemyHeadshot, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bAllowSimulatedProjectiles, 0x400000 )
			ADD_VAR( ::BoolProperty, c_bPressingZoomButton, 0x200 )
			ADD_OBJECT( TrHelpTextManager, m_HelpTextManager )
			ADD_STRUCT( ::RotatorProperty, m_rCurrentKickbackDirection, 0xFFFFFFFF )
			ADD_OBJECT( MaterialEffect, m_ZoomedEffect )
			bool IsBassBoostToggled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsBassBoostToggled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowHelpTextToDisplay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AllowHelpTextToDisplay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedToVisitInventoryStation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.NeedToVisitInventoryStation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_OBJECT( TrAccoladeManager, m_AccoladeManager )
			ADD_STRUCT( ::VectorProperty, m_vDeathCamOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeathCameraCurrentScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeathCameraInnerScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeathCameraInterpSpeed, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_OldPossessedFamilyInfo )
			ADD_VAR( ::IntProperty, m_BeginPlayedTime, 0xFFFFFFFF )
			float GetCurrentDetermination(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetCurrentDetermination" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bPressingJetpack, 0x4 )
			ADD_OBJECT( Actor, m_LastDamagedBy )
			float GetNewPlayerAssistToApply(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetNewPlayerAssistToApply" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, FriendlyFireDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastFlagGrabTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bShowHUDFriendColoring, 0x20000 )
			ADD_VAR( ::BoolProperty, m_bEjectedFromVehicle, 0x10000000 )
			ADD_VAR( ::BoolProperty, m_bLastDeathWasUserSuicide, 0x200000 )
			ADD_VAR( ::IntProperty, FriendlyFireKills, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_ZoomState, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFreeCamYawOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFreeCamPitchOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCallInCooldown, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nCallinCooldownFlash, 0xFFFFFFFF )
			void PlayReliableSound( class SoundCue* InSoundCue, bool bNotReplicated, bool bNoRepToOwner, bool bStopWhenOwnerDestroyed, Vector SoundLocation, bool bNoRepToRelevant )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayReliableSound" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class SoundCue** )params = InSoundCue;
				*( bool* )( params + 4 ) = bNotReplicated;
				*( bool* )( params + 8 ) = bNoRepToOwner;
				*( bool* )( params + 12 ) = bStopWhenOwnerDestroyed;
				*( Vector* )( params + 16 ) = SoundLocation;
				*( bool* )( params + 28 ) = bNoRepToRelevant;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( TrChatConsoleCommands, m_PlayerCommands )
			ADD_VAR( ::FloatProperty, fSniperRespawnDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSuicideTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VGSClassId, 0xFFFFFFFF )
			ADD_OBJECT( TrContentLoader, c_ContentLoader )
			ADD_VAR( ::IntProperty, m_WhisperFilter, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, r_rViewTargetViewRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_vViewTargetViewLocation, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, r_ViewTargetVehiclePassengerPRI )
			ADD_OBJECT( PlayerReplicationInfo, r_ViewTargetVehicleDriverPRI )
			ADD_VAR( ::FloatProperty, r_fViewTargetVehicleMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetVehicleCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetPackAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetOffhandAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetSecondaryMaxAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetPrimaryMaxAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetSecondaryAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nViewTargetPrimaryAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetCurrentPowerpool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fViewTargetNextRegenTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxVGSSoundChannels, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_TeamRabbitAssistCredit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_TeamAssistCredit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_DamageNeededForCredit, 0xFFFFFFFF )
			ADD_OBJECT( MaterialEffect, m_RoundEndedME )
			ADD_VAR( ::FloatProperty, m_fDeterminationAccumulator, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeterminationAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LoadingScreenTimeout, 0xFFFFFFFF )
			ADD_OBJECT( TrPaperDoll, m_PaperDoll )
			ADD_VAR( ::FloatProperty, m_fDeathCameraOuterScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fUserSuicideTimePenalty, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpamLockoutTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLockoutFromSpamTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMessageSpamTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_fMaxBroadcastSpamCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSpotTargetTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, s_nNewPlayerAssistPoints, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, s_nMaxNewPlayerAssistPoints, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, s_fNewPlayerAssistMitigateCauseDamageMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, s_fNewPlayerAssistMitigateTakeDamageMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFlagGrabSpeedRecord, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFlagCapSpeedRecord, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiSpeedRecord, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCheckTotal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSpeedCheckCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastSpeedCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCheckInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fHideJetpackHelpTextDistanceThresholdSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTotalDistanceJetpackedSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fHideSkiHelpTextDistanceThresholdSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastDistanceSkiedSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastDistanceCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDistanceCheckInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTotalDistanceSkiedSq, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_HelpTextManagerClass )
			ADD_OBJECT( TrVehicle, m_LastAcknowledgedVehicle )
			ADD_VAR( ::IntProperty, m_ActiveClassId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_LastVGSUse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fIdleCheckTimer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedVZeroSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedPPTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedPPAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_RoundEndedPPInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCameraSpeedSqared, 0xFFFFFFFF )
			ADD_OBJECT( UDKEmitCameraEffect, m_WeatherCameraEffect )
			ADD_OBJECT( UDKEmitCameraEffect, m_SpeedCameraEffect )
			ADD_VAR( ::IntProperty, m_nLatestAccoladeIcon, 0xFFFFFFFF )
			ADD_OBJECT( TrCameraModifier_CameraShake, m_CameraShake )
			ADD_OBJECT( Weapon, m_LastWeaponEquipped )
			ADD_VAR( ::IntProperty, m_VehicleSeatIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_LastPressedSkiTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinActiveSkiTimeToEnableFollowthough, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkiFollowthroughTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, r_KilledBy )
			ADD_VAR( ::FloatProperty, m_LastLoadoutRequestTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nClientSpawnTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRespawnTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPlayBeginTime, 0xFFFFFFFF )
			ADD_OBJECT( TrAnnouncer, m_Announcer )
			ADD_OBJECT( TrMusicManager, m_MusicManager )
			ADD_VAR( ::FloatProperty, c_fHUDZoomDuration, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_CurrentDecelerationFactor, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_nCallinCooldownFlashStored, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_nLastHitEnemyHeadshot, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nHitEnemy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, c_fZoomButtonPressedTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fZoomRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDesiredMagnifiedZoomFOV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDesiredZoomFOV, 0xFFFFFFFF )
			ADD_OBJECT( TrStation, m_CurrentStation )
			ADD_VAR( ::IntProperty, r_nCurrentCredits, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_RicochetSound3P )
			ADD_OBJECT( SoundCue, m_MissileSeekingSelfCue )
			ADD_OBJECT( SoundCue, m_MissileFiredCue )
			ADD_OBJECT( SoundCue, m_MissileLockedCue )
			ADD_OBJECT( SoundCue, m_MissileLockingCue )
			ADD_VAR( ::IntProperty, m_OverwatchTeam, 0xFFFFFFFF )
			ADD_OBJECT( CameraActor, m_OverwatchCam )
			ADD_STRUCT( ::RotatorProperty, m_rKickbackAim, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastKickbackViewTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fKickbackViewBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fKickbackViewBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingInitiatingJettingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWarmingUp, 0x20000000 )
			ADD_VAR( ::BoolProperty, m_bAirSpeedBoundToGroundSpeed, 0x8000000 )
			ADD_VAR( ::BoolProperty, m_bEnableChatFilter, 0x4000000 )
			ADD_VAR( ::BoolProperty, bBlockForAcquisition, 0x1000000 )
			ADD_VAR( ::BoolProperty, m_bAnimMenu, 0x200000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDFriendStateNotifications, 0x80000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDNotifications, 0x40000 )
			ADD_VAR( ::BoolProperty, m_bShowHUDObjectives, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEnableOverheadDamageIndicators, 0x1 )
			ADD_VAR( ::BoolProperty, r_bViewTargetVehicleSecondaryWeaponReady, 0x80000000 )
			ADD_VAR( ::BoolProperty, r_bViewTargetVehiclePrimaryWeaponReady, 0x40000000 )
			ADD_VAR( ::BoolProperty, r_bWeeklyCompleted, 0x4000000 )
			ADD_VAR( ::BoolProperty, m_bIsJumpJetting, 0x1000000 )
			ADD_VAR( ::BoolProperty, m_bJustJoined, 0x800000 )
			ADD_VAR( ::BoolProperty, m_bMonkeyMode, 0x100000 )
			ADD_VAR( ::BoolProperty, m_bJetpackHelpTextThresholdReached, 0x80000 )
			ADD_VAR( ::BoolProperty, m_bSkiHelpTextThresholdReached, 0x40000 )
			ADD_VAR( ::BoolProperty, m_bEnableCameraSpeedEffect, 0x20000 )
			ADD_VAR( ::BoolProperty, m_bLoadoutChangeAlerted, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bRequestingSki, 0x2000 )
			ADD_VAR( ::BoolProperty, m_bPlayerSwappedTeams, 0x1000 )
			ADD_VAR( ::BoolProperty, m_bReturnTo3PAfterZoom, 0x800 )
			ADD_VAR( ::BoolProperty, m_bZoomMagnified, 0x400 )
			ADD_VAR( ::BoolProperty, m_bPlayCreditsSound, 0x100 )
			ADD_VAR( ::BoolProperty, bWasAutoBalanced, 0x80 )
			ADD_VAR( ::BoolProperty, m_bAftermathKill, 0x40 )
			ADD_VAR( ::BoolProperty, m_bKickbackBlendingIn, 0x20 )
			ADD_VAR( ::BoolProperty, m_bBlink, 0x10 )
			ADD_VAR( ::BoolProperty, m_bJumpJet, 0x8 )
			ADD_VAR( ::BoolProperty, m_bPressingJetpackButton, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEditorMode, 0x1 )
			ADD_VAR( ::FloatProperty, m_fLastWeaponSwitchTimestamp, 0xFFFFFFFF )
			ADD_OBJECT( Actor, m_aHoverActor )
			void SendCtrlRequest( ScriptArray< wchar_t > fsRequest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SendCtrlRequest" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = fsRequest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendGameRequest( ScriptArray< wchar_t > fsRequest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SendGameRequest" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = fsRequest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TestSteamPurchase(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TestSteamPurchase" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowAdminPage( ScriptArray< wchar_t > ServerURL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowAdminPage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = ServerURL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHitValidationMode( int loggingMode, int validationMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetHitValidationMode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = loggingMode;
				*( int* )( params + 4 ) = validationMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickPlayerFromMatch( int Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.KickPlayerFromMatch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MainMenuIsOpen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.MainMenuIsOpen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetMenuInGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetMenuInGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMenuToLobby(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SendMenuToLobby" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TweenSummaryScreen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TweenSummaryScreen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMenuSummaryScreen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetMenuSummaryScreen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMenuEndOfMatch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetMenuEndOfMatch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginExperienceTweens(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.BeginExperienceTweens" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickVoteReply( bool bVote )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.KickVoteReply" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bVote;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMenuMatchCountdown( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetMenuMatchCountdown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetUserSelectedClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetUserSelectedClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void RevertSetting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.RevertSetting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMenuBack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SendMenuBack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireAcquisition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FireAcquisition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceFocus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ForceFocus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTVTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateTVTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateDealTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateDealTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateQueueTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateQueueTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleWorkingGraphic( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleWorkingGraphic" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndHotkeyBlock(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EndHotkeyBlock" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MutePlayer( ScriptArray< wchar_t > PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.MutePlayer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnmutePlayer( ScriptArray< wchar_t > PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UnmutePlayer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HaveMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.HaveMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsChatFiltered( ScriptArray< wchar_t > PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsChatFiltered" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RequestKickVote( ScriptArray< wchar_t > PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.RequestKickVote" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.HideMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OpenMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OpenMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OpenClasses(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OpenClasses" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleFriends(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleFriends" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleMainMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleMainMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClaimPromotion( ScriptArray< wchar_t > PromoCode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClaimPromotion" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PromoCode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireUILoadSummary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FireUILoadSummary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireRefreshPage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FireRefreshPage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleBassBoost( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleBassBoost" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForwardChatFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ForwardChatFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowNotification( ScriptArray< wchar_t > Message, ScriptArray< wchar_t > Message2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowNotification" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Message;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideNotification(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.HideNotification" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChatMessageReceived( int Channel, ScriptArray< wchar_t > Sender, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ChatMessageReceived" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = Channel;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Sender;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowChat(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowChat" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideChat(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.HideChat" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleChat(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleChat" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PushChat( ScriptArray< wchar_t > chatStr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PushChat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = chatStr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Bug(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Bug" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void _Crash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController._Crash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsGameUsingSeekFreeLoading(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsGameUsingSeekFreeLoading" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ResetRunaway(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ResetRunaway" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearVehicleMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClearVehicleMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowVehicleMenu( int Credits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowVehicleMenu" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Credits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddVehicleMenuOption( ScriptArray< wchar_t > ClassName, ScriptArray< wchar_t > DisplayName, int Cost, int Icon, int CountSpawned, int CountAllowed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AddVehicleMenuOption" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptArray< wchar_t >* )params = ClassName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = DisplayName;
				*( int* )( params + 24 ) = Cost;
				*( int* )( params + 28 ) = Icon;
				*( int* )( params + 32 ) = CountSpawned;
				*( int* )( params + 36 ) = CountAllowed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetOnlineFriends(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetOnlineFriends" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitHelpTextManager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.InitHelpTextManager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.InitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayAnnouncerSound( class SoundCue* AnnouncementCue, bool bPlayRightNow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayAnnouncerSound" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SoundCue** )params = AnnouncementCue;
				*( bool* )( params + 4 ) = bPlayRightNow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TestAnnouncement( bool bPlayRightNow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TestAnnouncement" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bPlayRightNow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientHearReliableSound( class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientHearReliableSound" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class SoundCue** )params = ASound;
				*( class Actor** )( params + 4 ) = SourceActor;
				*( Vector* )( params + 8 ) = SourceLocation;
				*( bool* )( params + 20 ) = bStopWhenOwnerDestroyed;
				*( bool* )( params + 24 ) = bIsOccluded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientMySaberLauncherTargetingUpdated( byte MissileLockValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientMySaberLauncherTargetingUpdated" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = MissileLockValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSeekingMissileTargetingSelfEvent( int EventSwitch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientSeekingMissileTargetingSelfEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = EventSwitch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMissileIntercepted(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnMissileIntercepted" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowHUDNotification( ScriptArray< wchar_t > Message, ScriptArray< wchar_t > Message2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowHUDNotification" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Message;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideHUDNotification(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.HideHUDNotification" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckBulletWhip( class SoundCue* BulletWhip, Vector FireLocation, Vector FireDir, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CheckBulletWhip" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class SoundCue** )params = BulletWhip;
				*( Vector* )( params + 4 ) = FireLocation;
				*( Vector* )( params + 16 ) = FireDir;
				*( Vector* )( params + 28 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessCreditEvent( byte EventType, bool bProxyEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ProcessCreditEvent" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = EventType;
				*( bool* )( params + 4 ) = bProxyEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ModifyCredits( int Count, bool bFreeCredits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ModifyCredits" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Count;
				*( bool* )( params + 4 ) = bFreeCredits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateCurrentCredits( int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateCurrentCredits" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreditsSoundFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CreditsSoundFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientUpdateCredits( int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientUpdateCredits" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetLatestAccoladeIconIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetLatestAccoladeIconIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ClientShowAccoladeIcon( int IconIndex, ScriptArray< wchar_t > Description, ScriptArray< wchar_t > Points )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientShowAccoladeIcon" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = IconIndex;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Description;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Points;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientShowAccoladeText( ScriptArray< wchar_t > Message, int ShowTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientShowAccoladeText" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Message;
				*( int* )( params + 12 ) = ShowTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetStreaks(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ResetStreaks" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GiveCredits( int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GiveCredits" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerGiveCreditsCheat( int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerGiveCreditsCheat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AimingHelp( bool bInstantHit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AimingHelp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInstantHit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyChangedWeapon( class Weapon* PreviousWeapon, class Weapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.NotifyChangedWeapon" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )params = PreviousWeapon;
				*( class Weapon** )( params + 4 ) = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReloadWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReloadWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerReloadWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerReloadWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetCharFamily( ScriptArray< wchar_t > FamilyClassStr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSetCharFamily" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = FamilyClassStr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Suicide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Suicide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSuicide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSuicide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetArmorType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetArmorType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			float GetRespawnDelayTotalTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetRespawnDelayTotalTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Rotator LimitViewRotation( Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.LimitViewRotation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Rotator* )params = ViewRotation;
				*( float* )( params + 12 ) = ViewPitchMin;
				*( float* )( params + 16 ) = ViewPitchMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void PressedMelee(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedMelee" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PressedLaser(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedLaser" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PressedBelt(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedBelt" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PressedPack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedPack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PressedDeployable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedDeployable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetShowEquip( bool bShow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetShowEquip" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bShow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PressedConsoleUse(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedConsoleUse" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PressedWeaponSwitch( bool bFilterTimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedWeaponSwitch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bFilterTimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EquipPrimary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EquipPrimary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EquipSecondary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EquipSecondary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchWeapon( byte T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SwitchWeapon" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PrevWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PrevWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NextWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.NextWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivateDevice( byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ActivateDevice" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateLockedTarget( class Actor* LockedActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateLockedTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = LockedActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IdentifyTeamMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IdentifyTeamMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayStartupMessage( byte StartupStage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayStartupMessage" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = StartupStage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindValidGRI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FindValidGRI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitHUDObjects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.InitHUDObjects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStartSpawnTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientStartSpawnTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CompletePickTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CompletePickTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRequestAutoAssignTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestAutoAssignTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientEndTeamSelect( int RequestedTeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientEndTeamSelect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = RequestedTeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeTeam( ScriptArray< wchar_t > TeamName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ChangeTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TeamName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewAPlayer( int Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ViewAPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerPlayerTick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerPlayerTick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayerTick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayerTick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Rotator GetAdjustedAimFor( class Weapon* W, Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetAdjustedAimFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )params = W;
				*( Vector* )( params + 4 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void StartWeather(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartWeather" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopWeather(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StopWeather" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnEnteredWeatherVolume( bool bDeactivatePawnCentricWeather, class TrWeatherVolume* WeatherVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PawnEnteredWeatherVolume" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bDeactivatePawnCentricWeather;
				*( class TrWeatherVolume** )( params + 4 ) = WeatherVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnLeftWeatherVolume( bool bDeactivatePawnCentricWeather, class TrWeatherVolume* WeatherVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PawnLeftWeatherVolume" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bDeactivatePawnCentricWeather;
				*( class TrWeatherVolume** )( params + 4 ) = WeatherVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayLowHealthFX(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayLowHealthFX" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopLowHealthFX(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StopLowHealthFX" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRechargeHealthFX(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayRechargeHealthFX" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopRechargeHealthFX(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StopRechargeHealthFX" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleJetpack( bool bEnabled, bool bJump )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleJetpack" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bEnabled;
				*( bool* )( params + 4 ) = bJump;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableJetpack( bool bEnabled, bool bJump, bool bForcedOff )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableJetpack" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )params = bEnabled;
				*( bool* )( params + 4 ) = bJump;
				*( bool* )( params + 8 ) = bForcedOff;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IgnoreMoveInput( bool bNewMoveInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IgnoreMoveInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewMoveInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DoJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformBlink(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PerformBlink" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetBlinkPackAccel( Vector &newAccel, float &BlinkPackPctEffectiveness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetBlinkPackAccel" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = newAccel;
				*( float* )( params + 12 ) = BlinkPackPctEffectiveness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				newAccel = *( Vector* )params;
				BlinkPackPctEffectiveness = *( float* )( params + 12 );
			}

			void InitRespawnTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.InitRespawnTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateRespawnTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateRespawnTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRequestRespawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestRespawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RequestRespawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.RequestRespawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Respawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Respawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRespawnSoonSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayRespawnSoonSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CleanupGameplayEffectsOnDeath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CleanupGameplayEffectsOnDeath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCrossedOffArenaList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnCrossedOffArenaList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Possess( class Pawn* aPawn, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Possess" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = aPawn;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshHUD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.RefreshHUD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetAirVehicleInversion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetAirVehicleInversion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerSetAirVehicleControls( bool bInvert )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSetAirVehicleControls" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInvert;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAirVehicleControls( bool bInvert )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetAirVehicleControls" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInvert;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsInVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsInVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClientVehiclePhysUpdated( class TrVehicle* InVehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientVehiclePhysUpdated" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrVehicle** )params = InVehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerVehiclePhysUpdated( class TrVehicle* InVehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerVehiclePhysUpdated" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrVehicle** )params = InVehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerVerifyVehiclePhys( float TimeStamp, float InForward, float InStrafe, float InUp, int View, void* InRBState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerVerifyVehiclePhys" );
				byte *params = ( byte* )( malloc( 84 ) );
				*( float* )params = TimeStamp;
				*( float* )( params + 4 ) = InForward;
				*( float* )( params + 8 ) = InStrafe;
				*( float* )( params + 12 ) = InUp;
				*( int* )( params + 16 ) = View;
				*( void** )( params + 32 ) = InRBState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerCorrectClientPhys( float TimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerCorrectClientPhys" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = TimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerToggleVehicleJets( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerToggleVehicleJets" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleVehicleJets( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleVehicleJets" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessRiding( Rotator ViewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ProcessRiding" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )params = ViewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRiding( float TimeStamp, int View )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRiding" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = TimeStamp;
				*( int* )( params + 4 ) = View;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchToCallIn( byte T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SwitchToCallIn" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRequestCallInChange( byte T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestCallInChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchToSeat( byte T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SwitchToSeat" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSwitchToSeat( byte T, class TrVehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSwitchToSeat" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = T;
				*( class TrVehicle** )( params + 4 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TriggerInteracted(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TriggerInteracted" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerRequestLoadoutChange( ScriptClass* FamilyInfo, int Loadout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestLoadoutChange" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = FamilyInfo;
				*( int* )( params + 4 ) = Loadout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePaperDoll( ScriptClass* FamilyInfo, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdatePaperDoll" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = FamilyInfo;
				*( ScriptClass** )( params + 4 ) = DeviceClass;
				*( ScriptClass** )( params + 8 ) = skinClass;
				*( int* )( params + 12 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePaperDoll_Device( ScriptClass* DeviceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdatePaperDoll_Device" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DeviceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnVehicle( ScriptArray< wchar_t > vehicleClassStr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SpawnVehicle" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = vehicleClassStr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RequestBuyVehicle( ScriptArray< wchar_t > vehicleClassStr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.RequestBuyVehicle" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = vehicleClassStr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PressedSki( bool bJump )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedSki" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bJump;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReleasedSki(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReleasedSki" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleSki(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleSki" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DelayReleasedSki(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DelayReleasedSki" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBindSkiJet( int method )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetBindSkiJet" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = method;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleShowObjectMarkers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ToggleShowObjectMarkers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerStartSki( bool bJump )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerStartSki" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bJump;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerStopSki(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerStopSki" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetHUD( ScriptClass* newHUDType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientSetHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = newHUDType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchHud(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SwitchHud" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnKickback( Rotator KickbackAim, float KickbackBlendOutTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnKickback" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )params = KickbackAim;
				*( float* )( params + 12 ) = KickbackBlendOutTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateKickbackDirection( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateKickbackDirection" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RestoreMoveInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.RestoreMoveInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRestoreMoveInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientRestoreMoveInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRequestSpawnVehicle( ScriptClass* VehicleClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestSpawnVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = VehicleClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PerformedUseAction(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PerformedUseAction" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PressedZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PressedZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReleasedZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReleasedZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MagnifyZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.MagnifyZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DemagnifyZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DemagnifyZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReleaseZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReleaseZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckZoomButton(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CheckZoomButton" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TrStartZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TrStartZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TrStopZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TrStopZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TrEndZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TrEndZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetZoomDuration( bool bPlayRechargeSoundOnWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ResetZoomDuration" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bPlayRechargeSoundOnWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetZoom( byte NewZoomState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSetZoom" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewZoomState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveLocalizedMessage( ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReceiveLocalizedMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )params = Message;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveLocalizedNagMessage( ScriptClass* Message, int Switch, float Time )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReceiveLocalizedNagMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptClass** )params = Message;
				*( int* )( params + 4 ) = Switch;
				*( float* )( params + 8 ) = Time;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TrClientMusicEvent( int EventIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TrClientMusicEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = EventIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRestart( class Pawn* NewPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientRestart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = NewPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateClientSpawnTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateClientSpawnTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameHasEnded( class Actor* EndGameFocus, bool bIsWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GameHasEnded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = EndGameFocus;
				*( bool* )( params + 4 ) = bIsWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckJumpOrDuck(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CheckJumpOrDuck" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientGameEnded( class Actor* EndGameFocus, bool bIsWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientGameEnded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = EndGameFocus;
				*( bool* )( params + 4 ) = bIsWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerDropFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerDropFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPlayerViewPoint( Vector &POVLocation, Rotator &POVRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetPlayerViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = POVLocation;
				*( Rotator* )( params + 12 ) = POVRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				POVLocation = *( Vector* )params;
				POVRotation = *( Rotator* )( params + 12 );
			}

			void ActivateFreeCam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ActivateFreeCam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeactivateFreeCam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DeactivateFreeCam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetViewTargetAsOverwatch( bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetViewTargetAsOverwatch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayCameraShake( ScriptName ShakeName, float Scale, class CameraShake* SourceShake )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PlayCameraShake" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = ShakeName;
				*( float* )( params + 8 ) = Scale;
				*( class CameraShake** )( params + 12 ) = SourceShake;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayForceFeedbackWaveform( class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPlayForceFeedbackWaveform" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class ForceFeedbackWaveform** )params = FFWaveform;
				*( class Actor** )( params + 4 ) = FFWaveformInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSpeedCameraEffect( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateSpeedCameraEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpeedCamEffect( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SpeedCamEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPulseHUD( byte Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPulseHUD" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PulseShield(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.PulseShield" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddTimePlayed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AddTimePlayed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AcknowledgePossession( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AcknowledgePossession" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MatchEndSoundMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.MatchEndSoundMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetSoundMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ResetSoundMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SuppressHelpText(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SuppressHelpText" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TalkVGS( ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TalkVGS" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Say( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Say" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPlayerCommand( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsPlayerCommand" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ShowFeedbackMessage( ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowFeedbackMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetChatColor( byte Channel, bool bSameTeam, int &ChatColorIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetChatColor" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = Channel;
				*( bool* )( params + 4 ) = bSameTeam;
				*( int* )( params + 8 ) = ChatColorIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ChatColorIdx = *( int* )( params + 8 );
				return *( void** )( params + function->return_val_offset() );
			}

			void AddChatToConsole( ScriptArray< wchar_t > Sender, ScriptArray< wchar_t > ChatMessage, byte Channel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AddChatToConsole" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( ScriptArray< wchar_t >* )params = Sender;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ChatMessage;
				*( byte* )( params + 24 ) = Channel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetLastTellSender(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetLastTellSender" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ReplyTalk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ReplyTalk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanCommunicate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CanCommunicate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Talk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Talk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChatConsole( bool bTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ChatConsole" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TalkConsole( bool bTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TalkConsole" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamTalk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TeamTalk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamSay( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TeamSay" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowTextMessage( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AllowTextMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WarnPlayerAboutSpam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.WarnPlayerAboutSpam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginVGS(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.BeginVGS" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpotTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SpotTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRequestVGSContextCommand( byte ContextActor, byte ContextLocation, bool bEnemyLocation, class Actor* SpottedActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestVGSContextCommand" );
				byte *params = ( byte* )( malloc( 10 ) );
				*( byte* )params = ContextActor;
				*( byte* )( params + 1 ) = ContextLocation;
				*( bool* )( params + 4 ) = bEnemyLocation;
				*( class Actor** )( params + 8 ) = SpottedActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRequestVGSCommand( byte VGSCommandIndex, bool bGlobal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerRequestVGSCommand" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = VGSCommandIndex;
				*( bool* )( params + 4 ) = bGlobal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveVGSCommand( class PlayerReplicationInfo* PRI, byte VGSCommandIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientReceiveVGSCommand" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				*( byte* )( params + 4 ) = VGSCommandIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveVGSContextCommand( class PlayerReplicationInfo* PRI, byte ContextActor, byte ContextLocation, bool bEnemyLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientReceiveVGSContextCommand" );
				byte *params = ( byte* )( malloc( 10 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				*( byte* )( params + 4 ) = ContextActor;
				*( byte* )( params + 5 ) = ContextLocation;
				*( bool* )( params + 8 ) = bEnemyLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMoveErrors( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowMoveErrors" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSkiHelpTextDistanceThresholdReached(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnSkiHelpTextDistanceThresholdReached" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJetpackHelpTextDistanceThresholdReached(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnJetpackHelpTextDistanceThresholdReached" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadPlayerProfile(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.LoadPlayerProfile" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetNewPlayerAssistAmount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetNewPlayerAssistAmount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void UpdateNewPlayerAssistPoints( int AmoutToSubtract )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateNewPlayerAssistPoints" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = AmoutToSubtract;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BehindView(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.BehindView" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetBehindView( bool bNewBehindView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSetBehindView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewBehindView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetBehindView( bool bNewBehindView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientSetBehindView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewBehindView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PlayerInput* GetEngineSettings( bool bUse )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetEngineSettings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bUse;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerInput** )( params + function->return_val_offset() );
			}

			class TrPlayerInput_Spectator* GetSpectatorSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetSpectatorSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrPlayerInput_Spectator** )( params + function->return_val_offset() );
			}

			void ClientOnMotionSensorAlarmSounded( class TrDeployable_MotionSensor* MotionSensor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientOnMotionSensorAlarmSounded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrDeployable_MotionSensor** )params = MotionSensor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientOnMotionSensorMineSounded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientOnMotionSensorMineSounded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadPendingLoadoutContentData( int ClassId, int Loadout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.LoadPendingLoadoutContentData" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Loadout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadPendingDeviceContentData( ScriptClass* DeviceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.LoadPendingDeviceContentData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DeviceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideHUDElements(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.HideHUDElements" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientShowFlagIcon( bool bShow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientShowFlagIcon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bShow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetPlayerClassObjects( ScriptArray< wchar_t > ClassName, int PerkIcon1, int PerkIcon2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientSetPlayerClassObjects" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )params = ClassName;
				*( int* )( params + 12 ) = PerkIcon1;
				*( int* )( params + 16 ) = PerkIcon2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePotentialSeekingTargets(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdatePotentialSeekingTargets" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NotifyHitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.NotifyHitWall" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyFallingHitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.NotifyFallingHitWall" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Spectate( bool bNeutral )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.Spectate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNeutral;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndSpectate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EndSpectate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSpectate( bool bNeutral )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientSpectate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNeutral;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSpectate( bool bNeutral )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSpectate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNeutral;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewFlags( int Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerViewFlags" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewFlagStands( int Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerViewFlagStands" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewGenerators( int Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerViewGenerators" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewBookmark( int Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerViewBookmark" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewVehicles( int Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerViewVehicles" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewFastestPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerViewFastestPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewActor( class Actor* ActorToView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerViewActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = ActorToView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientOnViewTargetChange( class Actor* NewViewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientOnViewTargetChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = NewViewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerIncreaseCamDistance( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerIncreaseCamDistance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerDecreaseCamDistance( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerDecreaseCamDistance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetMoveSpeed( float NewSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSetMoveSpeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnViewTargetCapturedFlag( class TrFlagCTF* NewFlagToWatch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnViewTargetCapturedFlag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrFlagCTF** )params = NewFlagToWatch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnViewTargetFlagReturned(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnViewTargetFlagReturned" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnViewTargetDroppedFlag( class TrFlagBase* NewFlagToWatch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnViewTargetDroppedFlag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrFlagBase** )params = NewFlagToWatch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnViewTargetLeftVehicle( class PlayerReplicationInfo* NewPRIToWatch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnViewTargetLeftVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = NewPRIToWatch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetViewTargetList( class TrPawn* &PawnViewTarget, class TrVehicle* &VehicleViewTarget, class TrCamera_SpectatorBookmark* &BookmarkViewTarget, class Actor* &ObjectiveViewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetViewTargetList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class TrPawn** )params = PawnViewTarget;
				*( class TrVehicle** )( params + 4 ) = VehicleViewTarget;
				*( class TrCamera_SpectatorBookmark** )( params + 8 ) = BookmarkViewTarget;
				*( class Actor** )( params + 12 ) = ObjectiveViewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PawnViewTarget = *( class TrPawn** )params;
				VehicleViewTarget = *( class TrVehicle** )( params + 4 );
				BookmarkViewTarget = *( class TrCamera_SpectatorBookmark** )( params + 8 );
				ObjectiveViewTarget = *( class Actor** )( params + 12 );
			}

			void ServerUnPossess(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerUnPossess" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayTakeHit( Vector HitLoc, byte Damage, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPlayTakeHit" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( Vector* )params = HitLoc;
				*( byte* )( params + 12 ) = Damage;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayReticuleHitSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPlayReticuleHitSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayBluePlateImpact(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPlayBluePlateImpact" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayAirMailImpact(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPlayAirMailImpact" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SummarizeAwards(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SummarizeAwards" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientMatchOver( int Winner, ScriptArray< wchar_t > WinnerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientMatchOver" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = WinnerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetEndOfMatch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientSetEndOfMatch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientFadeToSummary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientFadeToSummary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMatchCountdown( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateMatchCountdown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateRoundCountdown( int Seconds, int Round )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateRoundCountdown" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Seconds;
				*( int* )( params + 4 ) = Round;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGameCountdown( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateGameCountdown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerKickPlayer( int Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerKickPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientKickPlayer( int Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientKickPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickWarning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.KickWarning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FumbledFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FumbledFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientOnFumbledFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientOnFumbledFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateCallInAvailability(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateCallInAvailability" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateCallInCooldown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateCallInCooldown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CalcCameraOnViewTarget( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CalcCameraOnViewTarget" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )params = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
			}

			bool IsGameTypeArena(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsGameTypeArena" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsGameTypeDaD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsGameTypeDaD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsGameTypeCaH(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.IsGameTypeCaH" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SwitchToDeathCamera(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SwitchToDeathCamera" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddProjectileToTetherList( class TrProjectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AddProjectileToTetherList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrProjectile** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckTetherList( class TrProjectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CheckTetherList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrProjectile** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrProjectile* TetherProjectile( class TrProjectile* ProjectileFromServer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TetherProjectile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrProjectile** )params = ProjectileFromServer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProjectile** )( params + function->return_val_offset() );
			}

			void ConfigureSkiSpeedSteps( float SoftCap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ConfigureSkiSpeedSteps" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = SoftCap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadingTimer( bool bStart )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.LoadingTimer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bStart;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlushAccumulatedDetermination(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FlushAccumulatedDetermination" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDetermination(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClearDetermination" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDetermination(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AddDetermination" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMenuMovieOpened(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnMenuMovieOpened" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMenuMovieClosed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnMenuMovieClosed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayVGSAudio( class SoundCue* ASound, class PlayerReplicationInfo* InstigatorPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPlayVGSAudio" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SoundCue** )params = ASound;
				*( class PlayerReplicationInfo** )( params + 4 ) = InstigatorPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VGSAudioFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.VGSAudioFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetLastDamagerInfo( int Health, int UpgradeLevel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientSetLastDamagerInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Health;
				*( int* )( params + 4 ) = UpgradeLevel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableTinyWeapons( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableTinyWeapons" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetTinyWeaponValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetTinyWeaponValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EnableChatFilter( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableChatFilter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetChatFilterValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetChatFilterValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EnableDamageCounter( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableDamageCounter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetDamageCounterValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetDamageCounterValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EnableHUDObjectives( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDObjectives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDReticule( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDReticule" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDCredits( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDCredits" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDAccolades( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDAccolades" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDBadges( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDBadges" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDScores( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDScores" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDHealthBar( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDHealthBar" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDVisor( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDVisor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDChat( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDChat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDCombatLog( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDCombatLog" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDKillbox( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDKillbox" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDDeathcam( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDDeathcam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDHeroText( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDHeroText" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDPromptPanel( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDPromptPanel" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDRespawnTimer( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDRespawnTimer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDSkiBars( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDSkiBars" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDFriendColoring( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDFriendColoring" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDNotifications( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDNotifications" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDFriendStateNotifications( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDFriendStateNotifications" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableHUDCracks( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EnableHUDCracks" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowAlienFX( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ShowAlienFX" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetHUDObjectivesValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetHUDObjectivesValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetHUDNotifications(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetHUDNotifications" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetHUDFriendStateNotifications(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetHUDFriendStateNotifications" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetWhisperFilterValue(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetWhisperFilterValue" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetWhisperFilter( int FilterValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetWhisperFilter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FilterValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SummaryTweenTimer( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SummaryTweenTimer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VoteNo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.VoteNo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VoteYes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.VoteYes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlashShooterHitReticule( int DamageAmount, bool isInstantHit, int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FlashShooterHitReticule" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = DamageAmount;
				*( bool* )( params + 4 ) = isInstantHit;
				*( int* )( params + 8 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerShowOverheadNumber( int NumberToShow, Vector WorldLocation, float fScreenDepth )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerShowOverheadNumber" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = NumberToShow;
				*( Vector* )( params + 4 ) = WorldLocation;
				*( float* )( params + 16 ) = fScreenDepth;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientShowOverheadNumber( int NumberToShow, Vector WorldLocation, float fScreenDepth )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientShowOverheadNumber" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = NumberToShow;
				*( Vector* )( params + 4 ) = WorldLocation;
				*( float* )( params + 16 ) = fScreenDepth;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetCreditsForDamageAmount( int DamageAmount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetCreditsForDamageAmount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = DamageAmount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void CashForDamage( int DamageAmount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CashForDamage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = DamageAmount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AwardTeamAssistCredits(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AwardTeamAssistCredits" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AwardTeamRabbitAssistCredits( int Multiplier )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AwardTeamRabbitAssistCredits" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Multiplier;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TypeKeyPressed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TypeKeyPressed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FOV( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FixFOV(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.FixFOV" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFOV( float NewFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetClassAffordable( int BitMask )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSetClassAffordable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = BitMask;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetClassBit( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.GetClassBit" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void TestTrainingSlot( byte equipType, int EquipId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TestTrainingSlot" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = equipType;
				*( int* )( params + 4 ) = EquipId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TestSlot( byte equipType, int EquipId, bool bTraining )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TestSlot" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = equipType;
				*( int* )( params + 4 ) = EquipId;
				*( bool* )( params + 8 ) = bTraining;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerTestSlot( byte EquipId, int EquipItem )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerTestSlot" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = EquipId;
				*( int* )( params + 4 ) = EquipItem;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDeviceContentDataClassLoaded( ScriptClass* DeviceContentDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnDeviceContentDataClassLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DeviceContentDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void On3PSkinContentLoaded( ScriptClass* Skin3PDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.On3PSkinContentLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Skin3PDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void On1PSkinContentLoaded( ScriptClass* Skin1PDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.On1PSkinContentLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Skin1PDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPending3PSkin( class TrPlayerReplicationInfo* TrPRI, int skinId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AddPending3PSkin" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerReplicationInfo** )params = TrPRI;
				*( int* )( params + 4 ) = skinId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClassSelectedMainMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnClassSelectedMainMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGiveCredits( class TrSeqAct_GiveCredits* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnGiveCredits" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrSeqAct_GiveCredits** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGiveAccolade( class TrSeqAct_GiveAccolade* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnGiveAccolade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrSeqAct_GiveAccolade** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayVGSCommand( class TrSeqAct_PlayVGSCommand* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnPlayVGSCommand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrSeqAct_PlayVGSCommand** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRefreshInventory( class TrSeqAct_RefreshInventory* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnRefreshInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrSeqAct_RefreshInventory** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartForceFocusTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartForceFocusTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartAcquisitionFireTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartAcquisitionFireTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartSettingBlock(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartSettingBlock" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AutoRevertSetting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.AutoRevertSetting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartSendMenuBackTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartSendMenuBackTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QueueTimer( bool bStart )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.QueueTimer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bStart;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TVTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.TVTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DealTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DealTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartHotkeyBlock(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartHotkeyBlock" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientArenaRoundEnded( int WinningTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientArenaRoundEnded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = WinningTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayerResettingAndRespawning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientPlayerResettingAndRespawning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyAllOwnedDeployables( ScriptClass* DestroyIfNotOfType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DestroyAllOwnedDeployables" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DestroyIfNotOfType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyAllOwnedMines( ScriptClass* DestroyIfNotOfType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DestroyAllOwnedMines" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DestroyIfNotOfType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyAllOwnedProjectiles(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.DestroyAllOwnedProjectiles" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QueueBadge( int Icon, ScriptArray< wchar_t > Title, ScriptArray< wchar_t > XPReward )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.QueueBadge" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = Icon;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 16 ) = XPReward;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientQueueAccolade( int Icon, ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Subtitle, bool bIsBadge )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClientQueueAccolade" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( int* )params = Icon;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Subtitle;
				*( bool* )( params + 28 ) = bIsBadge;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeyPTH(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeyPTH" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeySEN(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeySEN" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeyINF(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeyINF" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeySLD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeySLD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeyRDR(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeyRDR" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeyTCN(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeyTCN" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeyJUG(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeyJUG" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeyDMB(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeyDMB" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClassHotkeyBRT(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClassHotkeyBRT" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QuickClasses(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.QuickClasses" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QuickLoadouts( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.QuickLoadouts" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndVGSInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.EndVGSInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartUILoadSummaryTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartUILoadSummaryTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OpenVehicleMenu( class TrVehicleStation* VehicleStation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OpenVehicleMenu" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrVehicleStation** )params = VehicleStation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnScoreChanged( class UTTeamInfo* T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.OnScoreChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTTeamInfo** )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckFriendlyFireKills(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CheckFriendlyFireKills" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckFriendlyFireDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.CheckFriendlyFireDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartRefreshPageTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StartRefreshPageTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMainMenuPaperDoll_Mesh( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.UpdateMainMenuPaperDoll_Mesh" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMainMenuPaperDoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClearMainMenuPaperDoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPaperDoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ClearPaperDoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpecList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SpecList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SampleVoice( ScriptClass* VoiceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SampleVoice" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = VoiceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > StripTag( ScriptArray< wchar_t > sValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.StripTag" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = sValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetAllowSimProjectiles( bool bAllow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.SetAllowSimProjectiles" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bAllow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetAllowSimProjectiles( bool bAllow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerController.ServerSetAllowSimProjectiles" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bAllow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
