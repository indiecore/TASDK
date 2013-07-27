#pragma once
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
	class OnlineMatchmakingStats : public Object
	{
	public:
		class MMStats_Timer
		{
		public:
			ADD_STRUCT(Object::Double, MSecs, 4)
			ADD_BOOL(bInProgress, 0, 0x1)
		};
		void StartTimer(OnlineMatchmakingStats::MMStats_Timer& Timer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineMatchmakingStats.StartTimer");
			byte params[12] = { NULL };
			*(OnlineMatchmakingStats::MMStats_Timer*)&params[0] = Timer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Timer = *(OnlineMatchmakingStats::MMStats_Timer*)&params[0];
		}
		void StopTimer(OnlineMatchmakingStats::MMStats_Timer& Timer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineMatchmakingStats.StopTimer");
			byte params[12] = { NULL };
			*(OnlineMatchmakingStats::MMStats_Timer*)&params[0] = Timer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Timer = *(OnlineMatchmakingStats::MMStats_Timer*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
