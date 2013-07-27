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
		ADD_STRUCT(Object::Rotator, m_rDesiredPlacementRotation, 2212)
		ADD_STRUCT(Object::Vector, m_vDesiredPlacementLocation, 2200)
		ADD_BOOL(m_bIgnoreCollisionForPlacement, 2196, 0x1)
		ADD_STRUCT(float, m_fOutsideCheckDistance, 2192)
		ADD_STRUCT(float, m_fOtherDeployableProximityCheck, 2188)
		ADD_STRUCT(Object::Vector, m_vDeployVolumePlacementExtent, 2176)
		ADD_STRUCT(Object::Vector, m_vPlacementExtent, 2164)
		ADD_STRUCT(float, m_fPlacementScale, 2160)
		ADD_STRUCT(int, m_nPerPlayerMaxDeployed, 2156)
		ADD_OBJECT(ScriptClass, c_DeployableHologramClass, 2152)
		ADD_OBJECT(TrDeployableHologram, c_DeployableHologram, 2148)
		int GetAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.GetAmmoCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool CanAttemptDeploy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.CanAttemptDeploy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void UpdateDeployModeStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.UpdateDeployModeStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TickInHandWeapon(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.TickInHandWeapon");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrDeployable* Deploy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.Deploy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDeployable**)&params[0];
		}
		bool IsValidDeployTerrain(Object::Vector& OutLocation, Object::Rotator& OutRotation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDeployTerrain");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = OutLocation;
			*(Object::Rotator*)&params[12] = OutRotation;
			*(bool*)&params[24] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutLocation = *(Object::Vector*)&params[0];
			OutRotation = *(Object::Rotator*)&params[12];
			return *(bool*)&params[28];
		}
		bool IsValidDeployVolume(Object::Vector& OutLocation, Object::Rotator& OutRotation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDeployVolume");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = OutLocation;
			*(Object::Rotator*)&params[12] = OutRotation;
			*(bool*)&params[24] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutLocation = *(Object::Vector*)&params[0];
			OutRotation = *(Object::Rotator*)&params[12];
			return *(bool*)&params[28];
		}
		bool IsValidDeployProximity(Object::Vector DeployLocation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDeployProximity");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = DeployLocation;
			*(bool*)&params[12] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsValidOutsideCheck(Object::Vector DeployLocation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidOutsideCheck");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = DeployLocation;
			*(bool*)&params[12] = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.UpdateReplicatedCarriedAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.OnSwitchToWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckInHandWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.CheckInHandWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.HolderEnteredVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResumeInhandWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ResumeInhandWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.TryPutDown");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetMaxDeployedLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.GetMaxDeployedLimit");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool IsDeployableOldest(class TrDeployable* OtherDep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsDeployableOldest");
			byte params[8] = { NULL };
			*(class TrDeployable**)&params[0] = OtherDep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool BelowMaxCountLimit(bool bDestroyOldest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.BelowMaxCountLimit");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bDestroyOldest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ConsumeAmmo");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.AddCarriedAmmo");
			byte params[8] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.AddAmmo");
			byte params[8] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void EnterDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.EnterDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ExitDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.AttachWeaponTo");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.EndZoom");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ChangeVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnterDeployModeDisplay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.EnterDeployModeDisplay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDeployModeDisplay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ExitDeployModeDisplay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsValidDesiredDeploy(Object::Vector DesiredPlacement, Object::Rotator DesiredRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDesiredDeploy");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = DesiredPlacement;
			*(Object::Rotator*)&params[12] = DesiredRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void ServerRequestDeploy(Object::Vector DesiredPlacement, Object::Rotator DesiredRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ServerRequestDeploy");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = DesiredPlacement;
			*(Object::Rotator*)&params[12] = DesiredRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CustomFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.CustomFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanAutoDeviceFireNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.CanAutoDeviceFireNow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.HasAnyAmmo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.HasAmmo");
			byte params[9] = { NULL };
			params[0] = FireModeNum;
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
