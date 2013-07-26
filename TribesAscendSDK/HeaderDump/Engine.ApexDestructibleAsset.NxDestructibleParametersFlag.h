#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ApexDestructibleAsset.NxDestructibleParametersFlag." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxDestructibleParametersFlag
	{
	public:
		ADD_VAR(::BoolProperty, USE_VALID_BOUNDS, 0x80)
		ADD_VAR(::BoolProperty, ACCURATE_RAYCASTS, 0x40)
		ADD_VAR(::BoolProperty, CRUMBLE_SMALLEST_CHUNKS, 0x20)
		ADD_VAR(::BoolProperty, DEBRIS_MAX_SEPARATION, 0x10)
		ADD_VAR(::BoolProperty, DEBRIS_TIMEOUT, 0x8)
		ADD_VAR(::BoolProperty, WORLD_SUPPORT, 0x4)
		ADD_VAR(::BoolProperty, ASSET_DEFINED_SUPPORT, 0x2)
		ADD_VAR(::BoolProperty, ACCUMULATE_DAMAGE, 0x1)
	};
}
#undef ADD_VAR
