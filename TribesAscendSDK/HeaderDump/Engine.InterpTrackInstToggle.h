#pragma once
#include "Engine.InterpTrackInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackInstToggle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstToggle : public InterpTrackInst
	{
	public:
		ADD_VAR(::BoolProperty, bSavedActiveState, 0x1)
		ADD_VAR(::FloatProperty, LastUpdatePosition, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Action, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
