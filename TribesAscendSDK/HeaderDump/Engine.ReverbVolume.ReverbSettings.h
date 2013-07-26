#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ReverbVolume.ReverbSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ReverbSettings
	{
	public:
		ADD_VAR(::BoolProperty, bApplyReverb, 0x1)
		ADD_VAR(::ByteProperty, ReverbType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Volume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
