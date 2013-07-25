#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlinePlayerStorage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePlayerStorage : public Object
	{
	public:
		ADD_VAR(::IntProperty, DeviceID, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AsyncState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VersionNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VersionSettingsId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetProfileSettingId'
		// Here lies the not-yet-implemented method 'GetProfileSettingName'
		// Here lies the not-yet-implemented method 'GetProfileSettingColumnHeader'
		// Here lies the not-yet-implemented method 'FindProfileSettingIndex'
		// Here lies the not-yet-implemented method 'FindProfileMappingIndex'
		// Here lies the not-yet-implemented method 'FindProfileMappingIndexByName'
		// Here lies the not-yet-implemented method 'FindDefaultProfileMappingIndexByName'
		// Here lies the not-yet-implemented method 'IsProfileSettingIdMapped'
		// Here lies the not-yet-implemented method 'GetProfileSettingValue'
		// Here lies the not-yet-implemented method 'GetProfileSettingValueName'
		// Here lies the not-yet-implemented method 'GetProfileSettingValues'
		// Here lies the not-yet-implemented method 'GetProfileSettingValueByName'
		// Here lies the not-yet-implemented method 'SetProfileSettingValueByName'
		// Here lies the not-yet-implemented method 'SetProfileSettingValue'
		// Here lies the not-yet-implemented method 'GetProfileSettingValueId'
		// Here lies the not-yet-implemented method 'GetProfileSettingValueFromListIndex'
		// Here lies the not-yet-implemented method 'GetProfileSettingValueInt'
		// Here lies the not-yet-implemented method 'GetProfileSettingValueFloat'
		// Here lies the not-yet-implemented method 'SetProfileSettingValueId'
		// Here lies the not-yet-implemented method 'SetProfileSettingValueInt'
		// Here lies the not-yet-implemented method 'SetProfileSettingValueFloat'
		// Here lies the not-yet-implemented method 'GetProfileSettingMappingType'
		// Here lies the not-yet-implemented method 'GetProfileSettingMappingIds'
		// Here lies the not-yet-implemented method 'GetProfileSettingRange'
		// Here lies the not-yet-implemented method 'SetRangedProfileSettingValue'
		// Here lies the not-yet-implemented method 'GetRangedProfileSettingValue'
		// Here lies the not-yet-implemented method 'AddSettingInt'
		// Here lies the not-yet-implemented method 'AddSettingFloat'
		// Here lies the not-yet-implemented method 'SetToDefaults'
		// Here lies the not-yet-implemented method 'AppendVersionToSettings'
		// Here lies the not-yet-implemented method 'GetVersionNumber'
		// Here lies the not-yet-implemented method 'SetDefaultVersionNumber'
	};
}
#undef ADD_VAR
