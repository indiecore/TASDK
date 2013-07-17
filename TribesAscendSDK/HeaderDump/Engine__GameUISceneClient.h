#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameUISceneClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameUISceneClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameUISceneClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameUISceneClient : public UISceneClient
	{
	public:
			ADD_VAR( ::BoolProperty, bCaptureUnprocessedInput, 0x10 )
			ADD_VAR( ::BoolProperty, bRenderDebugInfo, 0x8 )
			ADD_VAR( ::BoolProperty, bEnableDebugInput, 0x4 )
			ADD_VAR( ::BoolProperty, bUpdateSceneViewportSizes, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdateInputProcessingStatus, 0x1 )
			ADD_VAR( ::FloatProperty, LatestDeltaTime, 0xFFFFFFFF )
			byte GetCurrentNetMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.GetCurrentNetMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void RequestInputProcessingUpdate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.RequestInputProcessingUpdate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanUnpauseInternalUI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.CanUnpauseInternalUI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PauseGame( bool bDesiredPauseState, int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.PauseGame" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bDesiredPauseState;
				*( int* )( params + 4 ) = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyClientTravel( class PlayerController* TravellingPlayer, ScriptArray< wchar_t > TravelURL, byte TravelType, bool bIsSeamlessTravel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.NotifyClientTravel" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( class PlayerController** )( params + 0 ) = TravellingPlayer;
				*( ScriptArray< wchar_t >* )( params + 4 ) = TravelURL;
				*( byte* )( params + 16 ) = TravelType;
				*( bool* )( params + 20 ) = bIsSeamlessTravel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyGameSessionEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.NotifyGameSessionEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPlayerAdded( int PlayerIndex, class LocalPlayer* AddedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.NotifyPlayerAdded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = AddedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPlayerRemoved( int PlayerIndex, class LocalPlayer* RemovedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.NotifyPlayerRemoved" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = RemovedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindLocalPlayerIndex( class Player* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameUISceneClient.FindLocalPlayerIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Player** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
