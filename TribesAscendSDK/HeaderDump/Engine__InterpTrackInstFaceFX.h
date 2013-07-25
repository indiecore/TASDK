#pragma once
#include "Engine__InterpTrackInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackInstFaceFX." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstFaceFX : public InterpTrackInst
	{
	public:
		ADD_VAR(::FloatProperty, LastUpdatePosition, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFirstUpdate, 0x1)
	};
}
#undef ADD_VAR
