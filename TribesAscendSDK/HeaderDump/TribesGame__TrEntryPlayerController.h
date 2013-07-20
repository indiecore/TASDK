#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrEntryPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrEntryPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrEntryPlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrEntryPlayerController : public TrPlayerController
	{
	public:
			ADD_VAR( ::BoolProperty, bMenuNotified, 0x1 )
			ADD_VAR( ::FloatProperty, m_fCameraRotationInterpTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCameraRotationCurrTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rTargetCameraRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rInitialCameraRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_CameraLocation4x3, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_CameraLocation16x10, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_CameraLocation16x9, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_PreloadTextureTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_ContentDataType, 0xFFFFFFFF )
			ADD_OBJECT( TrPaperDollMainMenu, m_MainMenuPaperDoll )
			ADD_VAR( ::StrProperty, MainMenuContentClassName, 0xFFFFFFFF )
			ADD_OBJECT( TrMainMenuContentData, m_MainMenuContentData )
			ADD_OBJECT( LocalPlayer, OldPlayer )
			ADD_OBJECT( PostProcessChain, EntryPostProcessChain )
			ADD_VAR( ::IntProperty, MAX_RESEND_WAIT_TIME, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MIN_RESEND_WAIT_TIME, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_CountdownTime, 0xFFFFFFFF )
			bool RequestPaperDoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.RequestPaperDoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SendMenuToLobby(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.SendMenuToLobby" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResendReadyCheck(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ResendReadyCheck" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMenuTimer( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.UpdateMenuTimer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetWaitRemaining(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.GetWaitRemaining" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void NotifyMenuReady(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.NotifyMenuReady" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshFriends(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.RefreshFriends" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwapModel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.SwapModel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowPeach(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ShowPeach" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleMenuVisible(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ToggleMenuVisible" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPlayerViewPoint( Vector &POVLocation, Rotator &POVRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.GetPlayerViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = POVLocation;
				*( Rotator* )( params + 12 ) = POVRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				POVLocation = *( Vector* )params;
				POVRotation = *( Rotator* )( params + 12 );
			}

			void SwingCamera( float TargetPitch, float TargetYaw, float TargetRoll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.SwingCamera" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = TargetPitch;
				*( float* )( params + 4 ) = TargetYaw;
				*( float* )( params + 8 ) = TargetRoll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwingCameraBack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.SwingCameraBack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreloadTexturesTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.PreloadTexturesTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyMenuReadyTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.NotifyMenuReadyTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RequestPaperDollTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.RequestPaperDollTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginQueueResendTimer( int SecondsLeft )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.BeginQueueResendTimer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SecondsLeft;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearQueueResendTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ClearQueueResendTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadingTimer( bool bStart )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.LoadingTimer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bStart;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.InitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnControllerChanged( int ControllerId, bool bIsConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnControllerChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ControllerId;
				*( bool* )( params + 4 ) = bIsConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameInviteReceived( byte LocalUserNum, ScriptArray< wchar_t > RequestingNick )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnGameInviteReceived" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = RequestingNick;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendInviteReceived( byte LocalUserNum, void* RequestingPlayer, ScriptArray< wchar_t > RequestingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnFriendInviteReceived" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnFriendMessageReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = SendingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = SendingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnConnectionStatusChange( byte ConnectionStatus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnConnectionStatusChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = ConnectionStatus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLinkStatusChanged( bool bConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnLinkStatusChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QuitToMainMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.QuitToMainMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPawnConstructionScene( bool bShow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.SetPawnConstructionScene" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bShow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMidGameMenu( ScriptName TabTag, bool bEnableInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ShowMidGameMenu" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TabTag;
				*( bool* )( params + 8 ) = bEnableInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowScoreboard(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ShowScoreboard" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Pose( int PoseId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.Pose" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PoseId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Weap( int WeapId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.Weap" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = WeapId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Char( int CharID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.Char" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = CharID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePaperDoll_Device( ScriptClass* DeviceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.UpdatePaperDoll_Device" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DeviceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMainMenuPaperDoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ClearMainMenuPaperDoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMainMenuPaperDoll_Mesh( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.UpdateMainMenuPaperDoll_Mesh" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePaperDoll( ScriptClass* FamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.UpdatePaperDoll" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = FamilyInfoClass;
				*( ScriptClass** )( params + 4 ) = DeviceClass;
				*( ScriptClass** )( params + 8 ) = skinClass;
				*( int* )( params + 12 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDeviceContentDataClassLoaded( ScriptClass* DeviceContentDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnDeviceContentDataClassLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DeviceContentDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClassSelectedMainMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.OnClassSelectedMainMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void On3PSkinContentLoaded( ScriptClass* Skin3PDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.On3PSkinContentLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = Skin3PDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshFriendsTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.RefreshFriendsTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwapModelTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.SwapModelTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowPeachTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEntryPlayerController.ShowPeachTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
