#pragma once
#include "Core.Object.h"
#include "Engine.RB_BodySetup.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class StaticMesh : public Object
	{
	public:
		class StaticMeshLODElement
		{
		public:
			ADD_OBJECT(MaterialInterface, Material, 0)
			ADD_BOOL(bEnableShadowCasting, 4, 0x1)
			ADD_BOOL(bEnableCollision, 12, 0x1)
		};
		class StaticMeshLODInfo
		{
		public:
			ADD_STRUCT(ScriptArray<StaticMesh::StaticMeshLODElement>, Elements, 0)
		};
		ADD_BOOL(UseSimpleLineCollision, 252, 0x1)
		ADD_BOOL(UseSimpleBoxCollision, 256, 0x1)
		ADD_BOOL(UseSimpleRigidBodyCollision, 260, 0x1)
		ADD_BOOL(UseFullPrecisionUVs, 264, 0x1)
		ADD_BOOL(bUsedForInstancing, 268, 0x1)
		ADD_BOOL(bUseMaximumStreamingTexelRatio, 272, 0x1)
		ADD_BOOL(bPartitionForEdgeGeometry, 276, 0x1)
		ADD_BOOL(bCanBecomeDynamic, 280, 0x1)
		ADD_STRUCT(int, LightMapResolution, 108)
		ADD_STRUCT(int, LightMapCoordinateIndex, 112)
		ADD_STRUCT(float, LODDistanceRatio, 84)
		ADD_STRUCT(float, LODMaxRange, 88)
		ADD_STRUCT(float, StreamingDistanceMultiplier, 288)
		ADD_STRUCT(ScriptArray<StaticMesh::StaticMeshLODInfo>, LODInfo, 72)
		ADD_OBJECT(RB_BodySetup, BodySetup, 196)
		ADD_STRUCT(ScriptString*, SourceFilePath, 324)
		ADD_STRUCT(ScriptString*, SourceFileTimestamp, 336)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
