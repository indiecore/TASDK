#pragma once
#include "Core.Object.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.GfxTrHud.h"
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
	class TrArenaStats : public Object
	{
	public:
		static const auto MAX_NUM_ARENA_PLAYERS_PER_TEAM = 8;
		enum ManGraphicState : byte
		{
			ManGraphic_Hidden = 0,
			ManGraphic_HasSpawnsLeft = 1,
			ManGraphic_OutOfSpawns = 2,
			ManGraphic_CrossedOffList = 3,
			ManGraphic_MAX = 4,
		};
		ADD_STRUCT(int, MyTeam, 60)
		ADD_OBJECT(TrPlayerController, TrPC, 96)
		ADD_OBJECT(GfxTrHud, m_MoviePlayer, 92)
		ADD_BOOL(bIsActive, 68, 0x1)
		ADD_STRUCT(int, TeamScore, 72)
		ADD_BOOL(bForcingUpdate, 68, 0x2)
		ADD_STRUCT(TrArenaStats::ManGraphicState, FriendlyManGraphics, 100)
		ADD_STRUCT(TrArenaStats::ManGraphicState, EnemyManGraphics, 108)
		ADD_STRUCT(int, RoundScore, 80)
		ADD_STRUCT(int, RoundNum, 88)
		ADD_STRUCT(int, RemainingTime, 64)
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66604);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)&params[4] = MP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Show()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66609);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66611);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66612);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66614);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeamScore(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66615);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetManGraphicState(bool bFriendly, int Index, TrArenaStats::ManGraphicState NewState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66625);
			byte params[9] = { NULL };
			*(bool*)params = bFriendly;
			*(int*)&params[4] = Index;
			*(TrArenaStats::ManGraphicState*)&params[8] = NewState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRound(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66633);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTime(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66640);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66643);
			byte params[16] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66649);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
