#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SoundClass.SoundClassProperties." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundClassProperties
	{
	public:
		ADD_VAR(::BoolProperty, bBassBoost, 0x40)
		ADD_VAR(::BoolProperty, bCenterChannelOnly, 0x20)
		ADD_VAR(::BoolProperty, bReverb, 0x10)
		ADD_VAR(::BoolProperty, bIsMusic, 0x8)
		ADD_VAR(::BoolProperty, bIsUISound, 0x4)
		ADD_VAR(::BoolProperty, bAlwaysPlay, 0x2)
		ADD_VAR(::BoolProperty, bApplyEffects, 0x1)
		ADD_VAR(::FloatProperty, RadioFilterVolumeThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadioFilterVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VoiceCenterChannelVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LFEBleed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StereoBleed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Pitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Volume, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
