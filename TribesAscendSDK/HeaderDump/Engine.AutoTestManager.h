#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Info.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
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
		void InitializeOptions(ScriptArray<wchar_t> Options)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.InitializeOptions");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Options;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginSentinelRun(ScriptArray<wchar_t> TaskDescription, ScriptArray<wchar_t> TaskParameter, ScriptArray<wchar_t> TagDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.BeginSentinelRun");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = TaskDescription;
			*(ScriptArray<wchar_t>*)(params + 12) = TaskParameter;
			*(ScriptArray<wchar_t>*)(params + 24) = TagDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddSentinelPerTimePeriodStats(Vector InLocation, Rotator InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.AddSentinelPerTimePeriodStats");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InLocation;
			*(Rotator*)(params + 12) = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndSentinelRun(byte RunResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.EndSentinelRun");
			byte* params = (byte*)malloc(1);
			*params = RunResult;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void GetTravelLocations(ScriptName LevelName, class PlayerController* PC, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& TravelPoints)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.GetTravelLocations");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = LevelName;
			*(class PlayerController**)(params + 8) = PC;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = TravelPoints;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			TravelPoints = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
		}
		void DoSentinel_MemoryAtSpecificLocation(Vector InLocation, Rotator InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoSentinel_MemoryAtSpecificLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InLocation;
			*(Rotator*)(params + 12) = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoSentinel_PerfAtSpecificLocation(Vector& InLocation, Rotator& InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoSentinel_PerfAtSpecificLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InLocation;
			*(Rotator*)(params + 12) = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InLocation = *(Vector*)params;
			InRotation = *(Rotator*)(params + 12);
			free(params);
		}
		void DoSentinel_ViewDependentMemoryAtSpecificLocation(Vector& InLocation, Rotator& InRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.DoSentinel_ViewDependentMemoryAtSpecificLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InLocation;
			*(Rotator*)(params + 12) = InRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InLocation = *(Vector*)params;
			InRotation = *(Rotator*)(params + 12);
			free(params);
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
		ScriptArray<wchar_t> GetNextAutomatedTestingMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.GetNextAutomatedTestingMap");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void StartMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.StartMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckForSentinelRun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AutoTestManager.CheckForSentinelRun");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
