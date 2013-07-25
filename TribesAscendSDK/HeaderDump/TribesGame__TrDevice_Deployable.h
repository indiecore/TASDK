#pragma once
#include "TribesGame__TrDevice.h"
#include "UTGame__UTPlayerController.h"
#include "TribesGame__TrDeployableHologram.h"
#include "TribesGame__TrDeployable.h"
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
		ADD_STRUCT(::RotatorProperty, m_rDesiredPlacementRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vDesiredPlacementLocation, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, m_bIgnoreCollisionForPlacement, 0x1)
		ADD_VAR(::FloatProperty, m_fOutsideCheckDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOtherDeployableProximityCheck, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vDeployVolumePlacementExtent, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vPlacementExtent, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fPlacementScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPerPlayerMaxDeployed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, c_DeployableHologramClass)
		ADD_OBJECT(TrDeployableHologram, c_DeployableHologram)
		// Here lies the not-yet-implemented method 'GetAmmoCount'
		// Here lies the not-yet-implemented method 'CanAttemptDeploy'
		// Here lies the not-yet-implemented method 'UpdateDeployModeStatus'
		// Here lies the not-yet-implemented method 'TickInHandWeapon'
		// Here lies the not-yet-implemented method 'Deploy'
		// Here lies the not-yet-implemented method 'IsValidDeployTerrain'
		// Here lies the not-yet-implemented method 'IsValidDeployVolume'
		// Here lies the not-yet-implemented method 'IsValidDeployProximity'
		// Here lies the not-yet-implemented method 'IsValidOutsideCheck'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'UpdateReplicatedCarriedAmmo'
		// Here lies the not-yet-implemented method 'OnSwitchToWeapon'
		// Here lies the not-yet-implemented method 'OnSwitchAwayFromWeapon'
		// Here lies the not-yet-implemented method 'CheckInHandWeapon'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'HolderEnteredVehicle'
		// Here lies the not-yet-implemented method 'ResumeInhandWeapon'
		// Here lies the not-yet-implemented method 'TryPutDown'
		// Here lies the not-yet-implemented method 'GetMaxDeployedLimit'
		// Here lies the not-yet-implemented method 'IsDeployableOldest'
		// Here lies the not-yet-implemented method 'BelowMaxCountLimit'
		// Here lies the not-yet-implemented method 'ConsumeAmmo'
		// Here lies the not-yet-implemented method 'AddCarriedAmmo'
		// Here lies the not-yet-implemented method 'AddAmmo'
		// Here lies the not-yet-implemented method 'EnterDeployMode'
		// Here lies the not-yet-implemented method 'ExitDeployMode'
		// Here lies the not-yet-implemented method 'AttachWeaponTo'
		// Here lies the not-yet-implemented method 'EndZoom'
		// Here lies the not-yet-implemented method 'ChangeVisibility'
		// Here lies the not-yet-implemented method 'EnterDeployModeDisplay'
		// Here lies the not-yet-implemented method 'ExitDeployModeDisplay'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'IsValidDesiredDeploy'
		// Here lies the not-yet-implemented method 'ServerRequestDeploy'
		// Here lies the not-yet-implemented method 'CustomFire'
		// Here lies the not-yet-implemented method 'CanAutoDeviceFireNow'
		// Here lies the not-yet-implemented method 'HasAnyAmmo'
		// Here lies the not-yet-implemented method 'HasAmmo'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
