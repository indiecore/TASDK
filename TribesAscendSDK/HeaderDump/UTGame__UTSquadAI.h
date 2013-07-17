#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTSquadAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTSquadAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTSquadAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSquadAI : public UDKSquadAI
	{
	public:
			bool AllowContinueOnFoot( class UTBot* B, class UTVehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AllowContinueOnFoot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class UTVehicle** )( params + 4 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowImpactJumpBy( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AllowImpactJumpBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Controller, SquadLeader )
			ScriptName GetOrders(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetOrders" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool SetEnemy( class UTBot* B, class Pawn* NewEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.SetEnemy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Pawn** )( params + 4 ) = NewEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AssignSquadResponsibility( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AssignSquadResponsibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTBot, SquadMembers )
			bool FindNewEnemyFor( class UTBot* B, bool bSeeEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.FindNewEnemyFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( bool* )( params + 4 ) = bSeeEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MustKeepEnemy( class Pawn* E )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.MustKeepEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = E;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsDefending( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.IsDefending" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasOtherVisibleEnemy( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.HasOtherVisibleEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte PriorityObjective( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.PriorityObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool AllowDetourTo( class UTBot* B, class NavigationPoint* N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AllowDetourTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class NavigationPoint** )( params + 4 ) = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Actor* SetFacingActor( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.SetFacingActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			class Actor* FormationCenter( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.FormationCenter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool AcceptableDefensivePosition( class NavigationPoint* N, class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AcceptableDefensivePosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationPoint** )( params + 0 ) = N;
				*( class UTBot** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class NavigationPoint* FindDefensivePositionFor( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.FindDefensivePositionFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, FormationSize, 0xFFFFFFFF )
			bool ClearPathFor( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ClearPathFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LostEnemy( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.LostEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PickRetreatDestination( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.PickRetreatDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BeDevious( class Pawn* Enemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.BeDevious" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Enemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldSuppressEnemy( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ShouldSuppressEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float VehicleDesireability( class UTVehicle* V, class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.VehicleDesireability" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTVehicle** )( params + 0 ) = V;
				*( class UTBot** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool HandlePathObstruction( class UTBot* B, class Actor* BlockedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.HandlePathObstruction" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Actor** )( params + 4 ) = BlockedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindPathToObjective( class UTBot* B, class Actor* O )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.FindPathToObjective" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Actor** )( params + 4 ) = O;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetSize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetSize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bShouldUseGatherPoints, 0x20 )
			ADD_VAR( ::BoolProperty, bAddTransientCosts, 0x10 )
			ADD_VAR( ::BoolProperty, bRoamingSquad, 0x8 )
			ADD_VAR( ::BoolProperty, bFreelanceDefend, 0x4 )
			ADD_VAR( ::BoolProperty, bFreelanceAttack, 0x2 )
			ADD_VAR( ::BoolProperty, bFreelance, 0x1 )
			ADD_VAR( ::IntProperty, MaxSquadSize, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, Enemies )
			ADD_VAR( ::NameProperty, CurrentOrders, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SupportStringTrailer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FreelanceString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HoldString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AttackString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefendString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SupportString, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Size, 0xFFFFFFFF )
			ADD_OBJECT( UTSquadAI, NextSquad )
			ADD_OBJECT( UTPlayerReplicationInfo, LeaderPRI )
			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CriticalObjectiveWarning( class Pawn* NewEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.CriticalObjectiveWarning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = NewEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTVehicle* GetLinkVehicle( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetLinkVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTVehicle** )( params + function->return_val_offset() );
			}

			Rotator GetFacingRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetFacingRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool AddEnemy( class Pawn* NewEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AddEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = NewEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ValidEnemy( class Pawn* NewEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ValidEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = NewEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsOnSquad( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.IsOnSquad" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RemoveEnemy( class Pawn* E )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.RemoveEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = E;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyKilled( class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.NotifyKilled" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Killed;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float ModifyThreat( float Current, class Pawn* NewThreat, bool bThreatVisible, class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ModifyThreat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = Current;
				*( class Pawn** )( params + 4 ) = NewThreat;
				*( bool* )( params + 8 ) = bThreatVisible;
				*( class UTBot** )( params + 12 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool UnderFire( class Pawn* NewThreat, class UTBot* Ignored )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.UnderFire" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = NewThreat;
				*( class UTBot** )( params + 4 ) = Ignored;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float AssessThreat( class UTBot* B, class Pawn* NewThreat, bool bThreatVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AssessThreat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Pawn** )( params + 4 ) = NewThreat;
				*( bool* )( params + 8 ) = bThreatVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool ShouldDeferTo( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ShouldDeferTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WaitAtThisPosition( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.WaitAtThisPosition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WanderNearLeader( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.WanderNearLeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NearFormationCenter( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.NearFormationCenter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CloseToLeader( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.CloseToLeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void MergeWith( class UTSquadAI* S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.MergeWith" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSquadAI** )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Initialize( class UTTeamInfo* T, class UTGameObjective* O, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.Initialize" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTTeamInfo** )( params + 0 ) = T;
				*( class UTGameObjective** )( params + 4 ) = O;
				*( class Controller** )( params + 8 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldUseAlternatePaths(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ShouldUseAlternatePaths" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetAlternatePathTo( class NavigationPoint* NewRouteObjective, class UTBot* RouteMaker )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.SetAlternatePathTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationPoint** )( params + 0 ) = NewRouteObjective;
				*( class UTBot** )( params + 4 ) = RouteMaker;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TryToIntercept( class UTBot* B, class Pawn* P, class Actor* RouteGoal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.TryToIntercept" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Pawn** )( params + 4 ) = P;
				*( class Actor** )( params + 8 ) = RouteGoal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CloseEnoughToObjective( class UTBot* B, class Actor* O )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.CloseEnoughToObjective" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Actor** )( params + 4 ) = O;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LeaveVehicleToReachObjective( class UTBot* B, class Actor* O )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.LeaveVehicleToReachObjective" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Actor** )( params + 4 ) = O;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MustCompleteOnFoot( class Actor* O, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.MustCompleteOnFoot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = O;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void LeaveVehicleAtParkingSpot( class UTBot* B, class Actor* O )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.LeaveVehicleAtParkingSpot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Actor** )( params + 4 ) = O;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLeader( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.SetLeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemovePlayer( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.RemovePlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveBot( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.RemoveBot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddBot( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AddBot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDefenseScriptFor( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.SetDefenseScriptFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetObjective( class UTGameObjective* O, bool bForceUpdate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.SetObjective" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTGameObjective** )( params + 0 ) = O;
				*( bool* )( params + 4 ) = bForceUpdate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Retask( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.Retask" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetOrderStringFor( class UTPlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetOrderStringFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetShortOrderStringFor( class UTPlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetShortOrderStringFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void PickNewLeader(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.PickNewLeader" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TellBotToFollow( class UTBot* B, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.TellBotToFollow" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowTaunt( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AllowTaunt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddTransientCosts( class UTBot* B, float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.AddTransientCosts" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( float* )( params + 4 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float MaxVehicleDist( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.MaxVehicleDist" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool NeverBail( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.NeverBail" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BotEnteredVehicle( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.BotEnteredVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsOnPathToSquadObjective( class Actor* Goal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.IsOnPathToSquadObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Goal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetOnHoverboard( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetOnHoverboard" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EnterAndExitVehicle( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.EnterAndExitVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GotoVehicle( class UTVehicle* SquadVehicle, class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GotoVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTVehicle** )( params + 0 ) = SquadVehicle;
				*( class UTBot** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckVehicle( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.CheckVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckHoverboard( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.CheckHoverboard" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldUseHoverboard( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ShouldUseHoverboard" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool OverrideFollowPlayer( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.OverrideFollowPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldCheckSuperVehicle( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ShouldCheckSuperVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckSuperItem( class UTBot* B, float SuperDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.CheckSuperItem" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( float* )( params + 4 ) = SuperDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckSquadObjectives( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.CheckSquadObjectives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float BotSuitability( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.BotSuitability" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class UTBot* PickBotToReassign(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.PickBotToReassign" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTBot** )( params + function->return_val_offset() );
			}

			void DisplayDebug( class HUD* HUD, float &YL, float &YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = YL;
				*( float* )( params + 8 ) = YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				YL = *( float* )( params + 4 );
				YPos = *( float* )( params + 8 );
			}

			bool FriendlyToward( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.FriendlyToward" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetMaxDefenseDistanceFrom( class Actor* Center, class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.GetMaxDefenseDistanceFrom" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = Center;
				*( class UTBot** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float RateDefensivePosition( class NavigationPoint* N, class UTBot* CurrentBot, class Actor* Center )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.RateDefensivePosition" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class NavigationPoint** )( params + 0 ) = N;
				*( class UTBot** )( params + 4 ) = CurrentBot;
				*( class Actor** )( params + 8 ) = Center;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void MarkHuntingSpots( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.MarkHuntingSpots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ModifyAggression( class UTBot* B, float &Aggression )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSquadAI.ModifyAggression" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( float* )( params + 4 ) = Aggression;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Aggression = *( float* )( params + 4 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
