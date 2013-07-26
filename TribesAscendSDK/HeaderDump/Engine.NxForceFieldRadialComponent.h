#pragma once
#include "Engine.NxForceFieldComponent.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxForceFieldRadialComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxForceFieldRadialComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxForceFieldRadialComponent : public NxForceFieldComponent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Kernel, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ForceFalloff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelfRotationStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceStrength, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
