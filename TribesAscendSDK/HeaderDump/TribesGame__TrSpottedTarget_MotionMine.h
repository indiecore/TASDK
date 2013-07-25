#pragma once
#include "TribesGame__TrSpottedTarget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSpottedTarget_MotionMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSpottedTarget_MotionMine : public TrSpottedTarget
	{
	public:
		ADD_VAR(::FloatProperty, m_fMarkerBlinkSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentMarkerTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
