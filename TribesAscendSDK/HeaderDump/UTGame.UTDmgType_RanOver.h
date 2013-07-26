#pragma once
#include "UTGame.UTDamageType.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.Pawn.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDmgType_RanOver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTDmgType_RanOver : public UTDamageType
	{
	public:
		ADD_VAR(::IntProperty, NumMessages, 0xFFFFFFFF)
		int IncrementKills(class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_RanOver.IncrementKills");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void SmallReward(class UTPlayerController* Killer, int KillCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_RanOver.SmallReward");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = Killer;
			*(int*)(params + 4) = KillCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnHitEffect(class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_RanOver.SpawnHitEffect");
			byte* params = (byte*)malloc(40);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = Damage;
			*(Vector*)(params + 8) = Momentum;
			*(ScriptName*)(params + 20) = BoneName;
			*(Vector*)(params + 28) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
