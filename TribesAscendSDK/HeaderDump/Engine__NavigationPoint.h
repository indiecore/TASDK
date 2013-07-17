#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavigationPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavigationPoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavigationPoint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavigationPoint : public Actor
	{
	public:
			bool ProceedWithMove( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.ProceedWithMove" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, LastAnchoredPawnTime, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, AnchoredPawn )
			ADD_VAR( ::IntProperty, NetworkID, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDetourWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InventoryDist, 0xFFFFFFFF )
			ADD_OBJECT( DroppedPickup, InventoryCache )
			ADD_VAR( ::IntProperty, FearCost, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TransientCost, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ExtraCost, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Cost, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, previousPath )
			ADD_OBJECT( NavigationPoint, prevOrdered )
			ADD_OBJECT( NavigationPoint, nextOrdered )
			ADD_OBJECT( NavigationPoint, nextNavigationPoint )
			ADD_VAR( ::IntProperty, bestPathWeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, visitedWeight, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShouldSaveForCheckpoint, 0x40000000 )
			ADD_VAR( ::BoolProperty, bHasCrossLevelPaths, 0x20000000 )
			ADD_VAR( ::BoolProperty, bPreferredVehiclePath, 0x10000000 )
			ADD_VAR( ::BoolProperty, bBlockedForVehicles, 0x8000000 )
			ADD_VAR( ::BoolProperty, bBuildLongPaths, 0x4000000 )
			ADD_VAR( ::BoolProperty, bCanWalkOnToReach, 0x2000000 )
			ADD_VAR( ::BoolProperty, bMustTouchToReach, 0x1000000 )
			ADD_VAR( ::BoolProperty, bMakeSourceOnly, 0x800000 )
			ADD_VAR( ::BoolProperty, bVehicleDestination, 0x400000 )
			ADD_VAR( ::BoolProperty, bAlreadyVisited, 0x200000 )
			ADD_VAR( ::BoolProperty, bMayCausePain, 0x100000 )
			ADD_VAR( ::BoolProperty, bFlyingPreferred, 0x80000 )
			ADD_VAR( ::BoolProperty, bBlockable, 0x40000 )
			ADD_VAR( ::BoolProperty, bMustBeReachable, 0x20000 )
			ADD_VAR( ::BoolProperty, bSpecialForced, 0x10000 )
			ADD_VAR( ::BoolProperty, bSourceOnly, 0x8000 )
			ADD_VAR( ::BoolProperty, bDestinationOnly, 0x4000 )
			ADD_VAR( ::BoolProperty, bPathsChanged, 0x2000 )
			ADD_VAR( ::BoolProperty, bNotBased, 0x1000 )
			ADD_VAR( ::BoolProperty, bNoAutoConnect, 0x800 )
			ADD_VAR( ::BoolProperty, bSpecialMove, 0x400 )
			ADD_VAR( ::BoolProperty, bAutoBuilt, 0x200 )
			ADD_VAR( ::BoolProperty, bForceNoStrafing, 0x100 )
			ADD_VAR( ::BoolProperty, bAlwaysUseStrafing, 0x80 )
			ADD_VAR( ::BoolProperty, bNeverUseStrafing, 0x40 )
			ADD_VAR( ::BoolProperty, bOneWayPath, 0x20 )
			ADD_VAR( ::BoolProperty, bBlocked, 0x10 )
			ADD_VAR( ::BoolProperty, bCanReach, 0x8 )
			ADD_VAR( ::BoolProperty, bHideEditorPaths, 0x4 )
			ADD_VAR( ::BoolProperty, bTransientEndPoint, 0x2 )
			ADD_VAR( ::BoolProperty, bEndPoint, 0x1 )
			void GetBoundingCylinder( float &CollisionRadius, float &CollisionHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.GetBoundingCylinder" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = CollisionRadius;
				*( float* )( params + 4 ) = CollisionHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CollisionRadius = *( float* )( params + 0 );
				CollisionHeight = *( float* )( params + 4 );
			}

			class ReachSpec* GetReachSpecTo( class NavigationPoint* Nav, ScriptClass* SpecClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.GetReachSpecTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationPoint** )( params + 0 ) = Nav;
				*( ScriptClass** )( params + 4 ) = SpecClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ReachSpec** )( params + function->return_val_offset() );
			}

			bool IsUsableAnchorFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.IsUsableAnchorFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanTeleport( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.CanTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int SpecialCost( class Pawn* Seeker, class ReachSpec* Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.SpecialCost" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = Seeker;
				*( class ReachSpec** )( params + 4 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool Accept( class Actor* Incoming, class Actor* Source )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.Accept" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = Incoming;
				*( class Actor** )( params + 4 ) = Source;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float DetourWeight( class Pawn* Other, float PathWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.DetourWeight" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = Other;
				*( float* )( params + 4 ) = PathWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool SuggestMovePreparation( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.SuggestMovePreparation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class NavigationPoint* GetNearestNavToActor( class Actor* ChkActor, ScriptClass* RequiredClass, float MinDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.GetNearestNavToActor" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Actor** )( params + 0 ) = ChkActor;
				*( ScriptClass** )( params + 4 ) = RequiredClass;
				*( float* )( params + 20 ) = MinDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			class NavigationPoint* GetNearestNavToPoint( class Actor* ChkActor, Vector ChkPoint, ScriptClass* RequiredClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.GetNearestNavToPoint" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = ChkActor;
				*( Vector* )( params + 4 ) = ChkPoint;
				*( ScriptClass** )( params + 16 ) = RequiredClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			bool GetAllNavInRadius( class Actor* ChkActor, Vector ChkPoint, float Radius, bool bSkipBlocked, int inNetworkID, void* MinSize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.GetAllNavInRadius" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class Actor** )( params + 0 ) = ChkActor;
				*( Vector* )( params + 4 ) = ChkPoint;
				*( float* )( params + 16 ) = Radius;
				*( bool* )( params + 32 ) = bSkipBlocked;
				*( int* )( params + 36 ) = inNetworkID;
				*( void** )( params + 40 ) = MinSize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsOnDifferentNetwork( class NavigationPoint* Nav )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.IsOnDifferentNetwork" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )( params + 0 ) = Nav;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnToggle( class SeqAct_Toggle* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldSaveForCheckpoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.ShouldSaveForCheckpoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

			ScriptArray< wchar_t > GetDebugAbbrev(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationPoint.GetDebugAbbrev" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
