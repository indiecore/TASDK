#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SeqCond_SwitchClass.SwitchClassInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SwitchClassInfo
	{
	public:
		ADD_VAR(::ByteProperty, bFallThru, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ClassName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
