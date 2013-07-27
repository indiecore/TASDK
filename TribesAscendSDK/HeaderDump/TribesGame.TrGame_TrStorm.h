#pragma once
#include "TribesGame.TrGame.h"
#include "TribesGame.TrStormCarrierShield.h"
#include "TribesGame.TrStormCore.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrStormControlPoint.h"
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
	class TrGame_TrStorm : public TrGame
	{
	public:
		class Missile
		{
		public:
			ADD_STRUCT(byte, TargetTeam, 8)
			ADD_STRUCT(float, RemainingFlightTime, 4)
			ADD_OBJECT(TrStormControlPoint, FiredFrom, 0)
		};
		class Carrier
		{
		public:
			ADD_STRUCT(byte, TeamNum, 8)
			ADD_STRUCT(int, CoreHealth, 4)
			ADD_STRUCT(int, ShieldHealth, 0)
		};
		ADD_STRUCT(ScriptArray<TrGame_TrStorm::Missile>, m_fActiveMissiles, 1480)
		ADD_STRUCT(float, MatchEndingTime, 1520)
		ADD_STRUCT(int, m_nMaxCoreHealth, 1516)
		ADD_STRUCT(int, m_nMaxShieldHealth, 1512)
		ADD_OBJECT(TrStormCore, m_CarrierCore, 1504)
		ADD_OBJECT(TrStormCarrierShield, m_CarrierShields, 1496)
		ADD_STRUCT(float, m_fMissileDamageAmount, 1492)
		ADD_STRUCT(TrGame_TrStorm::Carrier, m_Carriers, 1456)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MissileFired(class TrStormControlPoint* FiredFrom, float TimeTillExplosion, byte TargetTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.MissileFired");
			byte params[9] = { NULL };
			*(class TrStormControlPoint**)&params[0] = FiredFrom;
			*(float*)&params[4] = TimeTillExplosion;
			params[8] = TargetTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ExplodeMissile(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.ExplodeMissile");
			byte params[1] = { NULL };
			params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeHealthDamage(byte TeamNum, int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.TakeHealthDamage");
			byte params[5] = { NULL };
			params[0] = TeamNum;
			*(int*)&params[4] = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CarrierDestroyed(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.CarrierDestroyed");
			byte params[1] = { NULL };
			params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamageFromCore(byte TeamNum, int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.TakeDamageFromCore");
			byte params[5] = { NULL };
			params[0] = TeamNum;
			*(int*)&params[4] = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.CheckEndGame");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.EndGame");
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.DetermineWinningTeam");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
