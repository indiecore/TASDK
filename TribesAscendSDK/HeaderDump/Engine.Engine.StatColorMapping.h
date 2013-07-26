#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.StatColorMapping." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class StatColorMapping
	{
	public:
		ADD_VAR(::BoolProperty, DisableBlend, 0x1)
		ADD_VAR(::StrProperty, StatName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
