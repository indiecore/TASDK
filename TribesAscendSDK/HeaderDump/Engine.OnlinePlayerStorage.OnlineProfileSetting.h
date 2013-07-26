#pragma once
#include "Engine.Settings.SettingsProperty.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlinePlayerStorage.OnlineProfileSetting." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlinePlayerStorage.OnlineProfileSetting." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineProfileSetting
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<SettingsProperty>, ProfileSetting, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Owner, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
