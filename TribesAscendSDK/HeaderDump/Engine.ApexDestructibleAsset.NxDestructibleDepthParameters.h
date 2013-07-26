#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ApexDestructibleAsset.NxDestructibleDepthParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxDestructibleDepthParameters
	{
	public:
		ADD_VAR(::BoolProperty, USER_FLAG, 0x80)
		ADD_VAR(::BoolProperty, USER_FLAG, 0x40)
		ADD_VAR(::BoolProperty, USER_FLAG, 0x20)
		ADD_VAR(::BoolProperty, USER_FLAG, 0x10)
		ADD_VAR(::BoolProperty, IGNORE_CONTACT_CALLBACKS, 0x8)
		ADD_VAR(::BoolProperty, IGNORE_RAYCAST_CALLBACKS, 0x4)
		ADD_VAR(::BoolProperty, IGNORE_POSE_UPDATES, 0x2)
		ADD_VAR(::BoolProperty, TAKE_IMPACT_DAMAGE, 0x1)
	};
}
#undef ADD_VAR
