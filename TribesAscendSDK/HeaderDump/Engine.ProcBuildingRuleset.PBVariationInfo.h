#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ProcBuildingRuleset.PBVariationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBVariationInfo
	{
	public:
		ADD_VAR(::NameProperty, VariationName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bMeshOnTopOfFacePoly, 0x1)
	};
}
#undef ADD_VAR
