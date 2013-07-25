#pragma once
#include "TribesGame.TrGame.h"
#include "TribesGame.TrStormCarrierShield.h"
#include "TribesGame.TrStormCore.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrStormControlPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrStorm." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrGame_TrStorm." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TrStorm." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TrStorm : public TrGame
	{
	public:
		ADD_VAR(::FloatProperty, MatchEndingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxCoreHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxShieldHealth, 0xFFFFFFFF)
		ADD_OBJECT(TrStormCore, m_CarrierCore)
		ADD_OBJECT(TrStormCarrierShield, m_CarrierShields)
		ADD_VAR(::FloatProperty, m_fMissileDamageAmount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrGame_TrStorm.Carrier' for the property named 'm_Carriers'!
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MissileFired(class TrStormControlPoint* FiredFrom, float TimeTillExplosion, byte TargetTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.MissileFired");
			byte* params = (byte*)malloc(9);
			*(class TrStormControlPoint**)params = FiredFrom;
			*(float*)(params + 4) = TimeTillExplosion;
			*(params + 8) = TargetTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ExplodeMissile(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.ExplodeMissile");
			byte* params = (byte*)malloc(1);
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeHealthDamage(byte TeamNum, int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.TakeHealthDamage");
			byte* params = (byte*)malloc(5);
			*params = TeamNum;
			*(int*)(params + 4) = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CarrierDestroyed(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.CarrierDestroyed");
			byte* params = (byte*)malloc(1);
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamageFromCore(byte TeamNum, int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.TakeDamageFromCore");
			byte* params = (byte*)malloc(5);
			*params = TeamNum;
			*(int*)(params + 4) = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.EndGame");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrStorm.DetermineWinningTeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
