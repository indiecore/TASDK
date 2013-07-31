#pragma once
#include "UTGame.UTDamageType.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class UTDmgType_Burning : public UTDamageType
	{
	public:
		void SpawnHitEffect(class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47069);
			byte params[40] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = Damage;
			*(Vector*)&params[8] = Momentum;
			*(ScriptName*)&params[20] = BoneName;
			*(Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetHitEffectDuration(class Pawn* P, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47080);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
