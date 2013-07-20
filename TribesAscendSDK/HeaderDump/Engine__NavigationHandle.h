#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavigationHandle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavigationHandle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavigationHandle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavigationHandle : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, LastPathFailTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LastPathError, 0xFFFFFFFF )
			ADD_OBJECT( NavMeshPathGoalEvaluator, PathGoalList )
			ADD_OBJECT( NavMeshPathConstraint, PathConstraintList )
			ADD_VAR( ::BoolProperty, bUltraVerbosePathDebugging, 0x8 )
			ADD_VAR( ::BoolProperty, bDebugConstraintsAndGoalEvals, 0x4 )
			ADD_VAR( ::BoolProperty, bUseORforEvaluateGoal, 0x2 )
			ADD_VAR( ::BoolProperty, bSkipRouteCacheUpdates, 0x1 )
			ADD_OBJECT( Pylon, AnchorPylon )
			void ClearConstraints(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.ClearConstraints" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPathConstraint( class NavMeshPathConstraint* Constraint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.AddPathConstraint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavMeshPathConstraint** )params = Constraint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddGoalEvaluator( class NavMeshPathGoalEvaluator* Evaluator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.AddGoalEvaluator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavMeshPathGoalEvaluator** )params = Evaluator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class NavMeshPathConstraint* CreatePathConstraint( ScriptClass* ConstraintClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.CreatePathConstraint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = ConstraintClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavMeshPathConstraint** )( params + function->return_val_offset() );
			}

			class NavMeshPathGoalEvaluator* CreatePathGoalEvaluator( ScriptClass* GoalEvalClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.CreatePathGoalEvaluator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = GoalEvalClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavMeshPathGoalEvaluator** )( params + function->return_val_offset() );
			}

			int GetPathCacheLength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetPathCacheLength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void PathCache_Empty(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.PathCache_Empty" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector PathCache_GetGoalPoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.PathCache_GetGoalPoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void PathCache_RemoveIndex( int InIdx, int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.PathCache_RemoveIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = InIdx;
				*( int* )( params + 4 ) = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetBestUnfinishedPathPoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetBestUnfinishedPathPoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool FindPylon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.FindPylon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Pylon* GetPylonFromPos( Vector Position )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetPylonFromPos" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = Position;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Pylon** )( params + function->return_val_offset() );
			}

			bool GetNextMoveLocation( Vector &out_MoveDest, float ArrivalDistance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetNextMoveLocation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = out_MoveDest;
				*( float* )( params + 12 ) = ArrivalDistance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_MoveDest = *( Vector* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetFinalDestination( Vector FinalDest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.SetFinalDestination" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = FinalDest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ComputeValidFinalDestination( Vector &out_ComputedPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.ComputeValidFinalDestination" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = out_ComputedPosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ComputedPosition = *( Vector* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindPath( class Actor* &out_DestActor, int &out_DestItem )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.FindPath" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = out_DestActor;
				*( int* )( params + 4 ) = out_DestItem;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_DestActor = *( class Actor** )params;
				out_DestItem = *( int* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SuggestMovePreparation( Vector &MovePt, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.SuggestMovePreparation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = MovePt;
				*( class Controller** )( params + 12 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MovePt = *( Vector* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ObstacleLineCheck( Vector Start, Vector End, Vector Extent, Vector &out_HitLoc, Vector &out_HitNorm )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.ObstacleLineCheck" );
				byte *params = ( byte* )( malloc( 60 ) );
				*( Vector* )params = Start;
				*( Vector* )( params + 12 ) = End;
				*( Vector* )( params + 24 ) = Extent;
				*( Vector* )( params + 36 ) = out_HitLoc;
				*( Vector* )( params + 48 ) = out_HitNorm;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_HitLoc = *( Vector* )( params + 36 );
				out_HitNorm = *( Vector* )( params + 48 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ObstaclePointCheck( Vector Pt, Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.ObstaclePointCheck" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Pt;
				*( Vector* )( params + 12 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LineCheck( Vector Start, Vector End, Vector Extent, Vector &out_HitLocation, Vector &out_HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.LineCheck" );
				byte *params = ( byte* )( malloc( 60 ) );
				*( Vector* )params = Start;
				*( Vector* )( params + 12 ) = End;
				*( Vector* )( params + 24 ) = Extent;
				*( Vector* )( params + 36 ) = out_HitLocation;
				*( Vector* )( params + 48 ) = out_HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_HitLocation = *( Vector* )( params + 36 );
				out_HitNormal = *( Vector* )( params + 48 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PointCheck( Vector Pt, Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.PointCheck" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Pt;
				*( Vector* )( params + 12 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PointReachable( Vector Point, Vector OverrideStartPoint, bool bAllowHitsInEndCollisionBox )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.PointReachable" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = Point;
				*( Vector* )( params + 12 ) = OverrideStartPoint;
				*( bool* )( params + 24 ) = bAllowHitsInEndCollisionBox;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ActorReachable( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.ActorReachable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DrawPathCache( Vector DrawOffset, bool bPersistent, void* DrawColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.DrawPathCache" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = DrawOffset;
				*( bool* )( params + 12 ) = bPersistent;
				*( void** )( params + 16 ) = DrawColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetCurrentEdgeDebugText(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetCurrentEdgeDebugText" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ClearCurrentEdge(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.ClearCurrentEdge" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetCurrentEdgeType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetCurrentEdgeType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void GetAllPolyCentersWithinBounds( Vector pos, Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetAllPolyCentersWithinBounds" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )params = pos;
				*( Vector* )( params + 12 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetValidPositionsForBox( Vector pos, float Radius, Vector Extent, bool bMustBeReachableFromStartPos, int MaxPositions, float MinRadius, Vector ValidBoxAroundStartPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetValidPositionsForBox" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( Vector* )params = pos;
				*( float* )( params + 12 ) = Radius;
				*( Vector* )( params + 16 ) = Extent;
				*( bool* )( params + 28 ) = bMustBeReachableFromStartPos;
				*( int* )( params + 44 ) = MaxPositions;
				*( float* )( params + 48 ) = MinRadius;
				*( Vector* )( params + 52 ) = ValidBoxAroundStartPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LimitPathCacheDistance( float MaxDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.LimitPathCacheDistance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = MaxDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsAnchorInescapable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.IsAnchorInescapable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GetFirstMoveLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetFirstMoveLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float CalculatePathDistance( Vector FinalDest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.CalculatePathDistance" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = FinalDest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Vector MoveToDesiredHeightAboveMesh( Vector Point, float Height )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.MoveToDesiredHeightAboveMesh" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = Point;
				*( float* )( params + 12 ) = Height;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool PopulatePathfindingParamCache(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.PopulatePathfindingParamCache" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetAllCoverSlotsInRadius( Vector FromLoc, float Radius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavigationHandle.GetAllCoverSlotsInRadius" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = FromLoc;
				*( float* )( params + 12 ) = Radius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
