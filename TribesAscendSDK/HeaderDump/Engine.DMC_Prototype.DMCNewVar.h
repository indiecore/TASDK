#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " DMC_Prototype.DMCNewVar." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DMCNewVar
	{
	public:
		ADD_VAR(::NameProperty, VarType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, VarName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
