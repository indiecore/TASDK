#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Controller." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Controller." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Controller." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Controller : public Actor
	{
	public:
			ADD_OBJECT( Pawn, Pawn )
			ADD_OBJECT( PlayerReplicationInfo, PlayerReplicationInfo )
			ADD_VAR( ::BoolProperty, bGodMode, 0x2 )
			ADD_STRUCT( ::VectorProperty, NavMeshPath_SearchExtent_Modifier, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, OldBasedRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LaneOffset, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, Enemy )
			ADD_VAR( ::FloatProperty, MaxMoveTowardPawnTargetTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HighJumpNodeCostModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InUseNodeCostMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SightCounterInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SightCounter, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FailedReachLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FailedReachTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, LastFailedReach )
			ADD_OBJECT( Pawn, ShotTarget )
			ADD_STRUCT( ::VectorProperty, ViewZ, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ViewY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ViewX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroundPitchTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MoveFailureCount, 0xFFFFFFFF )
			ADD_OBJECT( Actor, FailedMoveTarget )
			ADD_OBJECT( InterpActor, PendingMover )
			ADD_VAR( ::FloatProperty, LastRouteFind, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RouteDist, 0xFFFFFFFF )
			ADD_OBJECT( Actor, RouteGoal )
			ADD_STRUCT( ::VectorProperty, CurrentPathDir, 0xFFFFFFFF )
			ADD_OBJECT( ReachSpec, NextRoutePath )
			ADD_OBJECT( ReachSpec, CurrentPath )
			ADD_OBJECT( NavigationPoint, StartSpot )
			ADD_OBJECT( Actor, GoalList )
			ADD_OBJECT( Actor, Focus )
			ADD_OBJECT( Actor, MoveTarget )
			ADD_VAR( ::FloatProperty, MoveTimer, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OverrideSearchStart, 0xFFFFFFFF )
			ADD_OBJECT( NavigationHandle, NavigationHandle )
			ADD_VAR( ::FloatProperty, MinHitWall, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bAltFire, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bFire, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUsingPathLanes, 0x20000 )
			ADD_VAR( ::BoolProperty, bSeeFriendly, 0x10000 )
			ADD_VAR( ::BoolProperty, bPreciseDestination, 0x8000 )
			ADD_VAR( ::BoolProperty, bNotifyFallingHitWall, 0x4000 )
			ADD_VAR( ::BoolProperty, bSkipExtraLOSChecks, 0x2000 )
			ADD_VAR( ::BoolProperty, bLOSflag, 0x1000 )
			ADD_VAR( ::BoolProperty, bForceStrafe, 0x800 )
			ADD_VAR( ::BoolProperty, bPreparingMove, 0x400 )
			ADD_VAR( ::BoolProperty, bAdjusting, 0x200 )
			ADD_VAR( ::BoolProperty, bCanDoSpecial, 0x100 )
			ADD_VAR( ::BoolProperty, bAdvancedTactics, 0x80 )
			ADD_VAR( ::BoolProperty, bOverrideSearchStart, 0x40 )
			ADD_VAR( ::BoolProperty, bNotifyApex, 0x20 )
			ADD_VAR( ::BoolProperty, bNotifyPostLanded, 0x10 )
			ADD_VAR( ::BoolProperty, bSlowerZAcquire, 0x8 )
			ADD_VAR( ::BoolProperty, bSoaking, 0x4 )
			ADD_VAR( ::BoolProperty, bIsPlayer, 0x1 )
			ADD_OBJECT( Controller, NextController )
			ADD_VAR( ::IntProperty, PlayerNum, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
