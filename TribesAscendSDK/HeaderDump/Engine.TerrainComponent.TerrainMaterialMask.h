#pragma once
#include "Core.Object.QWord.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TerrainComponent.TerrainMaterialMask." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TerrainComponent.TerrainMaterialMask." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TerrainMaterialMask
	{
	public:
		ADD_VAR(::IntProperty, NumBits, 0xFFFFFFFF)
		ADD_STRUCT(::QWordProperty, BitMask, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
