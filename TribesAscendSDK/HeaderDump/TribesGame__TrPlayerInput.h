#pragma once
#include "Engine__PlayerInput.h"
#include "Engine__Actor.h"
#include "TribesGame__TrVGSCommandList.h"
#include "TribesGame__TrHUD.h"
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
		ADD_OBJECT(ScriptClass, m_CurrentVGSNode)
		ADD_OBJECT(TrVGSCommandList, m_VGSCommandList)
		ADD_VAR(::StrProperty, m_CurrentVGSKeySequence, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bInVGSLoadoutMode, 0x4)
		ADD_VAR(::BoolProperty, m_bInVGSClassMode, 0x2)
		ADD_VAR(::BoolProperty, m_bInVGSCaptureMode, 0x1)
		ADD_OBJECT(TrHUD, m_HUD)
		ADD_VAR(::FloatProperty, m_RightJoystickLastValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_LeftJoystickLastValue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_VGSClassId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'InVGSClassMode'
		// Here lies the not-yet-implemented method 'InVGSLoadoutMode'
		// Here lies the not-yet-implemented method 'GetVGSClassId'
		// Here lies the not-yet-implemented method 'PlaySpottedCommand'
		// Here lies the not-yet-implemented method 'InitInputSystem'
		// Here lies the not-yet-implemented method 'AdjustMouseSensitivity'
		// Here lies the not-yet-implemented method 'IsMouseSmoothEnabled'
		// Here lies the not-yet-implemented method 'OnVGSKeyPressed'
		// Here lies the not-yet-implemented method 'OnVGSNumKeyPressed'
		// Here lies the not-yet-implemented method 'PlayVGSCommand'
		// Here lies the not-yet-implemented method 'IsValidVGSTarget'
		// Here lies the not-yet-implemented method 'StartVGS'
		// Here lies the not-yet-implemented method 'StartVGSClasses'
		// Here lies the not-yet-implemented method 'StartVGSLoadouts'
		// Here lies the not-yet-implemented method 'EndVGS'
		// Here lies the not-yet-implemented method 'SetHUDTarget'
		// Here lies the not-yet-implemented method 'GetStickAngle'
		// Here lies the not-yet-implemented method 'PushAnalogJoysticksToScaleform'
		// Here lies the not-yet-implemented method 'PreProcessInput'
		// Here lies the not-yet-implemented method 'PlayerInput'
		// Here lies the not-yet-implemented method 'SetFlyingPitchSensitivity'
		// Here lies the not-yet-implemented method 'SetFlyingYawSensitivity'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
