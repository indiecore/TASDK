#pragma once
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " LocalPlayer.PostProcessSettingsOverride." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty LocalPlayer.PostProcessSettingsOverride." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PostProcessSettingsOverride
	{
	public:
		ADD_VAR(::FloatProperty, BlendStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendOutDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBlendingOut, 0x2)
		ADD_VAR(::BoolProperty, bBlendingIn, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<PostProcessSettings>, Settings, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
