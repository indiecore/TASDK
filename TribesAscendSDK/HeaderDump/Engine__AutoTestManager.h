#pragma once
#include "Engine__Info.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AutoTestManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AutoTestManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AutoTestManager : public Info
	{
	public:
		ADD_VAR(::StrProperty, CommandStringToExec, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumMinutesPerMap, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TravelPointsIncrement, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumRotationsIncrement, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SentinelIdx, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SentinelNavigationIdx, 0xFFFFFFFF)
		ADD_OBJECT(PlayerController, SentinelPC)
		ADD_VAR(::StrProperty, SentinelTagDesc, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SentinelTaskParameter, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SentinelTaskDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AutomatedMapTestingTransitionMap, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AutomatedTestingExecCommandToRunAtStartMatch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumMapListCyclesDone, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumberOfMatchesPlayed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumAutomatedMapTestingCycles, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AutomatedTestingMapIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AutomatedPerfRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSentinelStreamingLevelStillLoading, 0x100)
		ADD_VAR(::BoolProperty, bDoingASentinelRun, 0x80)
		ADD_VAR(::BoolProperty, bCheckingForMemLeaks, 0x40)
		ADD_VAR(::BoolProperty, bCheckingForFragmentation, 0x20)
		ADD_VAR(::BoolProperty, bExitOnCyclesComplete, 0x10)
		ADD_VAR(::BoolProperty, bAutomatedTestingWithOpen, 0x8)
		ADD_VAR(::BoolProperty, bUsingAutomatedTestingMapList, 0x4)
		ADD_VAR(::BoolProperty, bAutoContinueToNextRound, 0x2)
		ADD_VAR(::BoolProperty, bAutomatedPerfTesting, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'InitializeOptions'
		// Here lies the not-yet-implemented method 'BeginSentinelRun'
		// Here lies the not-yet-implemented method 'AddSentinelPerTimePeriodStats'
		// Here lies the not-yet-implemented method 'EndSentinelRun'
		// Here lies the not-yet-implemented method 'DoTravelTheWorld'
		// Here lies the not-yet-implemented method 'DoSentinelActionPerLoadedMap'
		// Here lies the not-yet-implemented method 'HandlePerLoadedMapAudioStats'
		// Here lies the not-yet-implemented method 'GetTravelLocations'
		// Here lies the not-yet-implemented method 'DoSentinel_MemoryAtSpecificLocation'
		// Here lies the not-yet-implemented method 'DoSentinel_PerfAtSpecificLocation'
		// Here lies the not-yet-implemented method 'DoSentinel_ViewDependentMemoryAtSpecificLocation'
		// Here lies the not-yet-implemented method 'DoTimeBasedSentinelStatGathering'
		// Here lies the not-yet-implemented method 'DoMemoryTracking'
		// Here lies the not-yet-implemented method 'StartAutomatedMapTestTimer'
		// Here lies the not-yet-implemented method 'StartAutomatedMapTestTimerWorker'
		// Here lies the not-yet-implemented method 'CloseAutomatedMapTestTimer'
		// Here lies the not-yet-implemented method 'IncrementAutomatedTestingMapIndex'
		// Here lies the not-yet-implemented method 'IncrementNumberOfMatchesPlayed'
		// Here lies the not-yet-implemented method 'GetNextAutomatedTestingMap'
		// Here lies the not-yet-implemented method 'StartMatch'
		// Here lies the not-yet-implemented method 'CheckForSentinelRun'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
