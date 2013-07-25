#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.GFxObject.h"
namespace UnrealScript
{
	class UTGFxTweenableMoviePlayer : public GFxMoviePlayer
	{
	public:
		void TweenTo(class GFxObject* MC, float Duration, ScriptArray<wchar_t> Member, float Target, byte NewTweenType, ScriptArray<wchar_t> Callback)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxTweenableMoviePlayer.TweenTo");
			byte* params = (byte*)malloc(37);
			*(class GFxObject**)params = MC;
			*(float*)(params + 4) = Duration;
			*(ScriptArray<wchar_t>*)(params + 8) = Member;
			*(float*)(params + 20) = Target;
			*(params + 24) = NewTweenType;
			*(ScriptArray<wchar_t>*)(params + 28) = Callback;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessTweenCallback(ScriptArray<wchar_t> Callback, class GFxObject* TargetMC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxTweenableMoviePlayer.ProcessTweenCallback");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Callback;
			*(class GFxObject**)(params + 12) = TargetMC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxTweenableMoviePlayer.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearsTweensOnMovieClip(class GFxObject* MC, bool bReset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxTweenableMoviePlayer.ClearsTweensOnMovieClip");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = MC;
			*(bool*)(params + 4) = bReset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PrintTweensToLog()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxTweenableMoviePlayer.PrintTweensToLog");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TweenComplete(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGFxTweenableMoviePlayer.TweenComplete");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
