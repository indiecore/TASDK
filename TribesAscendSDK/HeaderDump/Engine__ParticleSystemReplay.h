#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleSystemReplay." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleSystemReplay : public Object
	{
	public:
		ADD_VAR(::IntProperty, ClipIDNumber, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
