#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " LandscapeComponent.WeightmapLayerAllocationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WeightmapLayerAllocationInfo
	{
	public:
		ADD_VAR(::ByteProperty, WeightmapTextureChannel, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeightmapTextureIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LayerName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
