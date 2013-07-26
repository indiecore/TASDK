#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.Cylinder." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Cylinder
	{
	public:
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Height, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
