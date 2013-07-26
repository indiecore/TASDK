#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObject.ObjectiveMICInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ObjectiveMICInfo
	{
	public:
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AmountFilled, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ObjStatus, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IsContested, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Flip, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
