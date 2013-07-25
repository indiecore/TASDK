#pragma once
#include "Core__Object.h"
namespace UnrealScript
{
	class OnlineMatchmakingStats : public Object
	{
	public:
		void StartTimer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineMatchmakingStats.MMStats_Timer'!
void*& Timer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineMatchmakingStats.StartTimer");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineMatchmakingStats.MMStats_Timer'!
void**)params = Timer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Timer = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineMatchmakingStats.MMStats_Timer'!
void**)params;
			free(params);
		}
		void StopTimer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineMatchmakingStats.MMStats_Timer'!
void*& Timer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineMatchmakingStats.StopTimer");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineMatchmakingStats.MMStats_Timer'!
void**)params = Timer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Timer = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineMatchmakingStats.MMStats_Timer'!
void**)params;
			free(params);
		}
	};
}
