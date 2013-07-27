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
		ADD_STRUCT(Vector, FireOffset, 660)
		ADD_STRUCT(float, PutDownTime, 656)
		ADD_STRUCT(float, EquipTime, 652)
		float GetTraceRange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8466);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18883);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float GetAIRating()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18885);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetWeaponRating()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18894);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool TryPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18915);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool DenyClientWeaponSet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18929);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20152);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20159);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20165);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanThrow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20471);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29299);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ItemRemovedFromInvManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29300);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderDied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29301);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoOverrideNextWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29302);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool DoOverridePrevWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29304);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29306);
			byte params[24] = { NULL };
			*(Vector*)params = StartLocation;
			*(Vector*)&params[12] = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29309);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29310);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void GetWeaponDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29317);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)params;
		}
		int GetPendingFireLength()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29322);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool PendingFire(int FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29323);
			byte params[8] = { NULL };
			*(int*)params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29324);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29326);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29329);
			byte params[9] = { NULL };
			*params = FireModeNum;
			*(int*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetPendingFire(int FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29336);
			byte params[4] = { NULL };
			*(int*)params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPendingFire(int FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29338);
			byte params[4] = { NULL };
			*(int*)params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29340);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		Rotator AddSpread(Rotator BaseAim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29342);
			byte params[24] = { NULL };
			*(Rotator*)params = BaseAim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		float MaxRange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29351);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		class AnimNodeSequence* GetWeaponAnimNodeSeq()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29355);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)params;
		}
		void PlayWeaponAnimation(ScriptName Sequence, float fDesiredDuration, bool bLoop, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29360);
			byte params[20] = { NULL };
			*(ScriptName*)params = Sequence;
			*(float*)&params[8] = fDesiredDuration;
			*(bool*)&params[12] = bLoop;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopWeaponAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29367);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29369);
			byte params[13] = { NULL };
			*params = FireModeNum;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFireEffects(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29372);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29374);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void TimeWeaponFiring(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29377);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefireCheckTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29379);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29380);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeWeaponEquipping()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29381);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Activate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29382);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29383);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29384);
			byte params[12] = { NULL };
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void WeaponEmpty()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29388);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void IncrementFlashCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29389);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearFlashCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29390);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFlashLocation(Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29391);
			byte params[12] = { NULL };
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29393);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29394);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29397);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29398);
			byte params[8] = { NULL };
			*(class Pawn**)params = NewOwner;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29401);
			byte params[8] = { NULL };
			*(bool*)params = bOptionalSet;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29404);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29406);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29408);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29410);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerStopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29412);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29414);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceEndFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29416);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendToFiringState(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29419);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentFireMode(byte FiringModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29421);
			byte params[1] = { NULL };
			*params = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireModeUpdated(byte FiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29423);
			byte params[5] = { NULL };
			*params = FiringMode;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29426);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29427);
			byte params[24] = { NULL };
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29431);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		Actor::ImpactInfo CalcWeaponFire(Vector StartTrace, Vector EndTrace, ScriptArray<Actor::ImpactInfo>& ImpactList, Vector Extent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29433);
			byte params[128] = { NULL };
			*(Vector*)params = StartTrace;
			*(Vector*)&params[12] = EndTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[24] = ImpactList;
			*(Vector*)&params[36] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactList = *(ScriptArray<Actor::ImpactInfo>*)&params[24];
			return *(Actor::ImpactInfo*)&params[48];
		}
		bool PassThroughDamage(class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29450);
			byte params[8] = { NULL };
			*(class Actor**)params = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit(byte FiringMode, Actor::ImpactInfo Impact, int NumHits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29460);
			byte params[85] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(int*)&params[84] = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29467);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		void CustomFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29475);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetMuzzleLoc()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29476);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29478);
			byte params[24] = { NULL };
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void HandleFinishedFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29515);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyWeaponFired(byte FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29516);
			byte params[1] = { NULL };
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyWeaponFinishedFiring(byte FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29518);
			byte params[1] = { NULL };
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldRefire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29520);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool StillFiring(byte FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29522);
			byte params[5] = { NULL };
			*params = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void WeaponIsDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29541);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CacheAIController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29548);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetTargetDistance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29549);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
