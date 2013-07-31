#pragma once
#include "Core.Object.h"
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
	class TrSpectatorHUDCache : public Object
	{
	public:
		ADD_BOOL(CachedPlayerPanelFlagCarried, 60, 0x1)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelPlayerName, 64)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelClassName, 76)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelNextRegen, 88)
		ADD_STRUCT(int, CachedPlayerPanelHealthBarFill, 100)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelHealth, 104)
		ADD_STRUCT(int, CachedPlayerPanelEnergyFillBar, 116)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelEnergy, 120)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelPrimaryWeaponName, 132)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelPrimaryAmmoCount, 144)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelSecondaryWeaponName, 156)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelSecondaryAmmoCount, 168)
		ADD_STRUCT(int, CachedPlayerPanelOffhandIcon, 180)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelOffhandAmmo, 184)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelOffhandName, 196)
		ADD_STRUCT(int, CachedPlayerPanelPackIcon, 208)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelPackAmmo, 212)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelPackName, 224)
		ADD_STRUCT(int, CachedPlayerPanelPerk1Icon, 236)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelPerk1Name, 240)
		ADD_STRUCT(int, CachedPlayerPanelPerk2Icon, 252)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelPerk2Name, 256)
		ADD_STRUCT(int, CachedPlayerPanelSkiFillBar, 268)
		ADD_STRUCT(ScriptString*, CachedPlayerPanelSkiSpeed, 272)
		ADD_STRUCT(int, CachedPlayerPanelSelected, 284)
		ADD_BOOL(CachedVehiclePanelFlagCarried, 60, 0x2)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelVehicleName, 288)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelDriverName, 300)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelPassengerName, 312)
		ADD_STRUCT(int, CachedVehiclePanelHealthFillBar, 324)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelHealth, 328)
		ADD_STRUCT(int, CachedVehiclePanelEnergyFillBar, 340)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelEnergy, 344)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelPrimaryWeaponName, 356)
		ADD_STRUCT(int, CachedVehiclePanelPrimaryWeaponReady, 368)
		ADD_BOOL(CachedVehiclePanelPrimaryWeaponVisible, 60, 0x4)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelSecondaryWeaponName, 372)
		ADD_STRUCT(int, CachedVehiclePanelSecondaryWeaponReady, 384)
		ADD_BOOL(CachedVehiclePanelSecondaryWeaponVisible, 60, 0x8)
		ADD_STRUCT(int, CachedVehiclePanelSkiFillBar, 388)
		ADD_STRUCT(ScriptString*, CachedVehiclePanelSkiSpeed, 392)
		ADD_STRUCT(int, CachedVehiclePanelSelected, 404)
		ADD_STRUCT(ScriptString*, CachedBookmarkPanelTitle, 408)
		ADD_STRUCT(ScriptString*, CachedBookmarkPanelName, 420)
		ADD_STRUCT(ScriptString*, CachedObjectivePanelObjectiveName, 432)
		ADD_STRUCT(ScriptString*, CachedObjectivePanelObjectiveDescription, 444)
		ADD_STRUCT(int, CachedObjectivePanelHealth, 460)
		ADD_STRUCT(ScriptString*, CachedFloatCameraPanelName, 464)
		ADD_STRUCT(ScriptString*, CachedFloatCameraPanelDescription, 476)
		ADD_STRUCT(int, CachedObjectivePanelHealthFillFrameIndex, 456)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
