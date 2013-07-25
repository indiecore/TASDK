#pragma once
#include "Core__Object.h"
#include "Engine__Camera.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraModifier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CameraModifier." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CameraModifier : public Object
	{
	public:
		ADD_VAR(::FloatProperty, TargetAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Alpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaInTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(Camera, CameraOwner)
		ADD_VAR(::BoolProperty, bDebug, 0x8)
		ADD_VAR(::BoolProperty, bExclusive, 0x4)
		ADD_VAR(::BoolProperty, bPendingDisable, 0x2)
		ADD_VAR(::BoolProperty, bDisabled, 0x1)
		// Here lies the not-yet-implemented method 'AddCameraModifier'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'ModifyCamera'
		// Here lies the not-yet-implemented method 'IsDisabled'
		// Here lies the not-yet-implemented method 'RemoveCameraModifier'
		// Here lies the not-yet-implemented method 'DisableModifier'
		// Here lies the not-yet-implemented method 'EnableModifier'
		// Here lies the not-yet-implemented method 'ToggleModifier'
		// Here lies the not-yet-implemented method 'UpdateAlpha'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
