#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " FracturedStaticMeshComponent.FragmentGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FragmentGroup
	{
	public:
		ADD_VAR(::BoolProperty, bGroupIsRooted, 0x1)
	};
}
#undef ADD_VAR
