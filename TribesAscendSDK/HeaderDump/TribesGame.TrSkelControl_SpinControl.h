#pragma once
#include "Engine.SkelControlSingleBone.h"
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
namespace UnrealScript
{
	class TrSkelControl_SpinControl : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(float, m_fSpinDownTime, 260)
		ADD_STRUCT(float, m_fSpinUpTime, 256)
		ADD_STRUCT(float, m_TimeToInterpToTargetRotation, 280)
		ADD_STRUCT(Rotator, m_TargetRotation, 268)
		ADD_STRUCT(float, m_fCurrentDegreesPerSecond, 264)
		ADD_BOOL(m_bRotateToTargetRotation, 252, 0x10)
		ADD_BOOL(m_bSpinningDown, 252, 0x8)
		ADD_BOOL(m_bSpinningUp, 252, 0x4)
		ADD_BOOL(m_bIsSpinning, 252, 0x2)
		ADD_BOOL(m_PreviewStartStop, 252, 0x1)
		ADD_STRUCT(Vector, m_vAxis, 240)
		ADD_STRUCT(float, m_fDegreesPerSecond, 236)
		void Spin(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112380);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpinToTargetRotation(Rotator TargetRotation, float Time, bool bReset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112382);
			byte params[20] = { NULL };
			*(Rotator*)params = TargetRotation;
			*(float*)&params[12] = Time;
			*(bool*)&params[16] = bReset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
