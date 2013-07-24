#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKScout." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKScout : public Scout
	{
	public:
		ADD_VAR(::NameProperty, SizePersonFindName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDoubleJumpHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRequiresDoubleJump, 0x1)
	};
}
#undef ADD_VAR
