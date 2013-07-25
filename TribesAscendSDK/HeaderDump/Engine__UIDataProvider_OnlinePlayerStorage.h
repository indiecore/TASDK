#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
