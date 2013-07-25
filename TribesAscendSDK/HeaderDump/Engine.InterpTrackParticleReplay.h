#pragma once
#include "Engine.InterpTrack.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackParticleReplay." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackParticleReplay : public InterpTrack
	{
	public:
		ADD_VAR(::FloatProperty, FixedTimeStep, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsCapturingReplay, 0x1)
	};
}
#undef ADD_VAR
