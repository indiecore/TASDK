#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_KeybindAction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_KeybindAction : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bWaitingForKeybind, 0x1)
		ADD_VAR(::IntProperty, SelectedCommand, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SelectedIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
