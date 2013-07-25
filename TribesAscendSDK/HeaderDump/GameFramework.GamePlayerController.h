#pragma once
#include "Engine.PlayerController.h"
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.CameraShake.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GamePlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GamePlayerController : public PlayerController
	{
	public:
		ADD_VAR(::NameProperty, CurrentSoundMode, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AgentAwareRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsWarmupPaused, 0x4)
		ADD_VAR(::BoolProperty, bDebugCrowdAwareness, 0x2)
		ADD_VAR(::BoolProperty, bWarnCrowdMembers, 0x1)
		int GetUIPlayerIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.GetUIPlayerIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void NotifyCrowdAgentRefresh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.NotifyCrowdAgentRefresh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyCrowdAgentInRadius(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.NotifyCrowdAgentInRadius");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoForceFeedbackForScreenShake(class CameraShake* ShakeData, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.DoForceFeedbackForScreenShake");
			byte* params = (byte*)malloc(8);
			*(class CameraShake**)params = ShakeData;
			*(float*)(params + 4) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSoundMode(ScriptName InSoundModeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.SetSoundMode");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = InSoundModeName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowLoadingMovie(bool bShowMovie, bool bPauseAfterHide, float PauseDuration, float KeepPlayingDuration, bool bOverridePreviousDelays)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ShowLoadingMovie");
			byte* params = (byte*)malloc(20);
			*(bool*)params = bShowMovie;
			*(bool*)(params + 4) = bPauseAfterHide;
			*(float*)(params + 8) = PauseDuration;
			*(float*)(params + 12) = KeepPlayingDuration;
			*(bool*)(params + 16) = bOverridePreviousDelays;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KeepPlayingLoadingMovie()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.KeepPlayingLoadingMovie");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayMovie(ScriptArray<wchar_t> MovieName, int InStartOfRenderingMovieFrame, int InEndOfRenderingMovieFrame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ClientPlayMovie");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = MovieName;
			*(int*)(params + 12) = InStartOfRenderingMovieFrame;
			*(int*)(params + 16) = InEndOfRenderingMovieFrame;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientStopMovie(float DelayInSeconds, bool bAllowMovieToFinish, bool bForceStopNonSkippable, bool bForceStopLoadingMovie)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ClientStopMovie");
			byte* params = (byte*)malloc(16);
			*(float*)params = DelayInSeconds;
			*(bool*)(params + 4) = bAllowMovieToFinish;
			*(bool*)(params + 8) = bForceStopNonSkippable;
			*(bool*)(params + 12) = bForceStopLoadingMovie;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetCurrentMovie(ScriptArray<wchar_t>& MovieName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.GetCurrentMovie");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = MovieName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MovieName = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		bool CanUnpauseWarmup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.CanUnpauseWarmup");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void WarmupPause(bool bDesiredPauseState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.WarmupPause");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDesiredPauseState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoMemLeakChecking(float InTimeBetweenMemLeakChecks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.DoMemLeakChecking");
			byte* params = (byte*)malloc(4);
			*(float*)params = InTimeBetweenMemLeakChecks;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopMemLeakChecking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.StopMemLeakChecking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CallMemLeakCheck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.CallMemLeakCheck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientColorFade(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* FadeColor, byte FromAlpha, byte ToAlpha, float FadeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ClientColorFade");
			byte* params = (byte*)malloc(10);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params = FadeColor;
			*(params + 4) = FromAlpha;
			*(params + 5) = ToAlpha;
			*(float*)(params + 8) = FadeTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
