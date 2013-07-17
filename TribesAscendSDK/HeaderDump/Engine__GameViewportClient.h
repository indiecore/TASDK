#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameViewportClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameViewportClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameViewportClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameViewportClient : public Object
	{
	public:
			ADD_OBJECT( Console, ViewportConsole )
			ADD_OBJECT( UIInteraction, UIController )
			ScriptArray< wchar_t > ConsoleCommand( ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.ConsoleCommand" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool HandleInputKey( int ControllerId, ScriptName Key, byte EventType, float AmountDepressed, bool bGamepad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.HandleInputKey" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( ScriptName* )( params + 4 ) = Key;
				*( byte* )( params + 12 ) = EventType;
				*( float* )( params + 16 ) = AmountDepressed;
				*( bool* )( params + 20 ) = bGamepad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HandleInputAxis( int ControllerId, ScriptName Key, float Delta, float DeltaTime, bool bGamepad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.HandleInputAxis" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( ScriptName* )( params + 4 ) = Key;
				*( float* )( params + 12 ) = Delta;
				*( float* )( params + 16 ) = DeltaTime;
				*( bool* )( params + 20 ) = bGamepad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HandleInputChar( int ControllerId, ScriptArray< wchar_t > Unicode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.HandleInputChar" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Unicode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetViewportSize( void* &out_ViewportSize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GetViewportSize" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = out_ViewportSize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewportSize = *( void** )( params + 0 );
			}

			bool IsFullScreenViewport(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.IsFullScreenViewport" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldForceFullscreenViewport(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.ShouldForceFullscreenViewport" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetNumCustomInteractions(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GetNumCustomInteractions" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptClass* GetCustomInteractionClass( int InIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GetCustomInteractionClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = InIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void SetCustomInteractionObject( class Interaction* InInteraction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.SetCustomInteractionObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Interaction** )( params + 0 ) = InInteraction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class LocalPlayer* CreatePlayer( int ControllerId, ScriptArray< wchar_t > &OutError, bool bSpawnActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.CreatePlayer" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = OutError;
				*( bool* )( params + 16 ) = bSpawnActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutError = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( class LocalPlayer** )( params + function->return_val_offset() );
			}

			int AddLocalPlayer( class LocalPlayer* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.AddLocalPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int RemoveLocalPlayer( class LocalPlayer* ExistingPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.RemoveLocalPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = ExistingPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void NotifyPlayerAdded( int PlayerIndex, class LocalPlayer* AddedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.NotifyPlayerAdded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = AddedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RemovePlayer( class LocalPlayer* ExPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.RemovePlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = ExPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyPlayerRemoved( int PlayerIndex, class LocalPlayer* RemovedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.NotifyPlayerRemoved" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = RemovedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class LocalPlayer* FindPlayerByControllerId( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.FindPlayerByControllerId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class LocalPlayer** )( params + function->return_val_offset() );
			}

			bool CreateViewportConsole( ScriptClass* vpcClass, ScriptArray< wchar_t > &OutError )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.CreateViewportConsole" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = vpcClass;
				*( ScriptArray< wchar_t >* )( params + 4 ) = OutError;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutError = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Init( ScriptArray< wchar_t > &OutError )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.Init" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = OutError;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutError = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, ActiveSplitscreenType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DesiredSplitscreenType, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, UIControllerClass )
			ADD_VAR( ::BoolProperty, bDebugNoGFxUI, 0x80 )
			bool CreateInitialPlayer( ScriptArray< wchar_t > &OutError )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.CreateInitialPlayer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = OutError;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutError = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			int InsertInteraction( class Interaction* NewInteraction, int InIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.InsertInteraction" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Interaction** )( params + 0 ) = NewInteraction;
				*( int* )( params + 4 ) = InIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void GameSessionEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GameSessionEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSplitscreenConfiguration( byte SplitType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.SetSplitscreenConfiguration" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = SplitType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetSplitscreenConfiguration(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GetSplitscreenConfiguration" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void UpdateActiveSplitscreenType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.UpdateActiveSplitscreenType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, Default2PSplitType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Default3PSplitType, 0xFFFFFFFF )
			void LayoutPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.LayoutPlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetSubtitleRegion( void* &MinPos, void* &MaxPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GetSubtitleRegion" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = MinPos;
				*( void** )( params + 8 ) = MaxPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MinPos = *( void** )( params + 0 );
				MaxPos = *( void** )( params + 8 );
			}

			int ConvertLocalPlayerToGamePlayerIndex( class LocalPlayer* LPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.ConvertLocalPlayerToGamePlayerIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = LPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool HasTopSafeZone( int LocalPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.HasTopSafeZone" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = LocalPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasBottomSafeZone( int LocalPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.HasBottomSafeZone" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = LocalPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasLeftSafeZone( int LocalPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.HasLeftSafeZone" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = LocalPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasRightSafeZone( int LocalPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.HasRightSafeZone" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = LocalPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetPixelSizeOfScreen( float &out_Width, float &out_Height, class Canvas* Canvas, int LocalPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GetPixelSizeOfScreen" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = out_Width;
				*( float* )( params + 4 ) = out_Height;
				*( class Canvas** )( params + 8 ) = Canvas;
				*( int* )( params + 12 ) = LocalPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Width = *( float* )( params + 0 );
				out_Height = *( float* )( params + 4 );
			}

			void CalculateSafeZoneValues( float &out_Horizontal, float &out_Vertical, class Canvas* Canvas, int LocalPlayerIndex, bool bUseMaxPercent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.CalculateSafeZoneValues" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )( params + 0 ) = out_Horizontal;
				*( float* )( params + 4 ) = out_Vertical;
				*( class Canvas** )( params + 8 ) = Canvas;
				*( int* )( params + 12 ) = LocalPlayerIndex;
				*( bool* )( params + 16 ) = bUseMaxPercent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Horizontal = *( float* )( params + 0 );
				out_Vertical = *( float* )( params + 4 );
			}

			bool CalculateDeadZoneForAllSides( class LocalPlayer* LPlayer, class Canvas* Canvas, float &fTopSafeZone, float &fBottomSafeZone, float &fLeftSafeZone, float &fRightSafeZone, bool bUseMaxPercent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.CalculateDeadZoneForAllSides" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class LocalPlayer** )( params + 0 ) = LPlayer;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( float* )( params + 8 ) = fTopSafeZone;
				*( float* )( params + 12 ) = fBottomSafeZone;
				*( float* )( params + 16 ) = fLeftSafeZone;
				*( float* )( params + 20 ) = fRightSafeZone;
				*( bool* )( params + 24 ) = bUseMaxPercent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				fTopSafeZone = *( float* )( params + 8 );
				fBottomSafeZone = *( float* )( params + 12 );
				fLeftSafeZone = *( float* )( params + 16 );
				fRightSafeZone = *( float* )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTitleSafeArea( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.DrawTitleSafeArea" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRender( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.PostRender" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bShowTitleSafeZone, 0x1 )
			void DisplayProgressMessage( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.DisplayProgressMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, ProgressTimeOut, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ProgressFadeTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ProgressMessage, 0xFFFFFFFF )
			void DrawTransition( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.DrawTransition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::StrProperty, LoadingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SavingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ConnectingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PrecachingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PausedMessage, 0xFFFFFFFF )
			void DrawTransitionMessage( class Canvas* Canvas, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.DrawTransitionMessage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetProgressMessage( byte MessageType, ScriptArray< wchar_t > Message, ScriptArray< wchar_t > Title, bool bIgnoreFutureNetworkMessages )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.SetProgressMessage" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )( params + 0 ) = MessageType;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Message;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Title;
				*( bool* )( params + 28 ) = bIgnoreFutureNetworkMessages;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyConnectionError( ScriptArray< wchar_t > Message, ScriptArray< wchar_t > Title )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.NotifyConnectionError" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Message;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Title;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetProgressTime( float T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.SetProgressTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearProgressMessages(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.ClearProgressMessages" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class LocalPlayer* GetPlayerOwner( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.GetPlayerOwner" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class LocalPlayer** )( params + function->return_val_offset() );
			}

			void FixupOwnerReferences(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.FixupOwnerReferences" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPrimaryPlayerSwitch( class LocalPlayer* OldPrimaryPlayer, class LocalPlayer* NewPrimaryPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.OnPrimaryPlayerSwitch" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class LocalPlayer** )( params + 0 ) = OldPrimaryPlayer;
				*( class LocalPlayer** )( params + 4 ) = NewPrimaryPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BecomePrimaryPlayer( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.BecomePrimaryPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DebugSetUISystemEnabled( bool bOldUISystemActive, bool bGFxUISystemActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameViewportClient.DebugSetUISystemEnabled" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bOldUISystemActive;
				*( bool* )( params + 4 ) = bGFxUISystemActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bDisplayingUIMouseCursor, 0x2 )
			ADD_VAR( ::BoolProperty, bUIMouseCaptureOverride, 0x4 )
			ADD_VAR( ::BoolProperty, bOverrideDiffuseAndSpecular, 0x8 )
			ADD_VAR( ::BoolProperty, bIsPlayInEditorViewport, 0x10 )
			ADD_VAR( ::BoolProperty, bShowSystemMouseCursor, 0x20 )
			ADD_VAR( ::BoolProperty, bDisableWorldRendering, 0x40 )
			ADD_VAR( ::BoolProperty, bUseHardwareCursorWhenWindowed, 0x100 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
