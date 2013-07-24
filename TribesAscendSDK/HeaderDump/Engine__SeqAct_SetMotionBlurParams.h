#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetMotionBlurParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetMotionBlurParams : public SeqAct_Latent
	{
	public:
		ADD_VAR(::FloatProperty, OldMotionBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpolateElapsed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpolateSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MotionBlurAmount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
