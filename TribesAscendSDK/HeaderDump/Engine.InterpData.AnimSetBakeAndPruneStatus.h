#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpData.AnimSetBakeAndPruneStatus." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimSetBakeAndPruneStatus
	{
	public:
		ADD_VAR(::BoolProperty, bSkipBakeAndPrune, 0x2)
		ADD_VAR(::BoolProperty, bReferencedButUnused, 0x1)
		ADD_VAR(::StrProperty, AnimSetName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
