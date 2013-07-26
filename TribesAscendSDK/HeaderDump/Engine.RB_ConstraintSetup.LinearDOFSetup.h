#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " RB_ConstraintSetup.LinearDOFSetup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LinearDOFSetup
	{
	public:
		ADD_VAR(::FloatProperty, LimitSize, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bLimited, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
