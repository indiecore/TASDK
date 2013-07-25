#pragma once
#include "TribesGame.TrGame.h"
#include "TribesGame.TrFlagTeamRabbit.h"
#include "Engine.PlayerStart.h"
#include "Engine.Controller.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TRTeamRabbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRTeamRabbit." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRTeamRabbit : public TrGame
	{
	public:
		ADD_OBJECT(TrFlagTeamRabbit, m_TeamRabbitFlag)
		ADD_VAR(::IntProperty, m_nBuffAmount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_nBuffedTeamIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bPlayedAnnouncerRally, 0x2)
		ADD_VAR(::BoolProperty, m_bSpawnFlagOnNextKill, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.ResetLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.ResetScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnFlag(Vector SpawnLocation, Vector InitialVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.SpawnFlag");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = SpawnLocation;
			*(Vector*)(params + 12) = InitialVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Killed(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.Killed");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = KilledPlayer;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlagDestoyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.FlagDestoyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PickedUpFlag(class Controller* Holder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.PickedUpFlag");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Holder;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DroppedFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.DroppedFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardFlagHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.AwardFlagHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.RatePlayerStart");
			byte* params = (byte*)malloc(13);
			*(class PlayerStart**)params = P;
			*(params + 4) = Team;
			*(class Controller**)(params + 8) = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTeamRabbit.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
