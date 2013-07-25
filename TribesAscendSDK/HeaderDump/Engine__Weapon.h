#pragma once
#include "Engine__Inventory.h"
#include "Engine__Actor.h"
#include "Engine__AIController.h"
#include "Engine__HUD.h"
#include "Engine__Projectile.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Weapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Weapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Weapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Weapon : public Inventory
	{
	public:
		ADD_VAR(::BoolProperty, bInstantHit, 0x10)
		ADD_VAR(::FloatProperty, WeaponRange, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentFireMode, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CachedMaxRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AIRating, 0xFFFFFFFF)
		ADD_OBJECT(AIController, AIController)
		ADD_VAR(::FloatProperty, Priority, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultAnimSpeed, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bMeleeWeapon, 0x20)
		ADD_VAR(::BoolProperty, bWasDoNotActivate, 0x8)
		ADD_VAR(::BoolProperty, bWasOptionalSet, 0x4)
		ADD_VAR(::BoolProperty, bCanThrow, 0x2)
		ADD_VAR(::BoolProperty, bWeaponPutDown, 0x1)
		ADD_STRUCT(::VectorProperty, FireOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PutDownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EquipTime, 0xFFFFFFFF)
		float GetTraceRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetTraceRange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.HasAnyAmmo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float GetAIRating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetAIRating");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetWeaponRating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetWeaponRating");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool TryPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.TryPutDown");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool DenyClientWeaponSet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DenyClientWeaponSet");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CanAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.FireOnRelease");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.IsFiring");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanThrow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CanThrow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ItemRemovedFromInvManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ItemRemovedFromInvManager");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderDied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.HolderDied");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoOverrideNextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DoOverrideNextWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool DoOverridePrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DoOverridePrevWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DropFrom");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartLocation;
			*(Vector*)(params + 12) = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClientWeaponThrown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void GetWeaponDebug(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetWeaponDebug");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DebugInfo = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		int GetPendingFireLength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetPendingFireLength");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool PendingFire(int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PendingFire");
			byte* params = (byte*)malloc(8);
			*(int*)params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ConsumeAmmo");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.AddAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.HasAmmo");
			byte* params = (byte*)malloc(9);
			*params = FireModeNum;
			*(int*)(params + 4) = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetPendingFire(int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SetPendingFire");
			byte* params = (byte*)malloc(4);
			*(int*)params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPendingFire(int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClearPendingFire");
			byte* params = (byte*)malloc(4);
			*(int*)params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetProjectileClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		Rotator AddSpread(Rotator BaseAim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.AddSpread");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = BaseAim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		float MaxRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.MaxRange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		class AnimNodeSequence* GetWeaponAnimNodeSeq()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetWeaponAnimNodeSeq");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNodeSequence**)params;
			free(params);
			return returnVal;
		}
		void PlayWeaponAnimation(ScriptName Sequence, float fDesiredDuration, bool bLoop, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PlayWeaponAnimation");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = Sequence;
			*(float*)(params + 8) = fDesiredDuration;
			*(bool*)(params + 12) = bLoop;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopWeaponAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StopWeaponAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PlayFireEffects");
			byte* params = (byte*)malloc(13);
			*params = FireModeNum;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopFireEffects(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StopFireEffects");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetFireInterval");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void TimeWeaponFiring(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.TimeWeaponFiring");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefireCheckTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.RefireCheckTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.TimeWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponEquipping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.TimeWeaponEquipping");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PutDownWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DenyPickupQuery");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)(params + 4) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void WeaponEmpty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.WeaponEmpty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void IncrementFlashCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.IncrementFlashCount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearFlashCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClearFlashCount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFlashLocation(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SetFlashLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlashLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClearFlashLocation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.AttachWeaponTo");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)(params + 4) = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DetachWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClientGivenTo");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewOwner;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClientWeaponSet");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOptionalSet;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ServerStartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.BeginFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StopFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerStopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ServerStopFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.EndFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceEndFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ForceEndFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendToFiringState(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SendToFiringState");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCurrentFireMode(byte FiringModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SetCurrentFireMode");
			byte* params = (byte*)malloc(1);
			*params = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireModeUpdated(byte FiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.FireModeUpdated");
			byte* params = (byte*)malloc(5);
			*params = FiringMode;
			*(bool*)(params + 4) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetAdjustedAim");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetTraceOwner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* CalcWeaponFire(Vector StartTrace, Vector EndTrace, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ImpactList, Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CalcWeaponFire");
			byte* params = (byte*)malloc(128);
			*(Vector*)params = StartTrace;
			*(Vector*)(params + 12) = EndTrace;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24) = ImpactList;
			*(Vector*)(params + 36) = Extent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ImpactList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 48);
			free(params);
			return returnVal;
		}
		bool PassThroughDamage(class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PassThroughDamage");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, int NumHits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ProcessInstantHit");
			byte* params = (byte*)malloc(85);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(int*)(params + 84) = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		void CustomFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CustomFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetMuzzleLoc()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetMuzzleLoc");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetPhysicalFireStartLoc");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void HandleFinishedFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.HandleFinishedFiring");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyWeaponFired(byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.NotifyWeaponFired");
			byte* params = (byte*)malloc(1);
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyWeaponFinishedFiring(byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.NotifyWeaponFinishedFiring");
			byte* params = (byte*)malloc(1);
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldRefire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ShouldRefire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool StillFiring(byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StillFiring");
			byte* params = (byte*)malloc(5);
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void WeaponIsDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.WeaponIsDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CacheAIController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CacheAIController");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetTargetDistance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetTargetDistance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
