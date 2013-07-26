#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeBlendMultiBone.ChildBoneBlendInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ChildBoneBlendInfo
	{
	public:
		ADD_VAR(::FloatProperty, OldBoneIncrease, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, OldStartBone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InitPerBoneIncrease, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InitTargetStartBone, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
