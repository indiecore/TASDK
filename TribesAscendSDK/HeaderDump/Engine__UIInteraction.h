#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIInteraction." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIInteraction." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIInteraction." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIInteraction : public Interaction
	{
	public:
			class DataStoreClient* GetDataStoreClient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetDataStoreClient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class DataStoreClient** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( GameUISceneClient, SceneClient )
			bool IsLoggedIn( int ControllerId, bool bRequireOnlineLogin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.IsLoggedIn" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ControllerId;
				*( bool* )( params + 4 ) = bRequireOnlineLogin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsGamepadConnected( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.IsGamepadConnected" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetPlayerCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetPlayerCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, DoubleClickPixelTolerance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleClickTriggerSeconds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MouseButtonRepeatDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AxisRepeatDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UIAxisMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UIJoystickDeadZone, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bProcessInput, 0x1 )
			ADD_OBJECT( DataStoreClient, DataStoreManager )
			ADD_OBJECT( ScriptClass, SceneClientClass )
			ADD_OBJECT( ScriptClass, UIManagerClass )
			ADD_OBJECT( UIManager, UIManager )
			int GetPlayerIndex( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetPlayerIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetPlayerControllerId( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetPlayerControllerId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class LocalPlayer* GetLocalPlayer( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetLocalPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class LocalPlayer** )( params + function->return_val_offset() );
			}

			void NotifyPlayerAdded( int PlayerIndex, class LocalPlayer* AddedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.NotifyPlayerAdded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = AddedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPlayerRemoved( int PlayerIndex, class LocalPlayer* RemovedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.NotifyPlayerRemoved" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = RemovedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetLoginStatus( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetLoginStatus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte GetLowestLoginStatusOfControllers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetLowestLoginStatusOfControllers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool HasLinkConnection(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.HasLinkConnection" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetLoggedInPlayerCount( bool bRequireOnlineLogin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetLoggedInPlayerCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bRequireOnlineLogin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetNumGuestsLoggedIn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetNumGuestsLoggedIn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetConnectedGamepadCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetConnectedGamepadCount" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			byte GetNATType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.GetNATType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void NotifyGameSessionEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIInteraction.NotifyGameSessionEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
