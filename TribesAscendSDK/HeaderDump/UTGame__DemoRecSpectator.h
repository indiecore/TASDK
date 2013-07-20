#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.DemoRecSpectator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.DemoRecSpectator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.DemoRecSpectator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DemoRecSpectator : public UTPlayerController
	{
	public:
			ADD_VAR( ::FloatProperty, AutoSwitchPlayerInterval, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, MyRealViewTarget )
			ADD_VAR( ::BoolProperty, bAutoSwitchPlayers, 0x4 )
			ADD_VAR( ::BoolProperty, bLockRotationToViewTarget, 0x2 )
			ADD_VAR( ::BoolProperty, bFindPlayer, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceivedPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.ReceivedPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitPlayerReplicationInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.InitPlayerReplicationInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Slomo( float NewTimeDilation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.Slomo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewTimeDilation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewClass( ScriptClass* aClass, bool bQuiet, bool bCheat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.ViewClass" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptClass** )params = aClass;
				*( bool* )( params + 4 ) = bQuiet;
				*( bool* )( params + 8 ) = bCheat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DemoViewNextPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.DemoViewNextPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetViewTarget( class Actor* NewViewTarget, void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.SetViewTarget" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = NewViewTarget;
				*( void** )( params + 4 ) = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewSelf( void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.ServerViewSelf" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )params = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetRealViewTarget( class PlayerReplicationInfo* NewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.ClientSetRealViewTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = NewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetPause( bool bPause )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.SetPause" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bPause;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Pause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.Pause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPlayerViewPoint( Vector &CameraLocation, Rotator &CameraRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.GetPlayerViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = CameraLocation;
				*( Rotator* )( params + 12 ) = CameraRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CameraLocation = *( Vector* )params;
				CameraRotation = *( Rotator* )( params + 12 );
			}

			void UpdateRotation( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.DemoRecSpectator.UpdateRotation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
