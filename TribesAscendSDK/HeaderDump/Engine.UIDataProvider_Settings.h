#pragma once
#include "Engine.UIDataProvider.h"
#include "Engine.UIDynamicDataProvider.h"
#include "Engine.Settings.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_Settings : public UIDynamicDataProvider
	{
	public:
		struct SettingsArrayProvider
		{
		public:
			ADD_OBJECT(UIDataProvider_SettingsArray, Provider, 12)
			ADD_STRUCT(ScriptName, SettingsName, 4)
			ADD_STRUCT(int, SettingsId, 0)
		};
		ADD_STRUCT(ScriptArray<UIDataProvider_Settings::SettingsArrayProvider>, SettingsArrayProviders, 128)
		ADD_BOOL(bIsAListRow, 140, 0x1)
		ADD_OBJECT(Settings, Settings, 124)
		void ArrayProviderPropertyChanged(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28413);
			byte params[12] = { NULL };
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)&params[4] = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSettingValueUpdated(ScriptName SettingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28418);
			byte params[8] = { NULL };
			*(ScriptName*)params = SettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
