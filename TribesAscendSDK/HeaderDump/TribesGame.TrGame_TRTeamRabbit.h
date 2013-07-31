#pragma once
#include "TribesGame.TrGame.h"
#include "TribesGame.TrFlagTeamRabbit.h"
#include "Engine.PlayerStart.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerReplicationInfo.h"
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
	class TrGame_TRTeamRabbit : public TrGame
	{
	public:
		static const auto MESSAGE_SCORE_SWITCH_LIMIT = 0xFFF;
		static const auto MESSAGE_SCORE_SWITCH_TEAM = 17;
		ADD_OBJECT(TrFlagTeamRabbit, m_TeamRabbitFlag, 1460)
		ADD_STRUCT(int, m_nBuffAmount, 1468)
		ADD_STRUCT(byte, m_nBuffedTeamIndex, 1464)
		ADD_BOOL(m_bPlayedAnnouncerRally, 1456, 0x2)
		ADD_BOOL(m_bSpawnFlagOnNextKill, 1456, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90990);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90991);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetScores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90992);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90993);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnFlag(Vector SpawnLocation, Vector InitialVelocity)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90995);
			byte params[24] = { NULL };
			*(Vector*)params = SpawnLocation;
			*(Vector*)&params[12] = InitialVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Killed(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91007);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = KilledPlayer;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlagDestoyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91013);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PickedUpFlag(class Controller* Holder)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91014);
			byte params[4] = { NULL };
			*(class Controller**)params = Holder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DroppedFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91019);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardFlagHolder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91023);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91039);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91042);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91050);
			byte params[13] = { NULL };
			*(class PlayerStart**)params = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91056);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
