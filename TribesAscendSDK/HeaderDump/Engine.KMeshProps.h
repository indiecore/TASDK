#pragma once
#include "Core.Object.h"
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
namespace UnrealScript
{
	class KMeshProps : public Object
	{
	public:
		struct KSphereElem
		{
		public:
			ADD_BOOL(bPerPolyShape, 68, 0x2)
			ADD_BOOL(bNoRBCollision, 68, 0x1)
			ADD_STRUCT(float, Radius, 64)
			ADD_STRUCT(Object::Matrix, TM, 0)
		};
		struct KBoxElem
		{
		public:
			ADD_BOOL(bPerPolyShape, 76, 0x2)
			ADD_BOOL(bNoRBCollision, 76, 0x1)
			ADD_STRUCT(float, Z, 72)
			ADD_STRUCT(float, Y, 68)
			ADD_STRUCT(float, X, 64)
			ADD_STRUCT(Object::Matrix, TM, 0)
		};
		struct KSphylElem
		{
		public:
			ADD_BOOL(bPerPolyShape, 72, 0x2)
			ADD_BOOL(bNoRBCollision, 72, 0x1)
			ADD_STRUCT(float, Length, 68)
			ADD_STRUCT(float, Radius, 64)
			ADD_STRUCT(Object::Matrix, TM, 0)
		};
		struct KConvexElem
		{
		public:
			ADD_STRUCT(ScriptArray<Vector>, VertexData, 0)
			ADD_STRUCT(ScriptArray<Object::Plane>, PermutedVertexData, 12)
			ADD_STRUCT(ScriptArray<int>, FaceTriData, 24)
			ADD_STRUCT(ScriptArray<Vector>, EdgeDirections, 36)
			ADD_STRUCT(ScriptArray<Vector>, FaceNormalDirections, 48)
			ADD_STRUCT(ScriptArray<Object::Plane>, FacePlaneData, 60)
			ADD_STRUCT(Object::Box, ElemBox, 72)
		};
		struct KAggregateGeom
		{
		public:
			ADD_STRUCT(ScriptArray<KMeshProps::KSphereElem>, SphereElems, 0)
			ADD_STRUCT(ScriptArray<KMeshProps::KBoxElem>, BoxElems, 12)
			ADD_STRUCT(ScriptArray<KMeshProps::KSphylElem>, SphylElems, 24)
			ADD_STRUCT(ScriptArray<KMeshProps::KConvexElem>, ConvexElems, 36)
			ADD_BOOL(bSkipCloseAndParallelChecks, 52, 0x1)
			ADD_STRUCT(Object::Pointer, RenderInfo, 48)
		};
		ADD_STRUCT(KMeshProps::KAggregateGeom, AggGeom, 72)
		ADD_STRUCT(Vector, COMNudge, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
