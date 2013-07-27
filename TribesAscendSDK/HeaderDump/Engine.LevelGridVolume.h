#pragma once
#include "Engine.Volume.h"
#include "Engine.KMeshProps.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class LevelGridVolume : public Volume
	{
	public:
		enum LevelGridCellShape : byte
		{
			LGCS_Box = 0,
			LGCS_Hex = 1,
			LGCS_MAX = 2,
		};
		class LevelGridCellCoordinate
		{
		public:
			ADD_STRUCT(int, Z, 8)
			ADD_STRUCT(int, Y, 4)
			ADD_STRUCT(int, X, 0)
		};
		ADD_STRUCT(KMeshProps::KConvexElem, CellConvexElem, 556)
		ADD_STRUCT(float, KeepLoadedRange, 552)
		ADD_STRUCT(float, LoadingDistance, 548)
		ADD_STRUCT(int, Subdivisions, 536)
		ADD_STRUCT(LevelGridVolume::LevelGridCellShape, CellShape, 532)
		ADD_STRUCT(ScriptString*, LevelGridVolumeName, 520)
	};
}
#undef ADD_STRUCT
