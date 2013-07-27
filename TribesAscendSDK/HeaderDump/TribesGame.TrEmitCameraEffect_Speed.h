#pragma once
#include "UDKBase.UDKEmitCameraEffect.h"
#include "Engine.SoundCue.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrEmitCameraEffect_Speed : public UDKEmitCameraEffect
	{
	public:
		ADD_STRUCT(float, m_fFadeOutWeatherSoundTime, 512)
		ADD_STRUCT(float, m_fFadeInWeatherSoundTime, 508)
		ADD_OBJECT(SoundCue, m_WeatherSound, 504)
		ADD_BOOL(m_bUpdateLocationBasedOnVelocity, 496, 0x2)
		ADD_BOOL(m_bUpdateRotation, 496, 0x1)
		void UpdateLocation(Object::Vector& CamLoc, Object::Rotator& CamRot, float CamFOVDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEmitCameraEffect_Speed.UpdateLocation");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = CamLoc;
			*(Object::Rotator*)&params[12] = CamRot;
			*(float*)&params[24] = CamFOVDeg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CamLoc = *(Object::Vector*)&params[0];
			CamRot = *(Object::Rotator*)&params[12];
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
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
