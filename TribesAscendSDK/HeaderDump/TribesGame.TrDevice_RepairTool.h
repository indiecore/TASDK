#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "TribesGame.TrDevice_ConstantFire.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDevice_RepairTool : public TrDevice_ConstantFire
	{
	public:
		ADD_STRUCT(Vector, m_Location, 2212)
		ADD_STRUCT(Vector, m_Tangent, 2200)
		ADD_STRUCT(float, m_fTargetHealth, 2196)
		ADD_STRUCT(float, m_fDisplayOn, 2192)
		ADD_BOOL(m_bIsBehindView, 2188, 0x1)
		ADD_STRUCT(float, m_fVehicleRepairPercentage, 2180)
		ADD_STRUCT(float, m_fPawnRepairPercentage, 2176)
		ADD_STRUCT(float, m_fRepairPercentage, 2172)
		bool CanActorBeRepaired(class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85852);
			byte params[8] = { NULL };
			*(class Actor**)params = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetActorHealth(class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85855);
			byte params[8] = { NULL };
			*(class Actor**)params = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		int GetAmmoCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85860);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void OnEndConstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85862);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartConstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85864);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85865);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit_Internal(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85874);
			byte params[85] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetRepairEndAndTangent(Vector& EndLocation, Vector& Tangent, class Actor*& HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85889);
			byte params[32] = { NULL };
			*(Vector*)params = EndLocation;
			*(Vector*)&params[12] = Tangent;
			*(class Actor**)&params[24] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			EndLocation = *(Vector*)params;
			Tangent = *(Vector*)&params[12];
			HitActor = *(class Actor**)&params[24];
			return *(bool*)&params[28];
		}
		void KillRepairEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85897);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HasViewModeSwitched()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85898);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SpawnRepairEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85902);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateRepairEffect(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85909);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDamageMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85914);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, Actor::ImpactInfo Impact, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85917);
			byte params[89] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(float*)&params[84] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[88];
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85933);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
