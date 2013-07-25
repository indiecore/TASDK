#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CameraActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CameraActor : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bConstrainAspectRatio, 0x1)
		ADD_VAR(::FloatProperty, AspectRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CamOverridePostProcessAlpha, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'CamOverridePostProcess'!
		ADD_VAR(::FloatProperty, FOVAngle, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCamOverridePostProcess, 0x2)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
