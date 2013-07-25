#pragma once
#include "Engine__UIDynamicDataProvider.h"
#include "Engine__Settings.h"
#include "Engine__UIDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_Settings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataProvider_Settings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_Settings : public UIDynamicDataProvider
	{
	public:
		ADD_VAR(::BoolProperty, bIsAListRow, 0x1)
		ADD_OBJECT(Settings, Settings)
		// Here lies the not-yet-implemented method 'ArrayProviderPropertyChanged'
		// Here lies the not-yet-implemented method 'OnSettingValueUpdated'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
