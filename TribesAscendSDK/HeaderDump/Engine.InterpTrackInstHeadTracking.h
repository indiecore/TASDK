#pragma once
#include "Engine.InterpTrackInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackInstHeadTracking." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstHeadTracking : public InterpTrackInst
	{
	public:
		ADD_VAR(::FloatProperty, LastUpdatePosition, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Action, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
