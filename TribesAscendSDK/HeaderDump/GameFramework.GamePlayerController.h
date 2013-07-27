#pragma once
#include "Engine.PlayerController.h"
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.CameraShake.h"
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
namespace UnrealScript
{
	class GamePlayerController : public PlayerController
	{
	public:
		ADD_STRUCT(ScriptName, CurrentSoundMode, 1456)
		ADD_STRUCT(float, AgentAwareRadius, 1452)
		ADD_BOOL(bIsWarmupPaused, 1448, 0x4)
		ADD_BOOL(bDebugCrowdAwareness, 1448, 0x2)
		ADD_BOOL(bWarnCrowdMembers, 1448, 0x1)
		int GetUIPlayerIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.GetUIPlayerIndex");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void NotifyCrowdAgentRefresh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.NotifyCrowdAgentRefresh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyCrowdAgentInRadius(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.NotifyCrowdAgentInRadius");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoForceFeedbackForScreenShake(class CameraShake* ShakeData, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.DoForceFeedbackForScreenShake");
			byte params[8] = { NULL };
			*(class CameraShake**)&params[0] = ShakeData;
			*(float*)&params[4] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundMode(ScriptName InSoundModeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.SetSoundMode");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = InSoundModeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowLoadingMovie(bool bShowMovie, bool bPauseAfterHide, float PauseDuration, float KeepPlayingDuration, bool bOverridePreviousDelays)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ShowLoadingMovie");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bShowMovie;
			*(bool*)&params[4] = bPauseAfterHide;
			*(float*)&params[8] = PauseDuration;
			*(float*)&params[12] = KeepPlayingDuration;
			*(bool*)&params[16] = bOverridePreviousDelays;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KeepPlayingLoadingMovie()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.KeepPlayingLoadingMovie");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayMovie(ScriptString* MovieName, int InStartOfRenderingMovieFrame, int InEndOfRenderingMovieFrame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ClientPlayMovie");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = MovieName;
			*(int*)&params[12] = InStartOfRenderingMovieFrame;
			*(int*)&params[16] = InEndOfRenderingMovieFrame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopMovie(float DelayInSeconds, bool bAllowMovieToFinish, bool bForceStopNonSkippable, bool bForceStopLoadingMovie)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ClientStopMovie");
			byte params[16] = { NULL };
			*(float*)&params[0] = DelayInSeconds;
			*(bool*)&params[4] = bAllowMovieToFinish;
			*(bool*)&params[8] = bForceStopNonSkippable;
			*(bool*)&params[12] = bForceStopLoadingMovie;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCurrentMovie(ScriptString*& MovieName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.GetCurrentMovie");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = MovieName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MovieName = *(ScriptString**)&params[0];
		}
		bool CanUnpauseWarmup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.CanUnpauseWarmup");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void WarmupPause(bool bDesiredPauseState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.WarmupPause");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDesiredPauseState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoMemLeakChecking(float InTimeBetweenMemLeakChecks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.DoMemLeakChecking");
			byte params[4] = { NULL };
			*(float*)&params[0] = InTimeBetweenMemLeakChecks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void ClientColorFade(Object::Color FadeColor, byte FromAlpha, byte ToAlpha, float FadeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerController.ClientColorFade");
			byte params[10] = { NULL };
			*(Object::Color*)&params[0] = FadeColor;
			params[4] = FromAlpha;
			params[5] = ToAlpha;
			*(float*)&params[8] = FadeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
