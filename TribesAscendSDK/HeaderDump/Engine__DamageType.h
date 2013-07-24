#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DamageType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DamageType." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DamageType : public Object
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, DamagedFFWaveform)
		ADD_VAR(::FloatProperty, FracturedMeshDamage, 0xFFFFFFFF)
		ADD_OBJECT(ForceFeedbackWaveform, KilledFFWaveform)
		ADD_VAR(::FloatProperty, VehicleMomentumScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleDamageScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialDamageImpulse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KDeathUpKick, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KDeathVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KDamageImpulse, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRadialDamageVelChange, 0x10)
		ADD_VAR(::BoolProperty, bCausesFracture, 0x8)
		ADD_VAR(::BoolProperty, bExtraMomentumZ, 0x4)
		ADD_VAR(::BoolProperty, bCausedByWorld, 0x2)
		ADD_VAR(::BoolProperty, bArmorStops, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
