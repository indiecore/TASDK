#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodePlayCustomAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodePlayCustomAnim : public AnimNodeBlend
	{
	public:
		ADD_VAR(::FloatProperty, CustomPendingBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsPlayingCustomAnim, 0x1)
	};
}
#undef ADD_VAR
