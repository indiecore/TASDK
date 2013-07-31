#pragma once
#include "TribesGame.TrDeployableHologram.h"
#include "TribesGame.TrDevice.h"
#include "Core.Object.h"
#include "TribesGame.TrDeployable.h"
#include "UTGame.UTPlayerController.h"
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
	class TrDevice_Deployable : public TrDevice
	{
	public:
		static const float DEPLOYMODE_GROUND_DELTA_CHECK_DIST;
		static const float DEPLOYMODE_MINIMUM_RADIUS_CHECK_DIST;
		ADD_STRUCT(Rotator, m_rDesiredPlacementRotation, 2212)
		ADD_STRUCT(Vector, m_vDesiredPlacementLocation, 2200)
		ADD_BOOL(m_bIgnoreCollisionForPlacement, 2196, 0x1)
		ADD_STRUCT(float, m_fOutsideCheckDistance, 2192)
		ADD_STRUCT(float, m_fOtherDeployableProximityCheck, 2188)
		ADD_STRUCT(Vector, m_vDeployVolumePlacementExtent, 2176)
		ADD_STRUCT(Vector, m_vPlacementExtent, 2164)
		ADD_STRUCT(float, m_fPlacementScale, 2160)
		ADD_STRUCT(int, m_nPerPlayerMaxDeployed, 2156)
		ADD_OBJECT(ScriptClass, c_DeployableHologramClass, 2152)
		ADD_OBJECT(TrDeployableHologram, c_DeployableHologram, 2148)
		int GetAmmoCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76442);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool CanAttemptDeploy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76468);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void UpdateDeployModeStatus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80741);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TickInHandWeapon(float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80742);
			byte params[4] = { NULL };
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrDeployable* Deploy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80744);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDeployable**)params;
		}
		bool IsValidDeployTerrain(Vector& OutLocation, Rotator& OutRotation, bool VerificationCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80746);
			byte params[32] = { NULL };
			*(Vector*)params = OutLocation;
			*(Rotator*)&params[12] = OutRotation;
			*(bool*)&params[24] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutLocation = *(Vector*)params;
			OutRotation = *(Rotator*)&params[12];
			return *(bool*)&params[28];
		}
		bool IsValidDeployVolume(Vector& OutLocation, Rotator& OutRotation, bool VerificationCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80751);
			byte params[32] = { NULL };
			*(Vector*)params = OutLocation;
			*(Rotator*)&params[12] = OutRotation;
			*(bool*)&params[24] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutLocation = *(Vector*)params;
			OutRotation = *(Rotator*)&params[12];
			return *(bool*)&params[28];
		}
		bool IsValidDeployProximity(Vector DeployLocation, bool VerificationCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80756);
			byte params[20] = { NULL };
			*(Vector*)params = DeployLocation;
			*(bool*)&params[12] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsValidOutsideCheck(Vector DeployLocation, bool VerificationCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80760);
			byte params[20] = { NULL };
			*(Vector*)params = DeployLocation;
			*(bool*)&params[12] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80764);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80766);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80767);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80768);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckInHandWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80769);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80770);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80771);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResumeInhandWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80772);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80774);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetMaxDeployedLimit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80777);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool IsDeployableOldest(class TrDeployable* OtherDep)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80782);
			byte params[8] = { NULL };
			*(class TrDeployable**)params = OtherDep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool BelowMaxCountLimit(bool bDestroyOldest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80788);
			byte params[8] = { NULL };
			*(bool*)params = bDestroyOldest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80797);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80799);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80802);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void EnterDeployMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80805);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDeployMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80807);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80809);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80812);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80816);
			byte params[4] = { NULL };
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnterDeployModeDisplay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80818);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDeployModeDisplay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80819);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80825);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsValidDesiredDeploy(Vector DesiredPlacement, Rotator DesiredRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80827);
			byte params[28] = { NULL };
			*(Vector*)params = DesiredPlacement;
			*(Rotator*)&params[12] = DesiredRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void ServerRequestDeploy(Vector DesiredPlacement, Rotator DesiredRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80831);
			byte params[24] = { NULL };
			*(Vector*)params = DesiredPlacement;
			*(Rotator*)&params[12] = DesiredRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CustomFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80836);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanAutoDeviceFireNow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80837);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80839);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80841);
			byte params[9] = { NULL };
			*params = FireModeNum;
			*(int*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
	const float TrDevice_Deployable::DEPLOYMODE_GROUND_DELTA_CHECK_DIST = 60.0f;
	const float TrDevice_Deployable::DEPLOYMODE_MINIMUM_RADIUS_CHECK_DIST = 30.0f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
