#pragma once
#include "Core.Factory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UnrealEd.SoundSurroundFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundSurroundFactory : public Factory
	{
	public:
		ADD_VAR(::FloatProperty, CueVolume, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
