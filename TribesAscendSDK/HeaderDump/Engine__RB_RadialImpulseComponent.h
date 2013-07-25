#pragma once
#include "Engine__PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_RadialImpulseComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_RadialImpulseComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bCauseFracture, 0x2)
		ADD_VAR(::BoolProperty, bVelChange, 0x1)
		ADD_VAR(::FloatProperty, ImpulseRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpulseStrength, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ImpulseFalloff, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
