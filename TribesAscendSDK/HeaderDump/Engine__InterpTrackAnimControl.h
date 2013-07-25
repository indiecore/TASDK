#pragma once
#include "Engine__InterpTrackFloatBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackAnimControl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackAnimControl : public InterpTrackFloatBase
	{
	public:
		ADD_VAR(::BoolProperty, bEnableRootMotion, 0x1)
		ADD_VAR(::NameProperty, SlotName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
