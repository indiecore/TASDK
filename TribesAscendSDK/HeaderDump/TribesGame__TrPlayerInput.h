#pragma once
#include "Engine__PlayerInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPlayerInput." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerInput : public PlayerInput
	{
	public:
		ADD_OBJECT(TrVGSCommandList, m_VGSCommandList)
		ADD_VAR(::StrProperty, m_CurrentVGSKeySequence, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bInVGSLoadoutMode, 0x4)
		ADD_VAR(::BoolProperty, m_bInVGSClassMode, 0x2)
		ADD_VAR(::BoolProperty, m_bInVGSCaptureMode, 0x1)
		ADD_OBJECT(TrHUD, m_HUD)
		ADD_VAR(::FloatProperty, m_RightJoystickLastValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_LeftJoystickLastValue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_VGSClassId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
