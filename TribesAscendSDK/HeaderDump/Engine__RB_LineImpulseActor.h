#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_LineImpulseActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_LineImpulseActor : public RigidBodyBase
	{
	public:
		ADD_VAR(::ByteProperty, ImpulseCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCauseFracture, 0x4)
		ADD_VAR(::BoolProperty, bStopAtFirstHit, 0x2)
		ADD_VAR(::BoolProperty, bVelChange, 0x1)
		ADD_VAR(::FloatProperty, ImpulseRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpulseStrength, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
