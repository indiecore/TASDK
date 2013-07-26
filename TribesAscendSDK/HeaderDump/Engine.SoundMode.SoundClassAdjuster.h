#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SoundMode.SoundClassAdjuster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundClassAdjuster
	{
	public:
		ADD_VAR(::FloatProperty, VoiceCenterChannelVolumeAdjuster, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bApplyToChildren, 0x1)
		ADD_VAR(::FloatProperty, PitchAdjuster, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VolumeAdjuster, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SoundClass, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SoundClassName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
