#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTPlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTPlayerController : public UDKPlayerController
	{
	public:
			ADD_VAR( ::BoolProperty, bLateComer, 0x1 )
			void ServerThrowWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerThrowWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.InitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PulseTeamColor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PulseTeamColor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetCharacterClass( ScriptClass* CharClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerSetCharacterClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = CharClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearStringAliasBindingMapCache(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClearStringAliasBindingMapCache" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( UTUIDataStore_StringAliasBindingsMap, BoundEventsStringDataStore )
			void RegisterCustomPlayerDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.RegisterCustomPlayerDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnregisterPlayerDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.UnregisterPlayerDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddOnlineDelegates( bool bRegisterVoice )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AddOnlineDelegates" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bRegisterVoice;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearOnlineDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClearOnlineDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetOnlineStatus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientSetOnlineStatus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnConnectionStatusChange( byte ConnectionStatus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnConnectionStatusChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = ConnectionStatus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLinkStatusChanged( bool bConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnLinkStatusChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadProfileSettingsComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnReadProfileSettingsComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameInviteReceived( byte LocalUserNum, ScriptArray< wchar_t > RequestingNick )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnGameInviteReceived" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = RequestingNick;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendInviteReceived( byte LocalUserNum, void* RequestingPlayer, ScriptArray< wchar_t > RequestingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnFriendInviteReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = RequestingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = RequestingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendMessageReceived( byte LocalUserNum, void* SendingPlayer, ScriptArray< wchar_t > SendingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnFriendMessageReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = SendingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = SendingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyInviteFailed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.NotifyInviteFailed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyNotAllPlayersCanJoinInvite(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.NotifyNotAllPlayersCanJoinInvite" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyNotEnoughSpaceInInvite(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.NotifyNotEnoughSpaceInInvite" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWasKicked(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientWasKicked" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFrontEndErrorMessage( ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetFrontEndErrorMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Title;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QuitToMainMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.QuitToMainMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bQuittingToMainMenu, 0x20000 )
			void FinishQuitToMainMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.FinishQuitToMainMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CleanupOnlineSubsystemSession( bool bWasFromMenu )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CleanupOnlineSubsystemSession" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasFromMenu;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnEndOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnEndOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDestroyOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnDestroyOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetSpeechRecognitionObject( class SpeechRecognition* NewRecognitionData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientSetSpeechRecognitionObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SpeechRecognition** )params = NewRecognitionData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpeechRecognitionComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SpeechRecognitionComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerProcessSpeechRecognition( void* ReplicatedWords )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerProcessSpeechRecognition" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )params = ReplicatedWords;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientHearSound( class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientHearSound" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class SoundCue** )params = ASound;
				*( class Actor** )( params + 4 ) = SourceActor;
				*( Vector* )( params + 8 ) = SourceLocation;
				*( bool* )( params + 20 ) = bStopWhenOwnerDestroyed;
				*( bool* )( params + 24 ) = bIsOccluded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AimingHelp( bool bInstantHit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AimingHelp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInstantHit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float AimHelpModifier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AimHelpModifier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Rotator GetAdjustedAimFor( class Weapon* W, Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.GetAdjustedAimFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )params = W;
				*( Vector* )( params + 4 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool FindVehicleToDrive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.FindVehicleToDrive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class UTVehicle* CheckPickedVehicle( class UTVehicle* V, bool bEnterVehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CheckPickedVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTVehicle** )params = V;
				*( bool* )( params + 4 ) = bEnterVehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTVehicle** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bJustFoundVehicle, 0x80000 )
			void ClientSetRequestedEntryWithFlag( class UTVehicle* V, bool bNewValue, int MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientSetRequestedEntryWithFlag" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTVehicle** )params = V;
				*( bool* )( params + 4 ) = bNewValue;
				*( int* )( params + 8 ) = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTVehicle* CheckVehicleToDrive( bool bEnterVehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CheckVehicleToDrive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnterVehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTVehicle** )( params + function->return_val_offset() );
			}

			void DropFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.DropFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerDropFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerDropFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool LandingShake(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.LandingShake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bLandingShake, 0x4000 )
			void PlayBeepSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PlayBeepSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveWarning( class Pawn* shooter, float projSpeed, Vector FireDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ReceiveWarning" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = shooter;
				*( float* )( params + 4 ) = projSpeed;
				*( Vector* )( params + 8 ) = FireDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastWarningTime, 0xFFFFFFFF )
			void ReceiveProjectileWarning( class Projectile* Proj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ReceiveProjectileWarning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = Proj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProjectileWarningTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ProjectileWarningTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayWinMessage( bool bWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PlayWinMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TriggerInteracted(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.TriggerInteracted" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayVehicleHorn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PlayVehicleHorn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastTauntAnimTime, 0xFFFFFFFF )
			void ServerPlayVehicleHorn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerPlayVehicleHorn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Typing( bool bTyping )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Typing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bTyping;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bIsTyping, 0x2 )
			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( UTAnnouncer, Announcer )
			ADD_OBJECT( UTMusicManager, MusicManager )
			void OnControllerChanged( int ControllerId, bool bIsConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnControllerChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ControllerId;
				*( bool* )( params + 4 ) = bIsConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SoakPause( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SoakPause" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bBehindView, 0x80 )
			void DrawHUD( class HUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.DrawHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )params = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickWarning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.KickWarning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastKickWarningTime, 0xFFFFFFFF )
			void CheckJumpOrDuck(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CheckJumpOrDuck" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FOV( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.FOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, OnFootDefaultFOV, 0xFFFFFFFF )
			void FixFOV(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.FixFOV" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Restart( bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Restart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRestart( class Pawn* NewPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientRestart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = NewPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, WeaponHandPreference, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoTaunt, 0x4 )
			ADD_VAR( ::BoolProperty, bCenteredWeaponFire, 0x8000 )
			ADD_VAR( ::ByteProperty, AutoObjectivePreference, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, VehicleControlType, 0xFFFFFFFF )
			void SetViewTarget( class Actor* NewViewTarget, void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetViewTarget" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = NewViewTarget;
				*( void** )( params + 4 ) = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, PawnShadowMode, 0xFFFFFFFF )
			void CheckAutoObjective( bool bOnlyNotifyDifferent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CheckAutoObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bOnlyNotifyDifferent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( Actor, LastAutoObjective )
			void SetAutoObjective( class Actor* ObjectiveActor, bool bOnlyNotifyDifferent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetAutoObjective" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = ObjectiveActor;
				*( bool* )( params + 4 ) = bOnlyNotifyDifferent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastShowPathTime, 0xFFFFFFFF )
			void ClientSetAutoObjective( class Actor* NewAutoObjective )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientSetAutoObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = NewAutoObjective;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Possess( class Pawn* inPawn, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Possess" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = inPawn;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AcknowledgePossession( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AcknowledgePossession" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bUseVehicleRotationOnPossess, 0x8 )
			ADD_VAR( ::ByteProperty, IdentifiedTeam, 0xFFFFFFFF )
			void IdentifyTeamMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.IdentifyTeamMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceivedPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ReceivedPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerPlayerPreferences( byte NewWeaponHand, bool bNewAutoTaunt, bool bNewCenteredWeaponFire, byte NewAutoObjectivePreference, byte NewVehicleControls )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerPlayerPreferences" );
				byte *params = ( byte* )( malloc( 11 ) );
				*( byte* )params = NewWeaponHand;
				*( bool* )( params + 4 ) = bNewAutoTaunt;
				*( bool* )( params + 8 ) = bNewCenteredWeaponFire;
				*( byte* )( params + 12 ) = NewAutoObjectivePreference;
				*( byte* )( params + 13 ) = NewVehicleControls;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetHand( byte NewWeaponHand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerSetHand" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewWeaponHand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, WeaponHand, 0xFFFFFFFF )
			void SetHand( byte NewWeaponHand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetHand" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewWeaponHand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetCameraMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ResetCameraMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UsingFirstPersonCamera(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.UsingFirstPersonCamera" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerSetAutoTaunt( bool Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerSetAutoTaunt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAutoTaunt( bool Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetAutoTaunt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleScreenShotMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ToggleScreenShotMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayStartupMessage( byte StartupStage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PlayStartupMessage" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = StartupStage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTakeHit( class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.NotifyTakeHit" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )params = InstigatedBy;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = Damage;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayTakeHit( Vector HitLoc, byte Damage, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientPlayTakeHit" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( Vector* )params = HitLoc;
				*( byte* )( params + 12 ) = Damage;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ServerUse(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerUse" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, LastUseTime, 0xFFFFFFFF )
			bool Use(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Use" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PerformedUseAction(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PerformedUseAction" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearDoubleClick(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClearDoubleClick" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bAlreadyReset, 0x400000 )
			void ShowScoreboard(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ShowScoreboard" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( Actor, CalcViewActor )
			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BehindView(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.BehindView" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBehindView( bool bNewBehindView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetBehindView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewBehindView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bFreeCamera, 0x200 )
			ADD_VAR( ::FloatProperty, LastCameraTimeStamp, 0xFFFFFFFF )
			void ClientSetBehindView( bool bNewBehindView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientSetBehindView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewBehindView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCameraMode( ScriptName NewCamMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetCameraMode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewCamMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bDebugFreeCam, 0x40000 )
			ADD_STRUCT( ::RotatorProperty, DebugFreeCamRot, 0xFFFFFFFF )
			void SpawnCamera(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SpawnCamera" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, MatineeCameraClass )
			void GetPlayerViewPoint( Vector &POVLocation, Rotator &POVRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.GetPlayerViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = POVLocation;
				*( Rotator* )( params + 12 ) = POVRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				POVLocation = *( Vector* )params;
				POVRotation = *( Rotator* )( params + 12 );
			}

			ADD_STRUCT( ::VectorProperty, CalcViewActorLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, CalcViewActorRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CalcEyeHeight, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CalcWalkBob, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CalcViewLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, CalcViewRotation, 0xFFFFFFFF )
			void CalcCameraOnViewTarget( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CalcCameraOnViewTarget" );
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

			void ClientMusicEvent( int EventIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientMusicEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = EventIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AlreadyInActionMusic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AlreadyInActionMusic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClientPlayAnnouncement( ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientPlayAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = InMessageClass;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayAnnouncement( ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PlayAnnouncement" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = InMessageClass;
				*( int* )( params + 4 ) = MessageIndex;
				*( class PlayerReplicationInfo** )( params + 8 ) = PRI;
				*( class Object** )( params + 12 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DamageShake( int Damage, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.DamageShake" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Damage;
				*( ScriptClass** )( params + 4 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( CameraAnim, DamageCameraAnim )
			ADD_VAR( ::BoolProperty, bCurrentCamAnimIsDamageShake, 0x1000 )
			void StopViewShaking(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.StopViewShaking" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayCameraAnim( class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bIsDamageShake )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PlayCameraAnim" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class CameraAnim** )params = AnimToPlay;
				*( float* )( params + 4 ) = Scale;
				*( float* )( params + 8 ) = Rate;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLoop;
				*( bool* )( params + 24 ) = bIsDamageShake;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bCurrentCamAnimAffectsFOV, 0x2000 )
			ADD_OBJECT( ForceFeedbackWaveform, CameraShakeShortWaveForm )
			ADD_OBJECT( ForceFeedbackWaveform, CameraShakeLongWaveForm )
			void StopCameraAnim( bool bImmediate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.StopCameraAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bImmediate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCameraAnimStrength( float NewStrength )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SetCameraAnimStrength" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewStrength;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayCameraAnim( class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, byte Space, Rotator CustomPlaySpace )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientPlayCameraAnim" );
				byte *params = ( byte* )( malloc( 41 ) );
				*( class CameraAnim** )params = AnimToPlay;
				*( float* )( params + 4 ) = Scale;
				*( float* )( params + 8 ) = Rate;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLoop;
				*( bool* )( params + 24 ) = bRandomStartTime;
				*( byte* )( params + 28 ) = Space;
				*( Rotator* )( params + 32 ) = CustomPlaySpace;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStopCameraAnim( class CameraAnim* AnimToStop )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientStopCameraAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class CameraAnim** )params = AnimToStop;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayCameraAnim( class UTSeqAct_PlayCameraAnim* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnPlayCameraAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_PlayCameraAnim** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStopCameraAnim( class UTSeqAct_StopCameraAnim* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnStopCameraAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_StopCameraAnim** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewShake( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ViewShake" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleMelee(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ToggleMelee" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleTranslocator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ToggleTranslocator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CallServerMove( class SavedMove* NewMove, Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CallServerMove" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( class SavedMove** )params = NewMove;
				*( Vector* )( params + 4 ) = ClientLoc;
				*( byte* )( params + 16 ) = ClientRoll;
				*( int* )( params + 20 ) = View;
				*( class SavedMove** )( params + 24 ) = OldMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShortServerMove( float TimeStamp, Vector ClientLoc, byte NewFlags, byte ClientRoll, int View )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ShortServerMove" );
				byte *params = ( byte* )( malloc( 22 ) );
				*( float* )params = TimeStamp;
				*( Vector* )( params + 4 ) = ClientLoc;
				*( byte* )( params + 16 ) = NewFlags;
				*( byte* )( params + 17 ) = ClientRoll;
				*( int* )( params + 20 ) = View;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LongClientAdjustPosition( float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.LongClientAdjustPosition" );
				byte *params = ( byte* )( malloc( 53 ) );
				*( float* )params = TimeStamp;
				*( ScriptName* )( params + 4 ) = NewState;
				*( byte* )( params + 12 ) = newPhysics;
				*( float* )( params + 16 ) = NewLocX;
				*( float* )( params + 20 ) = NewLocY;
				*( float* )( params + 24 ) = NewLocZ;
				*( float* )( params + 28 ) = NewVelX;
				*( float* )( params + 32 ) = NewVelY;
				*( float* )( params + 36 ) = NewVelZ;
				*( class Actor** )( params + 40 ) = NewBase;
				*( float* )( params + 44 ) = NewFloorX;
				*( float* )( params + 48 ) = NewFloorY;
				*( float* )( params + 52 ) = NewFloorZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bCameraOutOfWorld, 0x20 )
			void ViewNextBot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ViewNextBot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchWeapon( byte T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SwitchWeapon" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewSelf( void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerViewSelf" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )params = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewPlayerByName( ScriptArray< wchar_t > PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ViewPlayerByName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewPlayerByName( ScriptArray< wchar_t > PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerViewPlayerByName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::StrProperty, MsgPlayerNotFound, 0xFFFFFFFF )
			void ViewObjective(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ViewObjective" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewObjective(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerViewObjective" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PrevWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PrevWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NextWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.NextWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustCameraScale( bool bIn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdjustCameraScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanCommunicate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CanCommunicate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bServerMutedText, 0x800000 )
			void ShowMidGameMenu( ScriptName TabTag, bool bEnableInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ShowMidGameMenu" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TabTag;
				*( bool* )( params + 8 ) = bEnableInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientGameEnded( class Actor* EndGameFocus, bool bIsWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientGameEnded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = EndGameFocus;
				*( bool* )( params + 4 ) = bIsWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RoundHasEnded( class Actor* EndRoundFocus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.RoundHasEnded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = EndRoundFocus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRoundEnded( class Actor* EndRoundFocus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientRoundEnded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = EndRoundFocus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckBulletWhip( class SoundCue* BulletWhip, Vector FireLocation, Vector FireDir, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CheckBulletWhip" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class SoundCue** )params = BulletWhip;
				*( Vector* )( params + 4 ) = FireLocation;
				*( Vector* )( params + 16 ) = FireDir;
				*( Vector* )( params + 28 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnDied( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.PawnDied" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPawnDied(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientPawnDied" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePropertyFOVAngle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnUpdatePropertyFOVAngle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustFOV( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdjustFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bNonlinearZoomInterpolation, 0x10000 )
			ADD_VAR( ::FloatProperty, FOVNonlinearZoomInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FOVLinearZoomRate, 0xFFFFFFFF )
			void StartZoom( float NewDesiredFOV, float NewZoomRate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.StartZoom" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = NewDesiredFOV;
				*( float* )( params + 4 ) = NewZoomRate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartZoomNonlinear( float NewDesiredFOV, float NewZoomInterpSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.StartZoomNonlinear" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = NewDesiredFOV;
				*( float* )( params + 4 ) = NewZoomInterpSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.StopZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.EndZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndZoomNonlinear( float ZoomInterpSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.EndZoomNonlinear" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = ZoomInterpSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientEndZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ClientEndZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateRotation( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.UpdateRotation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CharacterProcessingComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CharacterProcessingComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanRestartPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.CanRestartPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SendMessage( class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.SendMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerReplicationInfo** )params = Recipient;
				*( ScriptName* )( params + 4 ) = MessageType;
				*( float* )( params + 12 ) = Wait;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveBotVoiceMessage( class UTPlayerReplicationInfo* SenderPRI, int MessageIndex, class Object* LocationObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ReceiveBotVoiceMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTPlayerReplicationInfo** )params = SenderPRI;
				*( int* )( params + 4 ) = MessageIndex;
				*( class Object** )( params + 8 ) = LocationObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetNetSpeed( int NewSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerSetNetSpeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NewSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BullseyeMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.BullseyeMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastBullseyeTime, 0xFFFFFFFF )
			void ServerChangeTeam( int N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerChangeTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastTeamChangeTime, 0xFFFFFFFF )
			void GetSeamlessTravelActorList( bool bToEntry )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.GetSeamlessTravelActorList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bToEntry;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerKickBan( ScriptArray< wchar_t > PlayerToKick, bool bBan )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerKickBan" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = PlayerToKick;
				*( bool* )( params + 12 ) = bBan;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowTTSMessageFrom( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AllowTTSMessageFrom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bNoTextToSpeechVoiceMessages, 0x400 )
			ADD_VAR( ::BoolProperty, bTextToSpeechTeamMessagesOnly, 0x800 )
			void ServerSay( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerSay" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerTeamSay( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerTeamSay" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowTextMessage( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AllowTextMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AdminCmdOk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminCmdOk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, NextAdminCmdTime, 0xFFFFFFFF )
			void AdminLogin( ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminLogin" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerAdminLogin( ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerAdminLogin" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminLogout(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminLogout" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerAdminLogOut(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerAdminLogOut" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Admin( ScriptArray< wchar_t > CommandLine )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Admin" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = CommandLine;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerAdmin( ScriptArray< wchar_t > CommandLine )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerAdmin" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = CommandLine;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminKickBan( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminKickBan" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminKick( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminKick" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminPlayerList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminPlayerList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminRestartMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminRestartMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRestartMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerRestartMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminChangeMap( ScriptArray< wchar_t > URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminChangeMap" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerChangeMap( ScriptArray< wchar_t > URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerChangeMap" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminForceVoiceMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminForceVoiceMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerForceVoiceMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerForceVoiceMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminForceVoiceUnMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminForceVoiceUnMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerForceVoiceUnMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerForceVoiceUnMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminForceTextMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminForceTextMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerForceTextMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerForceTextMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminForceTextUnMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.AdminForceTextUnMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerForceTextUnMute( ScriptArray< wchar_t > TargetPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.ServerForceTextUnMute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TargetPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Disconnect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.Disconnect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnScoreChanged( class UTTeamInfo* T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerController.OnScoreChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTTeamInfo** )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bRotateMinimap, 0x10 )
			ADD_VAR( ::BoolProperty, bFirstPersonWeaponsSelfShadow, 0x40 )
			ADD_VAR( ::BoolProperty, bForceBehindView, 0x100 )
			ADD_VAR( ::BoolProperty, bNoCrosshair, 0x100000 )
			ADD_VAR( ::BoolProperty, bSimpleCrosshair, 0x200000 )
			ADD_VAR( ::BoolProperty, bHideObjectivePaths, 0x1000000 )
			ADD_STRUCT( ::VectorProperty, DesiredLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomRotationModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldMessageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastFriendlyFireTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastIncomingMessageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastCombatUpdateTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
