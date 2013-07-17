#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeamAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeamAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeamAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeamAI : public UDKTeamOwnedInfo
	{
	public:
			class UTSquadAI* FindHumanSquad(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.FindHumanSquad" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTSquadAI** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTTeamInfo, EnemyTeam )
			ADD_OBJECT( UTGameObjective, Objectives )
			class UTGameObjective* GetPriorityAttackObjectiveFor( class UTSquadAI* InAttackSquad, class Controller* InController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.GetPriorityAttackObjectiveFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTSquadAI** )( params + 0 ) = InAttackSquad;
				*( class Controller** )( params + 4 ) = InController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGameObjective** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTSquadAI, Squads )
			ADD_VAR( ::BoolProperty, bFoundSuperItems, 0x1 )
			ADD_VAR( ::IntProperty, NumSuperPickups, 0xFFFFFFFF )
			ADD_OBJECT( UTPickupFactory, SuperPickups )
			bool FriendlyToward( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.FriendlyToward" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::NameProperty, OrderList, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OrderOffset, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, SquadType )
			ADD_OBJECT( UTSquadAI, FreelanceSquad )
			ADD_OBJECT( UTSquadAI, AttackSquad )
			ADD_OBJECT( UTGameObjective, PickedStandaloneObjective )
			ADD_OBJECT( UTGameObjective, PickedObjective )
			ADD_VAR( ::IntProperty, NumSupportingPlayer, 0xFFFFFFFF )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CriticalObjectiveWarning( class UTGameObjective* G, class Pawn* NewEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.CriticalObjectiveWarning" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTGameObjective** )( params + 0 ) = G;
				*( class Pawn** )( params + 4 ) = NewEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindSuperItems(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.FindSuperItems" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReAssessStrategy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.ReAssessStrategy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyKilled( class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.NotifyKilled" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Killed;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindNewObjectives( class UTGameObjective* DisabledObjective )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.FindNewObjectives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTGameObjective** )( params + 0 ) = DisabledObjective;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindNewObjectiveFor( class UTSquadAI* S, bool bForceUpdate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.FindNewObjectiveFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTSquadAI** )( params + 0 ) = S;
				*( bool* )( params + 4 ) = bForceUpdate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveSquad( class UTSquadAI* Squad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.RemoveSquad" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSquadAI** )( params + 0 ) = Squad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetObjectiveLists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.SetObjectiveLists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTSquadAI* AddHumanSquad(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.AddHumanSquad" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTSquadAI** )( params + function->return_val_offset() );
			}

			void PutBotOnSquadLedBy( class Controller* C, class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.PutBotOnSquadLedBy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = C;
				*( class UTBot** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTSquadAI* AddSquadWithLeader( class Controller* C, class UTGameObjective* O )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.AddSquadWithLeader" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = C;
				*( class UTGameObjective** )( params + 4 ) = O;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTSquadAI** )( params + function->return_val_offset() );
			}

			class UTGameObjective* GetLeastDefendedObjective( class Controller* InController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.GetLeastDefendedObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = InController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGameObjective** )( params + function->return_val_offset() );
			}

			class UTGameObjective* GetPriorityStandaloneObjectiveFor( class UTSquadAI* InAttackSquad, class Controller* InController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.GetPriorityStandaloneObjectiveFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTSquadAI** )( params + 0 ) = InAttackSquad;
				*( class Controller** )( params + 4 ) = InController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGameObjective** )( params + function->return_val_offset() );
			}

			class UTGameObjective* GetPriorityFreelanceObjectiveFor( class UTSquadAI* InFreelanceSquad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.GetPriorityFreelanceObjectiveFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSquadAI** )( params + 0 ) = InFreelanceSquad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGameObjective** )( params + function->return_val_offset() );
			}

			bool PutOnDefense( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.PutOnDefense" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PutOnOffense( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.PutOnOffense" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PutOnFreelance( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.PutOnFreelance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBotOrders( class UTBot* NewBot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.SetBotOrders" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = NewBot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOrders( class UTBot* B, ScriptName NewOrders, class Controller* OrderGiver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.SetOrders" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( ScriptName* )( params + 4 ) = NewOrders;
				*( class Controller** )( params + 12 ) = OrderGiver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveFromTeam( class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamAI.RemoveFromTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
