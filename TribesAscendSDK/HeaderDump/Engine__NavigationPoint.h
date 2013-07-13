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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
