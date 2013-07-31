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
	class TrRabbitLeaderboard : public Object
	{
	public:
		struct LeaderboardSlot
		{
		public:
			ADD_STRUCT(int, Score, 8)
			ADD_STRUCT(ScriptName, PRIName, 0)
		};
		ADD_OBJECT(GfxTrHud, m_MoviePlayer, 72)
		ADD_BOOL(bIsActive, 68, 0x4)
		ADD_STRUCT(TrRabbitLeaderboard::LeaderboardSlot, LeaderboardSlots, 80)
		ADD_OBJECT(TrPlayerController, TrPC, 76)
		ADD_BOOL(bInitialized, 68, 0x2)
		ADD_BOOL(bUpdated, 68, 0x1)
		ADD_STRUCT(int, RemainingTime, 64)
		ADD_STRUCT(int, PrevSlots, 60)
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109790);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)&params[4] = MP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Show()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109793);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109794);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109795);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdatePlayers(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109797);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UpdateLeaderboard(int Index, ScriptName PRIName, ScriptString* PlayerName, int Score)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109801);
			byte params[32] = { NULL };
			*(int*)params = Index;
			*(ScriptName*)&params[4] = PRIName;
			*(ScriptString**)&params[12] = PlayerName;
			*(int*)&params[24] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void UpdateTime(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109808);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109810);
			byte params[16] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109816);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
