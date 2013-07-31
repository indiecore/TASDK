#pragma once
#include "Core.Object.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#include "TribesGame.GfxTrHud.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
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
	class TrScoreboard : public Object
	{
	public:
		struct TrScoreboardState
		{
		public:
			ADD_STRUCT(int, DiamondSwordScore, 8)
			ADD_STRUCT(int, BloodEagleScore, 4)
			ADD_STRUCT(int, RemainingTime, 0)
		};
		struct TrScoreSlot
		{
		public:
			ADD_STRUCT(int, RankIcon, 44)
			ADD_STRUCT(int, Rank, 40)
			ADD_STRUCT(int, Ping, 36)
			ADD_STRUCT(int, Score, 32)
			ADD_STRUCT(int, Assists, 28)
			ADD_STRUCT(int, Kills, 24)
			ADD_STRUCT(ScriptString*, ClassAbb, 12)
			ADD_STRUCT(ScriptString*, PlayerName, 0)
		};
		ADD_OBJECT(GfxTrHud, m_MoviePlayer, 100)
		ADD_BOOL(bIsActive, 96, 0x8)
		ADD_OBJECT(TrPlayerController, TrPC, 1652)
		ADD_STRUCT(TrScoreboard::TrScoreboardState, PreviousState, 1640)
		ADD_STRUCT(TrScoreboard::TrScoreSlot, ScoreboardSlots, 104)
		ADD_BOOL(bCheckPing, 96, 0x10)
		ADD_BOOL(bInitialized, 96, 0x4)
		ADD_BOOL(bUpdated, 96, 0x2)
		ADD_BOOL(bTeamGame, 96, 0x1)
		ADD_STRUCT(int, DSIndex, 92)
		ADD_STRUCT(int, BEIndex, 88)
		ADD_STRUCT(int, DSOffset, 84)
		ADD_STRUCT(int, PrevActiveSlot, 80)
		ADD_STRUCT(int, PrevDSSLots, 76)
		ADD_STRUCT(int, PrevBESlots, 72)
		ADD_STRUCT(int, DSSlots, 68)
		ADD_STRUCT(int, BESlots, 64)
		ADD_STRUCT(int, MAX_PLAYER_INDEX, 60)
		int CreditsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110681);
			byte params[12] = { NULL };
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int AssistsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110683);
			byte params[12] = { NULL };
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int KillsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110685);
			byte params[12] = { NULL };
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110715);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)&params[4] = MP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Show(bool bIsTeamGame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110718);
			byte params[4] = { NULL };
			*(bool*)params = bIsTeamGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110720);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConfigScoreboard()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110721);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110723);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePRILists(class TrGameReplicationInfo* TrGRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110726);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = TrGRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptArray<class PlayerReplicationInfo*> GetBestSortArray(ScriptArray<class PlayerReplicationInfo*> PRIArray)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110734);
			byte params[24] = { NULL };
			*(ScriptArray<class PlayerReplicationInfo*>*)params = PRIArray;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class PlayerReplicationInfo*>*)&params[12];
		}
		int GetRank(ScriptArray<class PlayerReplicationInfo*> PRIArray)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110745);
			byte params[16] = { NULL };
			*(ScriptArray<class PlayerReplicationInfo*>*)params = PRIArray;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool ClearSlot(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110759);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool UpdateSlot(int Index, class TrPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110762);
			byte params[12] = { NULL };
			*(int*)params = Index;
			*(class TrPlayerReplicationInfo**)&params[4] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110766);
			byte params[16] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void UpdateHeaders(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110772);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsValidScoreboardPlayer(class TrPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110776);
			byte params[8] = { NULL };
			*(class TrPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
