#pragma once
#include "TribesGame.TrDeployableHologram.h"
#include "Core.Object.Vector.h"
#include "TribesGame.TrDevice.h"
#include "Core.Object.Rotator.h"
#include "TribesGame.TrDeployable.h"
#include "UTGame.UTPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_Deployable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDevice_Deployable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_Deployable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Deployable : public TrDevice
	{
	public:
		ADD_STRUCT(::RotatorProperty, m_rDesiredPlacementRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vDesiredPlacementLocation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIgnoreCollisionForPlacement, 0x1)
		ADD_VAR(::FloatProperty, m_fOutsideCheckDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOtherDeployableProximityCheck, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vDeployVolumePlacementExtent, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vPlacementExtent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPlacementScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPerPlayerMaxDeployed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, c_DeployableHologramClass)
		ADD_OBJECT(TrDeployableHologram, c_DeployableHologram)
		int GetAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.GetAmmoCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool CanAttemptDeploy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.CanAttemptDeploy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void UpdateDeployModeStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.UpdateDeployModeStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TickInHandWeapon(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.TickInHandWeapon");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrDeployable* Deploy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.Deploy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDeployable**)params;
			free(params);
			return returnVal;
		}
		bool IsValidDeployTerrain(Vector& OutLocation, Rotator& OutRotation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDeployTerrain");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = OutLocation;
			*(Rotator*)(params + 12) = OutRotation;
			*(bool*)(params + 24) = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutLocation = *(Vector*)params;
			OutRotation = *(Rotator*)(params + 12);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool IsValidDeployVolume(Vector& OutLocation, Rotator& OutRotation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDeployVolume");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = OutLocation;
			*(Rotator*)(params + 12) = OutRotation;
			*(bool*)(params + 24) = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutLocation = *(Vector*)params;
			OutRotation = *(Rotator*)(params + 12);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool IsValidDeployProximity(Vector DeployLocation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDeployProximity");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = DeployLocation;
			*(bool*)(params + 12) = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsValidOutsideCheck(Vector DeployLocation, bool VerificationCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidOutsideCheck");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = DeployLocation;
			*(bool*)(params + 12) = VerificationCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetMaxDeployedLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.GetMaxDeployedLimit");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool IsDeployableOldest(class TrDeployable* OtherDep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsDeployableOldest");
			byte* params = (byte*)malloc(8);
			*(class TrDeployable**)params = OtherDep;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool BelowMaxCountLimit(bool bDestroyOldest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.BelowMaxCountLimit");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bDestroyOldest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ConsumeAmmo");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.AddCarriedAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.AddAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)(params + 4) = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.EndZoom");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			*(bool*)(params + 4) = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ChangeVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsValidDesiredDeploy(Vector DesiredPlacement, Rotator DesiredRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.IsValidDesiredDeploy");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = DesiredPlacement;
			*(Rotator*)(params + 12) = DesiredRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void ServerRequestDeploy(Vector DesiredPlacement, Rotator DesiredRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.ServerRequestDeploy");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = DesiredPlacement;
			*(Rotator*)(params + 12) = DesiredRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CustomFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.CustomFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanAutoDeviceFireNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.CanAutoDeviceFireNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.HasAnyAmmo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Deployable.HasAmmo");
			byte* params = (byte*)malloc(9);
			*params = FireModeNum;
			*(int*)(params + 4) = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
