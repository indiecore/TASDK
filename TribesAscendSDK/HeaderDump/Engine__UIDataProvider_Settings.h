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
		void ArrayProviderPropertyChanged(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_Settings.ArrayProviderPropertyChanged");
			byte* params = (byte*)malloc(12);
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)(params + 4) = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSettingValueUpdated(ScriptName SettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_Settings.OnSettingValueUpdated");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SettingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
