#pragma once
#include "Engine.PhysicsVolume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GravityVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GravityVolume : public PhysicsVolume
	{
	public:
		ADD_VAR(::FloatProperty, GravityZ, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
