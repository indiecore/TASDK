#pragma once
#include "UTGame.UTDamageType.h"
#include "Engine.Pawn.h"
#include "Core.Object.Vector.h"
namespace UnrealScript
{
	class UTDmgType_Burning : public UTDamageType
	{
	public:
		void SpawnHitEffect(class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_Burning.SpawnHitEffect");
			byte* params = (byte*)malloc(40);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = Damage;
			*(Vector*)(params + 8) = Momentum;
			*(ScriptName*)(params + 20) = BoneName;
			*(Vector*)(params + 28) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetHitEffectDuration(class Pawn* P, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_Burning.GetHitEffectDuration");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
