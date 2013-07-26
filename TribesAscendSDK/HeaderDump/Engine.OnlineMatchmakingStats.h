#pragma once
#include "Core.Object.h"
#include "Engine.OnlineMatchmakingStats.MMStats_Timer.h"
namespace UnrealScript
{
	class OnlineMatchmakingStats : public Object
	{
	public:
		void StartTimer(MMStats_Timer& Timer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineMatchmakingStats.StartTimer");
			byte* params = (byte*)malloc(12);
			*(MMStats_Timer*)params = Timer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Timer = *(MMStats_Timer*)params;
			free(params);
		}
		void StopTimer(MMStats_Timer& Timer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineMatchmakingStats.StopTimer");
			byte* params = (byte*)malloc(12);
			*(MMStats_Timer*)params = Timer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Timer = *(MMStats_Timer*)params;
			free(params);
		}
	};
}
