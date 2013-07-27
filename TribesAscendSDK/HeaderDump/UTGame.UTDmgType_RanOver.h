#pragma once
#include "UTGame.UTDamageType.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTDmgType_RanOver : public UTDamageType
	{
	public:
		ADD_STRUCT(int, NumMessages, 300)
		int IncrementKills(class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47098);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void SmallReward(class UTPlayerController* Killer, int KillCount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47102);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = Killer;
			*(int*)&params[4] = KillCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnHitEffect(class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47106);
			byte params[40] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = Damage;
			*(Vector*)&params[8] = Momentum;
			*(ScriptName*)&params[20] = BoneName;
			*(Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
