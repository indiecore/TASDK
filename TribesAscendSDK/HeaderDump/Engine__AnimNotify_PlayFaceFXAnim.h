#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_PlayFaceFXAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNotify_PlayFaceFXAnim." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_PlayFaceFXAnim : public AnimNotify_Scripted
	{
	public:
		ADD_VAR(::FloatProperty, PlayFrequency, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOverridePlayingAnim, 0x1)
		ADD_OBJECT(SoundCue, SoundCueToPlay)
		ADD_VAR(::StrProperty, AnimName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GroupName, 0xFFFFFFFF)
		ADD_OBJECT(FaceFXAnimSet, FaceFXAnimSetRef)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
