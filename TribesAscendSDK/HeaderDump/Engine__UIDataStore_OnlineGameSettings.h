#pragma once
#include "Engine__UIDataStore_Settings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlineGameSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_OnlineGameSettings : public UIDataStore_Settings
	{
	public:
		ADD_VAR(::IntProperty, SelectedIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
