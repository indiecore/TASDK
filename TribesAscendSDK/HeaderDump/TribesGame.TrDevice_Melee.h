#pragma once
#include "TribesGame.TrDevice_AutoFire.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.AnimNodeSequence.h"
#include "TribesGame.TrPawn.h"
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
	class TrDevice_Melee : public TrDevice_AutoFire
	{
	public:
		struct MeleeRandomAnimation
		{
		public:
			ADD_OBJECT(CameraAnim, FireCameraAnim, 8)
			ADD_STRUCT(ScriptName, FireAnimName, 0)
		};
		ADD_STRUCT(ScriptArray<Actor::ImpactInfo>, PendingImpactList, 2164)
		ADD_STRUCT(ScriptArray<TrDevice_Melee::MeleeRandomAnimation>, FiringAnimRandomList, 2176)
		ADD_OBJECT(AnimNodeSequence, FiringAnimSeqNode, 2188)
		void OwningClientPlayHit(Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83116);
			byte params[12] = { NULL };
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireAnimation(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83119);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int CalcAmountToLoad()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83123);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83125);
			byte params[9] = { NULL };
			*params = FireModeNum;
			*(int*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		float GetBuildUpTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83129);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83131);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, Actor::ImpactInfo Impact, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83151);
			byte params[89] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(float*)&params[84] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[88];
		}
		void AttemptFlagFumble(class TrPawn* Victim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83161);
			byte params[4] = { NULL };
			*(class TrPawn**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
