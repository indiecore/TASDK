#pragma once
#include "Engine.OnlineSubsystem.h"
#include "IpDrv.OnlineGameInterfaceImpl.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystemCommonImpl : public OnlineSubsystem
	{
	public:
		ADD_OBJECT(OnlineGameInterfaceImpl, GameInterfaceImpl, 240)
		ADD_BOOL(bIsUsingSpeechRecognition, 236, 0x1)
		ADD_STRUCT(int, MaxRemoteTalkers, 232)
		ADD_STRUCT(int, MaxLocalTalkers, 228)
		ADD_STRUCT(Object::Pointer, VoiceEngine, 224)
		ScriptString* GetPlayerNicknameFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerNicknameFromIndex");
			byte params[16] = { NULL };
			*(int*)&params[0] = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		OnlineSubsystem::UniqueNetId GetPlayerUniqueNetIdFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerUniqueNetIdFromIndex");
			byte params[12] = { NULL };
			*(int*)&params[0] = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::UniqueNetId*)&params[4];
		}
		bool IsPlayerInSession(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.IsPlayerInSession");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void GetRegisteredPlayers(ScriptName SessionName, ScriptArray<OnlineSubsystem::UniqueNetId>& OutRegisteredPlayers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.GetRegisteredPlayers");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = OutRegisteredPlayers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutRegisteredPlayers = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
