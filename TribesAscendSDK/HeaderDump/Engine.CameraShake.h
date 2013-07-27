#pragma once
#include "Core.Object.h"
#include "Engine.CameraAnim.h"
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
	class CameraShake : public Object
	{
	public:
		enum EInitialOscillatorOffset : byte
		{
			EOO_OffsetRandom = 0,
			EOO_OffsetZero = 1,
			EOO_MAX = 2,
		};
		class FOscillator
		{
		public:
			ADD_STRUCT(float, Amplitude, 0)
			ADD_STRUCT(float, Frequency, 4)
			ADD_STRUCT(CameraShake::EInitialOscillatorOffset, InitialOffset, 8)
		};
		class VOscillator
		{
		public:
			ADD_STRUCT(CameraShake::FOscillator, X, 0)
			ADD_STRUCT(CameraShake::FOscillator, Y, 12)
			ADD_STRUCT(CameraShake::FOscillator, Z, 24)
		};
		class ROscillator
		{
		public:
			ADD_STRUCT(CameraShake::FOscillator, Pitch, 0)
			ADD_STRUCT(CameraShake::FOscillator, Yaw, 12)
			ADD_STRUCT(CameraShake::FOscillator, Roll, 24)
		};
		ADD_STRUCT(CameraShake::VOscillator, LocOscillation, 112)
		ADD_STRUCT(CameraShake::ROscillator, RotOscillation, 76)
		ADD_BOOL(bSingleInstance, 60, 0x1)
		ADD_BOOL(bRandomAnimSegment, 60, 0x2)
		ADD_STRUCT(float, OscillationDuration, 64)
		ADD_STRUCT(float, OscillationBlendInTime, 68)
		ADD_STRUCT(float, OscillationBlendOutTime, 72)
		ADD_STRUCT(CameraShake::FOscillator, FOVOscillation, 148)
		ADD_OBJECT(CameraAnim, Anim, 160)
		ADD_STRUCT(float, AnimPlayRate, 164)
		ADD_STRUCT(float, AnimScale, 168)
		ADD_STRUCT(float, AnimBlendInTime, 172)
		ADD_STRUCT(float, AnimBlendOutTime, 176)
		ADD_STRUCT(float, RandomAnimSegmentDuration, 180)
		float GetLocOscillationMagnitude()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraShake.GetLocOscillationMagnitude");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetRotOscillationMagnitude()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraShake.GetRotOscillationMagnitude");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
