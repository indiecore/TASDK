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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_RanOver.IncrementKills");
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void SmallReward(class UTPlayerController* Killer, int KillCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_RanOver.SmallReward");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = Killer;
			*(int*)&params[4] = KillCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnHitEffect(class Pawn* P, float Damage, Object::Vector Momentum, ScriptName BoneName, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_RanOver.SpawnHitEffect");
			byte params[40] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(float*)&params[4] = Damage;
			*(Object::Vector*)&params[8] = Momentum;
			*(ScriptName*)&params[20] = BoneName;
			*(Object::Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
