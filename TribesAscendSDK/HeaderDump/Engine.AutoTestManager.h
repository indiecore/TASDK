#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Info.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AutoTestManager : public Info
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, AutomatedMapTestingList, 488)
		ADD_STRUCT(ScriptArray<Object::Vector>, SentinelTravelArray, 576)
		ADD_STRUCT(ScriptArray<ScriptString*>, CommandsToRunAtEachTravelTheWorldNode, 608)
		ADD_STRUCT(ScriptString*, CommandStringToExec, 620)
		ADD_STRUCT(int, NumMinutesPerMap, 604)
		ADD_STRUCT(int, TravelPointsIncrement, 600)
		ADD_STRUCT(int, NumRotationsIncrement, 596)
		ADD_STRUCT(int, SentinelIdx, 592)
		ADD_STRUCT(int, SentinelNavigationIdx, 588)
		ADD_OBJECT(PlayerController, SentinelPC, 572)
		ADD_STRUCT(ScriptString*, SentinelTagDesc, 560)
		ADD_STRUCT(ScriptString*, SentinelTaskParameter, 548)
		ADD_STRUCT(ScriptString*, SentinelTaskDescription, 536)
		ADD_STRUCT(ScriptString*, AutomatedMapTestingTransitionMap, 524)
		ADD_STRUCT(ScriptString*, AutomatedTestingExecCommandToRunAtStartMatch, 512)
		ADD_STRUCT(int, NumMapListCyclesDone, 508)
		ADD_STRUCT(int, NumberOfMatchesPlayed, 504)
		ADD_STRUCT(int, NumAutomatedMapTestingCycles, 500)
		ADD_STRUCT(int, AutomatedTestingMapIndex, 484)
		ADD_STRUCT(int, AutomatedPerfRemainingTime, 480)
		ADD_BOOL(bSentinelStreamingLevelStillLoading, 476, 0x100)
		ADD_BOOL(bDoingASentinelRun, 476, 0x80)
		ADD_BOOL(bCheckingForMemLeaks, 476, 0x40)
		ADD_BOOL(bCheckingForFragmentation, 476, 0x20)
		ADD_BOOL(bExitOnCyclesComplete, 476, 0x10)
		ADD_BOOL(bAutomatedTestingWithOpen, 476, 0x8)
		ADD_BOOL(bUsingAutomatedTestingMapList, 476, 0x4)
		ADD_BOOL(bAutoContinueToNextRound, 476, 0x2)
		ADD_BOOL(bAutomatedPerfTesting, 476, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeOptions(ScriptString* Options)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.InitializeOptions");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Options;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginSentinelRun(ScriptString* TaskDescription, ScriptString* TaskParameter, ScriptString* TagDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.BeginSentinelRun");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = TaskDescription;
			*(ScriptString**)&params[12] = TaskParameter;
			*(ScriptString**)&params[24] = TagDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSentinelPerTimePeriodStats(Object::Vector InLocation, Object::Rotator InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.AddSentinelPerTimePeriodStats");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = InLocation;
			*(Object::Rotator*)&params[12] = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndSentinelRun(Object::EAutomatedRunResult RunResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.EndSentinelRun");
			byte params[1] = { NULL };
			*(Object::EAutomatedRunResult*)&params[0] = RunResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoTravelTheWorld()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoTravelTheWorld");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoSentinelActionPerLoadedMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoSentinelActionPerLoadedMap");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandlePerLoadedMapAudioStats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.HandlePerLoadedMapAudioStats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetTravelLocations(ScriptName LevelName, class PlayerController* PC, ScriptArray<Object::Vector>& TravelPoints)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.GetTravelLocations");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = LevelName;
			*(class PlayerController**)&params[8] = PC;
			*(ScriptArray<Object::Vector>*)&params[12] = TravelPoints;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TravelPoints = *(ScriptArray<Object::Vector>*)&params[12];
		}
		void DoSentinel_MemoryAtSpecificLocation(Object::Vector InLocation, Object::Rotator InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoSentinel_MemoryAtSpecificLocation");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = InLocation;
			*(Object::Rotator*)&params[12] = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoSentinel_PerfAtSpecificLocation(Object::Vector& InLocation, Object::Rotator& InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoSentinel_PerfAtSpecificLocation");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = InLocation;
			*(Object::Rotator*)&params[12] = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InLocation = *(Object::Vector*)&params[0];
			InRotation = *(Object::Rotator*)&params[12];
		}
		void DoSentinel_ViewDependentMemoryAtSpecificLocation(Object::Vector& InLocation, Object::Rotator& InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoSentinel_ViewDependentMemoryAtSpecificLocation");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = InLocation;
			*(Object::Rotator*)&params[12] = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InLocation = *(Object::Vector*)&params[0];
			InRotation = *(Object::Rotator*)&params[12];
		}
		void DoTimeBasedSentinelStatGathering()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoTimeBasedSentinelStatGathering");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoMemoryTracking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoMemoryTracking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartAutomatedMapTestTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.StartAutomatedMapTestTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartAutomatedMapTestTimerWorker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.StartAutomatedMapTestTimerWorker");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CloseAutomatedMapTestTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.CloseAutomatedMapTestTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void IncrementAutomatedTestingMapIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.IncrementAutomatedTestingMapIndex");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void IncrementNumberOfMatchesPlayed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.IncrementNumberOfMatchesPlayed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetNextAutomatedTestingMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.GetNextAutomatedTestingMap");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void StartMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.StartMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckForSentinelRun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.CheckForSentinelRun");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
