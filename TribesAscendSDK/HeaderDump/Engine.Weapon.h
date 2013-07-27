#pragma once
#include "Engine.Projectile.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.Inventory.h"
#include "Engine.HUD.h"
#include "Engine.AIController.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Weapon : public Inventory
	{
	public:
		enum EWeaponFireType : byte
		{
			EWFT_InstantHit = 0,
			EWFT_Projectile = 1,
			EWFT_Custom = 2,
			EWFT_None = 3,
			EWFT_MAX = 4,
		};
		ADD_BOOL(bInstantHit, 672, 0x10)
		ADD_STRUCT(float, WeaponRange, 676)
		ADD_STRUCT(byte, CurrentFireMode, 552)
		ADD_STRUCT(ScriptArray<ScriptName>, FiringStatesArray, 556)
		ADD_STRUCT(ScriptArray<Weapon::EWeaponFireType>, WeaponFireTypes, 568)
		ADD_STRUCT(ScriptArray<ScriptClass*>, WeaponProjectiles, 580)
		ADD_STRUCT(ScriptArray<float>, FireInterval, 592)
		ADD_STRUCT(ScriptArray<float>, Spread, 604)
		ADD_STRUCT(ScriptArray<float>, InstantHitDamage, 616)
		ADD_STRUCT(ScriptArray<float>, InstantHitMomentum, 628)
		ADD_STRUCT(ScriptArray<ScriptClass*>, InstantHitDamageTypes, 640)
		ADD_STRUCT(ScriptArray<byte>, ShouldFireOnRelease, 696)
		ADD_STRUCT(float, CachedMaxRange, 712)
		ADD_STRUCT(float, AIRating, 708)
		ADD_OBJECT(AIController, AIController, 692)
		ADD_STRUCT(float, Priority, 688)
		ADD_STRUCT(float, DefaultAnimSpeed, 684)
		ADD_BOOL(bMeleeWeapon, 672, 0x20)
		ADD_BOOL(bWasDoNotActivate, 672, 0x8)
		ADD_BOOL(bWasOptionalSet, 672, 0x4)
		ADD_BOOL(bCanThrow, 672, 0x2)
		ADD_BOOL(bWeaponPutDown, 672, 0x1)
		ADD_STRUCT(Object::Vector, FireOffset, 660)
		ADD_STRUCT(float, PutDownTime, 656)
		ADD_STRUCT(float, EquipTime, 652)
		float GetTraceRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetTraceRange");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.HasAnyAmmo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float GetAIRating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetAIRating");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetWeaponRating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetWeaponRating");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool TryPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.TryPutDown");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool DenyClientWeaponSet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DenyClientWeaponSet");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CanAttack");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.FireOnRelease");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.IsFiring");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanThrow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CanThrow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool DoOverridePrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DoOverridePrevWeapon");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void DropFrom(Object::Vector StartLocation, Object::Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DropFrom");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartLocation;
			*(Object::Vector*)&params[12] = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClientWeaponThrown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void GetWeaponDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetWeaponDebug");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)&params[0];
		}
		int GetPendingFireLength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetPendingFireLength");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool PendingFire(int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PendingFire");
			byte params[8] = { NULL };
			*(int*)&params[0] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ConsumeAmmo");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.AddAmmo");
			byte params[8] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.HasAmmo");
			byte params[9] = { NULL };
			params[0] = FireModeNum;
			*(int*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetPendingFire(int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SetPendingFire");
			byte params[4] = { NULL };
			*(int*)&params[0] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPendingFire(int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClearPendingFire");
			byte params[4] = { NULL };
			*(int*)&params[0] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetProjectileClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		Object::Rotator AddSpread(Object::Rotator BaseAim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.AddSpread");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = BaseAim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		float MaxRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.MaxRange");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		class AnimNodeSequence* GetWeaponAnimNodeSeq()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetWeaponAnimNodeSeq");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)&params[0];
		}
		void PlayWeaponAnimation(ScriptName Sequence, float fDesiredDuration, bool bLoop, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PlayWeaponAnimation");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = Sequence;
			*(float*)&params[8] = fDesiredDuration;
			*(bool*)&params[12] = bLoop;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopWeaponAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StopWeaponAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PlayFireEffects");
			byte params[13] = { NULL };
			params[0] = FireModeNum;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFireEffects(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StopFireEffects");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetFireInterval");
			byte params[5] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void TimeWeaponFiring(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.TimeWeaponFiring");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
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
		void SetFlashLocation(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SetFlashLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.DetachWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClientGivenTo");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = NewOwner;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ClientWeaponSet");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bOptionalSet;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ServerStartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.BeginFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StopFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerStopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ServerStopFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.EndFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceEndFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ForceEndFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendToFiringState(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SendToFiringState");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentFireMode(byte FiringModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.SetCurrentFireMode");
			byte params[1] = { NULL };
			params[0] = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireModeUpdated(byte FiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.FireModeUpdated");
			byte params[5] = { NULL };
			params[0] = FiringMode;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Rotator GetAdjustedAim(Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetAdjustedAim");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetTraceOwner");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		Actor::ImpactInfo CalcWeaponFire(Object::Vector StartTrace, Object::Vector EndTrace, ScriptArray<Actor::ImpactInfo>& ImpactList, Object::Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CalcWeaponFire");
			byte params[128] = { NULL };
			*(Object::Vector*)&params[0] = StartTrace;
			*(Object::Vector*)&params[12] = EndTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[24] = ImpactList;
			*(Object::Vector*)&params[36] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactList = *(ScriptArray<Actor::ImpactInfo>*)&params[24];
			return *(Actor::ImpactInfo*)&params[48];
		}
		bool PassThroughDamage(class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.PassThroughDamage");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit(byte FiringMode, Actor::ImpactInfo Impact, int NumHits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ProcessInstantHit");
			byte params[85] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(int*)&params[84] = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ProjectileFire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)&params[0];
		}
		void CustomFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.CustomFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Vector GetMuzzleLoc()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetMuzzleLoc");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		Object::Vector GetPhysicalFireStartLoc(Object::Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.GetPhysicalFireStartLoc");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		void HandleFinishedFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.HandleFinishedFiring");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyWeaponFired(byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.NotifyWeaponFired");
			byte params[1] = { NULL };
			params[0] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyWeaponFinishedFiring(byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.NotifyWeaponFinishedFiring");
			byte params[1] = { NULL };
			params[0] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldRefire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.ShouldRefire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool StillFiring(byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Weapon.StillFiring");
			byte params[5] = { NULL };
			params[0] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
