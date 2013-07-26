#pragma once
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Engine.PostProcessVolume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " LocalPlayer.CurrentPostProcessVolumeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty LocalPlayer.CurrentPostProcessVolumeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty LocalPlayer.CurrentPostProcessVolumeInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CurrentPostProcessVolumeInfo
	{
	public:
		ADD_VAR(::FloatProperty, LastBlendTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendStartTime, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessVolume, LastVolumeUsed)
		ADD_STRUCT(::NonArithmeticProperty<PostProcessSettings>, LastSettings, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
