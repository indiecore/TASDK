#pragma once
#include "Engine.Keypoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AmbientSound." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AmbientSound : public Keypoint
	{
	public:
		ADD_VAR(::BoolProperty, bIsPlaying, 0x2)
		ADD_VAR(::BoolProperty, bAutoPlay, 0x1)
	};
}
#undef ADD_VAR
