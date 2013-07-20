#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Mutator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Mutator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Mutator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Mutator : public Info
	{
	public:
			ADD_OBJECT( Mutator, NextMutator )
			ADD_VAR( ::BoolProperty, bUserAdded, 0x1 )
			bool PreventDeath( class Pawn* Killed, class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.PreventDeath" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Pawn** )params = Killed;
				*( class Controller** )( params + 4 ) = Killer;
				*( ScriptClass** )( params + 8 ) = DamageType;
				*( Vector* )( params + 12 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckRelevance( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.CheckRelevance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool OverridePickupQuery( class Pawn* Other, ScriptClass* ItemClass, class Actor* Pickup, byte &bAllowPickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.OverridePickupQuery" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( class Pawn** )params = Other;
				*( ScriptClass** )( params + 4 ) = ItemClass;
				*( class Actor** )( params + 8 ) = Pickup;
				*( byte* )( params + 12 ) = bAllowPickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				bAllowPickup = *( byte* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HandleRestartGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.HandleRestartGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckEndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.CheckEndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )params = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class NavigationPoint* FindPlayerStart( class Controller* Player, byte InTeam, ScriptArray< wchar_t > IncomingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.FindPlayerStart" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Controller** )params = Player;
				*( byte* )( params + 4 ) = InTeam;
				*( ScriptArray< wchar_t >* )( params + 8 ) = IncomingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			bool CanLeaveVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.CanLeaveVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )params = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MutatorIsAllowed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.MutatorIsAllowed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Mutate( ScriptArray< wchar_t > MutateString, class PlayerController* Sender )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.Mutate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = MutateString;
				*( class PlayerController** )( params + 12 ) = Sender;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ModifyLogin( ScriptArray< wchar_t > &Portal, ScriptArray< wchar_t > &Options )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.ModifyLogin" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Portal;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Portal = *( ScriptArray< wchar_t >* )params;
				Options = *( ScriptArray< wchar_t >* )( params + 12 );
			}

			void ModifyPlayer( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.ModifyPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMutator( class Mutator* M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.AddMutator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Mutator** )params = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AlwaysKeep( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.AlwaysKeep" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsRelevant( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.IsRelevant" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckReplacement( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.CheckReplacement" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyLogout( class Controller* Exiting )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.NotifyLogout" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = Exiting;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyLogin( class Controller* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.NotifyLogin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverEnteredVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.DriverEnteredVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )params = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverLeftVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.DriverLeftVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )params = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitMutator( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.InitMutator" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 12 );
			}

			void GetSeamlessTravelActorList( bool bToEntry )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.GetSeamlessTravelActorList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bToEntry;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ScoreObjective( class PlayerReplicationInfo* Scorer, int Score )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.ScoreObjective" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )params = Scorer;
				*( int* )( params + 4 ) = Score;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ScoreKill( class Controller* Killer, class Controller* Killed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.ScoreKill" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Killed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NetDamage( int OriginalDamage, int &Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector &Momentum, ScriptClass* DamageType, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Mutator.NetDamage" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( int* )params = OriginalDamage;
				*( int* )( params + 4 ) = Damage;
				*( class Pawn** )( params + 8 ) = injured;
				*( class Controller** )( params + 12 ) = InstigatedBy;
				*( Vector* )( params + 16 ) = HitLocation;
				*( Vector* )( params + 28 ) = Momentum;
				*( ScriptClass** )( params + 40 ) = DamageType;
				*( class Actor** )( params + 44 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Damage = *( int* )( params + 4 );
				Momentum = *( Vector* )( params + 28 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
