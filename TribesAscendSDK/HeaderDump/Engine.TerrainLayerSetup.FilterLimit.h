#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TerrainLayerSetup.FilterLimit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FilterLimit
	{
	public:
		ADD_VAR(::FloatProperty, NoiseAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NoiseScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Base, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, Enabled, 0x1)
	};
}
#undef ADD_VAR
