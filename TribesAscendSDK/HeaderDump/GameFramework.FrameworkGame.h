#pragma once
#include "Engine.GameInfo.h"
namespace UnrealScript
{
	class FrameworkGame : public GameInfo
	{
	public:
		void TgStartGame(ScriptArray<wchar_t>& Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgStartGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Reason = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void TgEndGame(ScriptArray<wchar_t>& Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgEndGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Reason = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void TgTimer(ScriptArray<wchar_t>& sTimerCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgTimer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = sTimerCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			sTimerCommand = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void TgChangeScore(int nTeam, int nCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgChangeScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = nTeam;
			*(int*)(params + 4) = nCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TgChangeTime(int nSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgChangeTime");
			byte* params = (byte*)malloc(4);
			*(int*)params = nSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TgGetSpectators(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgGetSpectators");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			List = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
	};
}
