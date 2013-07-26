#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.FireLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FireLink
	{
	public:
		ADD_VAR(::BoolProperty, bDynamicIndexInited, 0x2)
		ADD_VAR(::BoolProperty, bFallbackLink, 0x1)
		ADD_VAR(::IntProperty, PackedProperties_CoverPairRefAndDynamicInfo, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
