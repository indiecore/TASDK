#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TerrainComponent.TerrainPatchBounds." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TerrainPatchBounds
	{
	public:
		ADD_VAR(::FloatProperty, MaxDisplacement, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinHeight, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
