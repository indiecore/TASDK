#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Camera.ViewTargetTransitionParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ViewTargetTransitionParams
	{
	public:
		ADD_VAR(::BoolProperty, bLockOutgoing, 0x1)
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BlendFunction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendExp, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
