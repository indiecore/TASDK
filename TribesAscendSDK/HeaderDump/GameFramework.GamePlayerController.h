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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31789);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void NotifyCrowdAgentRefresh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31791);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyCrowdAgentInRadius(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31792);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoForceFeedbackForScreenShake(class CameraShake* ShakeData, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31794);
			byte params[8] = { NULL };
			*(class CameraShake**)params = ShakeData;
			*(float*)&params[4] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundMode(ScriptName InSoundModeName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31806);
			byte params[8] = { NULL };
			*(ScriptName*)params = InSoundModeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowLoadingMovie(bool bShowMovie, bool bPauseAfterHide, float PauseDuration, float KeepPlayingDuration, bool bOverridePreviousDelays)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31810);
			byte params[20] = { NULL };
			*(bool*)params = bShowMovie;
			*(bool*)&params[4] = bPauseAfterHide;
			*(float*)&params[8] = PauseDuration;
			*(float*)&params[12] = KeepPlayingDuration;
			*(bool*)&params[16] = bOverridePreviousDelays;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KeepPlayingLoadingMovie()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31816);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayMovie(ScriptString* MovieName, int InStartOfRenderingMovieFrame, int InEndOfRenderingMovieFrame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31817);
			byte params[20] = { NULL };
			*(ScriptString**)params = MovieName;
			*(int*)&params[12] = InStartOfRenderingMovieFrame;
			*(int*)&params[16] = InEndOfRenderingMovieFrame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopMovie(float DelayInSeconds, bool bAllowMovieToFinish, bool bForceStopNonSkippable, bool bForceStopLoadingMovie)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31821);
			byte params[16] = { NULL };
			*(float*)params = DelayInSeconds;
			*(bool*)&params[4] = bAllowMovieToFinish;
			*(bool*)&params[8] = bForceStopNonSkippable;
			*(bool*)&params[12] = bForceStopLoadingMovie;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCurrentMovie(ScriptString*& MovieName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31826);
			byte params[12] = { NULL };
			*(ScriptString**)params = MovieName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MovieName = *(ScriptString**)params;
		}
		bool CanUnpauseWarmup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31828);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void WarmupPause(bool bDesiredPauseState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31830);
			byte params[4] = { NULL };
			*(bool*)params = bDesiredPauseState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoMemLeakChecking(float InTimeBetweenMemLeakChecks)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31834);
			byte params[4] = { NULL };
			*(float*)params = InTimeBetweenMemLeakChecks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopMemLeakChecking()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31836);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CallMemLeakCheck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31837);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientColorFade(Object::Color FadeColor, byte FromAlpha, byte ToAlpha, float FadeTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31838);
			byte params[10] = { NULL };
			*(Object::Color*)params = FadeColor;
			params[4] = FromAlpha;
			params[5] = ToAlpha;
			*(float*)&params[8] = FadeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
