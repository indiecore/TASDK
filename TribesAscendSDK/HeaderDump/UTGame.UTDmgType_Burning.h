#pragma once
#include "UTGame.UTDamageType.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTDmgType_Burning : public UTDamageType
	{
	public:
		void SpawnHitEffect(class Pawn* P, float Damage, Object::Vector Momentum, ScriptName BoneName, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_Burning.SpawnHitEffect");
			byte params[40] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(float*)&params[4] = Damage;
			*(Object::Vector*)&params[8] = Momentum;
			*(ScriptName*)&params[20] = BoneName;
			*(Object::Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetHitEffectDuration(class Pawn* P, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_Burning.GetHitEffectDuration");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(float*)&params[4] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
