#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.K2Input_Int." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class K2Input_Int : public K2Input
	{
	public:
		ADD_VAR(::IntProperty, DefaultInt, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
