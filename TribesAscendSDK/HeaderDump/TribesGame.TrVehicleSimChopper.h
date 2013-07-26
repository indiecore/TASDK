#pragma once
#include "UDKBase.UDKVehicleSimChopper.AnglePID.h"
#include "UDKBase.UDKVehicleSimChopper.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicleSimChopper." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrVehicleSimChopper." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVehicleSimChopper : public UDKVehicleSimChopper
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<AnglePID>, RollGain, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AnglePID>, PitchGain, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldStabilizeRotation, 0x2)
		ADD_VAR(::BoolProperty, m_bInvertFlight, 0x1)
		ADD_VAR(::IntProperty, m_nLastYawInput, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPitchInput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReverseSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HoverHeight, 0xFFFFFFFF)
		void SetVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleSimChopper.SetVehicleControls");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
