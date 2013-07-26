#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.TAlphaBlend." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TAlphaBlend
	{
	public:
		ADD_VAR(::FloatProperty, AlphaIn, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BlendType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
