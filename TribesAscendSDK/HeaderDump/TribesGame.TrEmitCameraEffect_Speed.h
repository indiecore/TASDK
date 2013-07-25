#pragma once
#include "UDKBase.UDKEmitCameraEffect.h"
#include "Engine.SoundCue.h"
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
		void UpdateLocation(Vector& CamLoc, Rotator& CamRot, float CamFOVDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEmitCameraEffect_Speed.UpdateLocation");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = CamLoc;
			*(Rotator*)(params + 12) = CamRot;
			*(float*)(params + 24) = CamFOVDeg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CamLoc = *(Vector*)params;
			CamRot = *(Rotator*)(params + 12);
			free(params);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEmitCameraEffect_Speed.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Deactivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEmitCameraEffect_Speed.Deactivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
