#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PBRuleNodeCorner.RBCornerAngleInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RBCornerAngleInfo
	{
	public:
		ADD_VAR(::FloatProperty, CornerSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Angle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
