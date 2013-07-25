#pragma once
#include "Engine.ForcedReachSpec.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MantleReachSpec." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MantleReachSpec : public ForcedReachSpec
	{
	public:
		ADD_VAR(::BoolProperty, bClimbUp, 0x1)
	};
}
#undef ADD_VAR
