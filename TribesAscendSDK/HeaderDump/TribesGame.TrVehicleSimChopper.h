#pragma once
#include "UDKBase.UDKVehicleSimChopper.h"
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
	class TrVehicleSimChopper : public UDKVehicleSimChopper
	{
	public:
		ADD_STRUCT(UDKVehicleSimChopper::AnglePID, RollGain, 348)
		ADD_STRUCT(UDKVehicleSimChopper::AnglePID, PitchGain, 328)
		ADD_BOOL(bShouldStabilizeRotation, 324, 0x2)
		ADD_BOOL(m_bInvertFlight, 324, 0x1)
		ADD_STRUCT(int, m_nLastYawInput, 320)
		ADD_STRUCT(int, m_nLastPitchInput, 316)
		ADD_STRUCT(float, ReverseSpeed, 312)
		ADD_STRUCT(float, HoverHeight, 308)
		void SetVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114831);
			byte params[4] = { NULL };
			*(bool*)params = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
