#pragma once
#include "Core.Object.h"
#include "Engine.InterpGroup.h"
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Core.Object.Box.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CameraAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CameraAnim." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CameraAnim : public Object
	{
	public:
		ADD_VAR(::FloatProperty, BaseFOV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BasePPSettingsAlpha, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PostProcessSettings>, BasePPSettings, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Box>, BoundingBox, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimLength, 0xFFFFFFFF)
		ADD_OBJECT(InterpGroup, CameraInterpGroup)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
