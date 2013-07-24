#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEmitCameraEffect_Speed." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEmitCameraEffect_Speed." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEmitCameraEffect_Speed : public UDKEmitCameraEffect
	{
	public:
		ADD_VAR(::FloatProperty, m_fFadeOutWeatherSoundTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFadeInWeatherSoundTime, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_WeatherSound)
		ADD_VAR(::BoolProperty, m_bUpdateLocationBasedOnVelocity, 0x2)
		ADD_VAR(::BoolProperty, m_bUpdateRotation, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
