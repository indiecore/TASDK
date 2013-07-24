#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTBeamWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTBeamWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTBeamWeapon : public UTWeapon
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, BeamWeaponFireWaveForm)
		ADD_VAR(::NameProperty, BeamPostFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamPreFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EndPointParamName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamSockets, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, BeamTemplate)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
