#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AutoTestManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AutoTestManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AutoTestManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AutoTestManager : public Info
	{
	public:
			ADD_VAR( ::StrProperty, CommandStringToExec, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumMinutesPerMap, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TravelPointsIncrement, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumRotationsIncrement, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SentinelIdx, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SentinelNavigationIdx, 0xFFFFFFFF )
			ADD_OBJECT( PlayerController, SentinelPC )
			ADD_VAR( ::StrProperty, SentinelTagDesc, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SentinelTaskParameter, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SentinelTaskDescription, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AutomatedMapTestingTransitionMap, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AutomatedTestingExecCommandToRunAtStartMatch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumMapListCyclesDone, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumberOfMatchesPlayed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumAutomatedMapTestingCycles, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AutomatedTestingMapIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AutomatedPerfRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSentinelStreamingLevelStillLoading, 0x100 )
			ADD_VAR( ::BoolProperty, bDoingASentinelRun, 0x80 )
			ADD_VAR( ::BoolProperty, bCheckingForMemLeaks, 0x40 )
			ADD_VAR( ::BoolProperty, bCheckingForFragmentation, 0x20 )
			ADD_VAR( ::BoolProperty, bExitOnCyclesComplete, 0x10 )
			ADD_VAR( ::BoolProperty, bAutomatedTestingWithOpen, 0x8 )
			ADD_VAR( ::BoolProperty, bUsingAutomatedTestingMapList, 0x4 )
			ADD_VAR( ::BoolProperty, bAutoContinueToNextRound, 0x2 )
			ADD_VAR( ::BoolProperty, bAutomatedPerfTesting, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
