#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " LevelGridVolume.LevelGridCellCoordinate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LevelGridCellCoordinate
	{
	public:
		ADD_VAR(::IntProperty, Z, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, X, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
