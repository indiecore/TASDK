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
		class RequiredMobileInputConfig
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptString*>, RequireZoneNames, 12)
			ADD_BOOL(bIsAttractModeGroup, 24, 0x1)
			ADD_STRUCT(ScriptString*, GroupName, 0)
		};
		ADD_STRUCT(ScriptArray<FrameworkGame::RequiredMobileInputConfig>, RequiredMobileInputConfigs, 884)
		void TgStartGame(ScriptString*& Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgStartGame");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Reason = *(ScriptString**)&params[0];
		}
		void TgEndGame(ScriptString*& Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgEndGame");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Reason = *(ScriptString**)&params[0];
		}
		void TgTimer(ScriptString*& sTimerCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgTimer");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = sTimerCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			sTimerCommand = *(ScriptString**)&params[0];
		}
		void TgChangeScore(int nTeam, int nCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgChangeScore");
			byte params[8] = { NULL };
			*(int*)&params[0] = nTeam;
			*(int*)&params[4] = nCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TgChangeTime(int nSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgChangeTime");
			byte params[4] = { NULL };
			*(int*)&params[0] = nSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TgGetSpectators(ScriptArray<ScriptString*>& List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.FrameworkGame.TgGetSpectators");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			List = *(ScriptArray<ScriptString*>*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
