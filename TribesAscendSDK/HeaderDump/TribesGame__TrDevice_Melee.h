#pragma once
#include "TribesGame__TrDevice_AutoFire.h"
#include "TribesGame__TrPawn.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_Melee." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Melee : public TrDevice_AutoFire
	{
	public:
		ADD_OBJECT(AnimNodeSequence, FiringAnimSeqNode)
		void OwningClientPlayHit(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.OwningClientPlayHit");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFireAnimation(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.PlayFireAnimation");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int CalcAmountToLoad()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.CalcAmountToLoad");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.HasAmmo");
			byte* params = (byte*)malloc(9);
			*params = FireModeNum;
			*(int*)(params + 4) = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		float GetBuildUpTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.GetBuildUpTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.ModifyInstantHitDamage");
			byte* params = (byte*)malloc(89);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(float*)(params + 84) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 88);
			free(params);
			return returnVal;
		}
		void AttemptFlagFumble(class TrPawn* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Melee.AttemptFlagFumble");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
