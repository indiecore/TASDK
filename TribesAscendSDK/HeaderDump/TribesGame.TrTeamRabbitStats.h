#pragma once
#include "Core.Object.h"
#include "TribesGame.GfxTrHud.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrGameReplicationInfo.h"
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
	class TrTeamRabbitStats : public Object
	{
	public:
		ADD_OBJECT(GfxTrHud, m_MoviePlayer, 84)
		ADD_BOOL(bIsActive, 68, 0x1)
		ADD_OBJECT(TrPlayerController, TrPC, 88)
		ADD_STRUCT(int, TeamHoldingFlag, 80)
		ADD_STRUCT(int, TeamScore, 72)
		ADD_BOOL(bForcingUpdate, 68, 0x2)
		ADD_STRUCT(int, RemainingTime, 64)
		ADD_STRUCT(int, MyTeam, 60)
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113152);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)&params[4] = MP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Show()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113155);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113156);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113157);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113159);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateFlagStatus(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113160);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTeamScore(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113162);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTime(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113165);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113167);
			byte params[16] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113173);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
