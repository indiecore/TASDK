#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Brush.GeomSelection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GeomSelection
	{
	public:
		ADD_VAR(::IntProperty, SelectionIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Index, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Type, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
