#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine__OnlinePlayerStorage.h"
#include "Engine__LocalPlayer.h"
#include "Engine__UIDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlinePlayerStorage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataProvider_OnlinePlayerStorage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerStorage : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_VAR(::IntProperty, DeviceStorageSizeNeeded, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasErrorLastRead, 0x1)
		ADD_VAR(::NameProperty, ProviderName, 0xFFFFFFFF)
		ADD_OBJECT(OnlinePlayerStorage, Profile)
		// Here lies the not-yet-implemented method 'ReadData'
		// Here lies the not-yet-implemented method 'WriteData'
		// Here lies the not-yet-implemented method 'GetData'
		// Here lies the not-yet-implemented method 'AddReadCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearReadCompleteDelegate'
		// Here lies the not-yet-implemented method 'OnRegister'
		// Here lies the not-yet-implemented method 'OnUnregister'
		// Here lies the not-yet-implemented method 'OnReadStorageComplete'
		// Here lies the not-yet-implemented method 'OnLoginChange'
		// Here lies the not-yet-implemented method 'RefreshStorageData'
		// Here lies the not-yet-implemented method 'OnDeviceSelectionComplete'
		// Here lies the not-yet-implemented method 'ArrayProviderPropertyChanged'
		// Here lies the not-yet-implemented method 'OnSettingValueUpdated'
		// Here lies the not-yet-implemented method 'OnStorageDeviceChange'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
