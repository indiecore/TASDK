#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSpectatorHUDCache." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSpectatorHUDCache : public Object
	{
	public:
		ADD_VAR(::BoolProperty, CachedPlayerPanelFlagCarried, 0x1)
		ADD_VAR(::StrProperty, CachedPlayerPanelPlayerName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelNextRegen, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelHealthBarFill, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelEnergyFillBar, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelEnergy, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelPrimaryWeaponName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelPrimaryAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelSecondaryWeaponName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelSecondaryAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelOffhandIcon, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelOffhandAmmo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelOffhandName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelPackIcon, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelPackAmmo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelPackName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelPerk1Icon, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelPerk1Name, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelPerk2Icon, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelPerk2Name, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelSkiFillBar, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedPlayerPanelSkiSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedPlayerPanelSelected, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, CachedVehiclePanelFlagCarried, 0x2)
		ADD_VAR(::StrProperty, CachedVehiclePanelVehicleName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedVehiclePanelDriverName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedVehiclePanelPassengerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedVehiclePanelHealthFillBar, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedVehiclePanelHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedVehiclePanelEnergyFillBar, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedVehiclePanelEnergy, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedVehiclePanelPrimaryWeaponName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedVehiclePanelPrimaryWeaponReady, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, CachedVehiclePanelPrimaryWeaponVisible, 0x4)
		ADD_VAR(::StrProperty, CachedVehiclePanelSecondaryWeaponName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedVehiclePanelSecondaryWeaponReady, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, CachedVehiclePanelSecondaryWeaponVisible, 0x8)
		ADD_VAR(::IntProperty, CachedVehiclePanelSkiFillBar, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedVehiclePanelSkiSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedVehiclePanelSelected, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedBookmarkPanelTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedBookmarkPanelName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedObjectivePanelObjectiveName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedObjectivePanelObjectiveDescription, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedObjectivePanelHealth, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedFloatCameraPanelName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachedFloatCameraPanelDescription, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedObjectivePanelHealthFillFrameIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
