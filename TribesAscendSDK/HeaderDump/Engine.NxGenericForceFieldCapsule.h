#pragma once
#include "Engine.NxGenericForceField.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxGenericForceFieldCapsule." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceFieldCapsule : public NxGenericForceField
	{
	public:
		ADD_VAR(::FloatProperty, CapsuleRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CapsuleHeight, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
