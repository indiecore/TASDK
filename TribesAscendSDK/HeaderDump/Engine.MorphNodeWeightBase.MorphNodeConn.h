#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MorphNodeWeightBase.MorphNodeConn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MorphNodeConn
	{
	public:
		ADD_VAR(::IntProperty, DrawY, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ConnName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
