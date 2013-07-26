#pragma once
#include "Engine.Volume.h"
#include "Engine.KMeshProps.KConvexElem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LevelGridVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LevelGridVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LevelGridVolume : public Volume
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<KConvexElem>, CellConvexElem, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KeepLoadedRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LoadingDistance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Subdivisions, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CellShape, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LevelGridVolumeName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
