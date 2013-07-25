#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ControlSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ControlSettings : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bWaitingForVYSensitivity, 0x8)
		ADD_VAR(::BoolProperty, bWaitingForVPSensitivity, 0x4)
		ADD_VAR(::BoolProperty, bWaitingForSensitivity, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForFOV, 0x1)
		ADD_VAR(::IntProperty, popupIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
