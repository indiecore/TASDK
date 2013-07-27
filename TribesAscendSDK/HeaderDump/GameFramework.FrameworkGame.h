#pragma once
#include "Engine.GameInfo.h"
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
	class FrameworkGame : public GameInfo
	{
	public:
		struct RequiredMobileInputConfig
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptString*>, RequireZoneNames, 12)
			ADD_BOOL(bIsAttractModeGroup, 24, 0x1)
			ADD_STRUCT(ScriptString*, GroupName, 0)
		};
		ADD_STRUCT(ScriptArray<FrameworkGame::RequiredMobileInputConfig>, RequiredMobileInputConfigs, 884)
		void TgStartGame(ScriptString*& Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30549);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Reason = *(ScriptString**)params;
		}
		void TgEndGame(ScriptString*& Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30551);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Reason = *(ScriptString**)params;
		}
		void TgTimer(ScriptString*& sTimerCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30553);
			byte params[12] = { NULL };
			*(ScriptString**)params = sTimerCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			sTimerCommand = *(ScriptString**)params;
		}
		void TgChangeScore(int nTeam, int nCount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30555);
			byte params[8] = { NULL };
			*(int*)params = nTeam;
			*(int*)&params[4] = nCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TgChangeTime(int nSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30558);
			byte params[4] = { NULL };
			*(int*)params = nSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TgGetSpectators(ScriptArray<ScriptString*>& List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30560);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			List = *(ScriptArray<ScriptString*>*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
