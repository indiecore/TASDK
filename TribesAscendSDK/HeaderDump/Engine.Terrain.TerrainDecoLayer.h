#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Terrain.TerrainDecoLayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TerrainDecoLayer
	{
	public:
		ADD_VAR(::IntProperty, AlphaMapIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Name, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
