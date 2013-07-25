#pragma once
#include "TribesGame__TrDevice_ConstantFire.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_RepairTool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice_RepairTool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_RepairTool : public TrDevice_ConstantFire
	{
	public:
		ADD_STRUCT(::VectorProperty, m_Location, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_Tangent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTargetHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDisplayOn, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsBehindView, 0x1)
		ADD_VAR(::FloatProperty, m_fVehicleRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairPercentage, 0xFFFFFFFF)
		bool CanActorBeRepaired(class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.CanActorBeRepaired");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetActorHealth(class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.GetActorHealth");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.GetAmmoCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void OnEndConstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.OnEndConstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartConstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.OnStartConstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit_Internal(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, bool bHeadShot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.ProcessInstantHit_Internal");
			byte* params = (byte*)malloc(85);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(bool*)(params + 84) = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetRepairEndAndTangent(Vector& EndLocation, Vector& Tangent, class Actor*& HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.GetRepairEndAndTangent");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = EndLocation;
			*(Vector*)(params + 12) = Tangent;
			*(class Actor**)(params + 24) = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			EndLocation = *(Vector*)params;
			Tangent = *(Vector*)(params + 12);
			HitActor = *(class Actor**)(params + 24);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void KillRepairEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.KillRepairEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HasViewModeSwitched()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.HasViewModeSwitched");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SpawnRepairEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.SpawnRepairEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateRepairEffect(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.UpdateRepairEffect");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDamageMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.UpdateDamageMaterial");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.ModifyInstantHitDamage");
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
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RepairTool.HasAnyAmmo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
