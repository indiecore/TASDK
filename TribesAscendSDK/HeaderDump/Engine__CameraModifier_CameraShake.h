#pragma once
#include "Engine__CameraShake.h"
#include "Engine__CameraModifier.h"
#include "Engine__Camera.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraModifier_CameraShake." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CameraModifier_CameraShake : public CameraModifier
	{
	public:
		ADD_VAR(::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'InitializeOffset'
		// Here lies the not-yet-implemented method 'ReinitShake'
		// Here lies the not-yet-implemented method 'InitializeShake'
		// Here lies the not-yet-implemented method 'AddCameraShake'
		// Here lies the not-yet-implemented method 'RemoveCameraShake'
		// Here lies the not-yet-implemented method 'RemoveAllCameraShakes'
		// Here lies the not-yet-implemented method 'UpdateCameraShake'
		// Here lies the not-yet-implemented method 'ModifyCamera'
	};
}
#undef ADD_VAR
