#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTimedPowerup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTimedPowerup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTimedPowerup." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTimedPowerup : public UTInventory
	{
	public:
			ADD_VAR( ::FloatProperty, PP_Scene_Desaturation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PP_Scene_HighLights, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WarningTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransitionDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransitionTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PowerupStatName, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, PowerupOverSound )
			ADD_VAR( ::IntProperty, HudIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeRemaining, 0xFFFFFFFF )
			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GivenTo( class Pawn* NewOwner, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.GivenTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = NewOwner;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientGivenTo( class Pawn* NewOwner, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.ClientGivenTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = NewOwner;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustPPEffects( class Pawn* P, bool bRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.AdjustPPEffects" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( bool* )( params + 4 ) = bRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientLostItem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.ClientLostItem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetTimeRemaining( float NewTimeRemaining )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.ClientSetTimeRemaining" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewTimeRemaining;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimeRemaingUpdated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.TimeRemaingUpdated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayPowerup( class Canvas* Canvas, class UTHUD* HUD, float ResolutionScale, float &YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.DisplayPowerup" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Canvas** )params = Canvas;
				*( class UTHUD** )( params + 4 ) = HUD;
				*( float* )( params + 8 ) = ResolutionScale;
				*( float* )( params + 12 ) = YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				YPos = *( float* )( params + 12 );
			}

			bool DenyPickupQuery( ScriptClass* ItemClass, class Actor* Pickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.DenyPickupQuery" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = ItemClass;
				*( class Actor** )( params + 4 ) = Pickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TimeExpired(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.TimeExpired" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float BotDesireability( class Actor* PickupHolder, class Pawn* P, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.BotDesireability" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )params = PickupHolder;
				*( class Pawn** )( params + 4 ) = P;
				*( class Controller** )( params + 8 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float DetourWeight( class Pawn* Other, float PathWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.DetourWeight" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = Other;
				*( float* )( params + 4 ) = PathWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptName GetPowerupStatName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTimedPowerup.GetPowerupStatName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
