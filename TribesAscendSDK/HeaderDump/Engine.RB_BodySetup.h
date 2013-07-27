#pragma once
#include "Core.Object.h"
#include "Engine.KMeshProps.h"
#include "Engine.PhysicalMaterial.h"
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
	class RB_BodySetup : public KMeshProps
	{
	public:
		enum ESleepFamily : byte
		{
			SF_Normal = 0,
			SF_Sensitive = 1,
			SF_MAX = 2,
		};
		class KCachedConvexDataElement
		{
		public:
			ADD_STRUCT(ScriptArray<byte>, ConvexElementData, 0)
		};
		class KCachedConvexData
		{
		public:
			ADD_STRUCT(ScriptArray<RB_BodySetup::KCachedConvexDataElement>, CachedConvexElements, 0)
		};
		ADD_STRUCT(ScriptArray<Object::Pointer>, CollisionGeom, 152)
		ADD_STRUCT(ScriptArray<Object::Vector>, CollisionGeomScale3D, 164)
		ADD_STRUCT(ScriptArray<Object::Vector>, PreCachedPhysScale, 176)
		ADD_STRUCT(ScriptArray<RB_BodySetup::KCachedConvexData>, PreCachedPhysData, 188)
		ADD_STRUCT(int, PreCachedPhysDataVersion, 200)
		ADD_STRUCT(float, MassScale, 148)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial, 144)
		ADD_BOOL(bConsiderForBounds, 140, 0x40)
		ADD_BOOL(bAlwaysFullAnimWeight, 140, 0x20)
		ADD_BOOL(bEnableContinuousCollisionDetection, 140, 0x10)
		ADD_BOOL(bBlockNonZeroExtent, 140, 0x8)
		ADD_BOOL(bBlockZeroExtent, 140, 0x4)
		ADD_BOOL(bNoCollision, 140, 0x2)
		ADD_BOOL(bFixed, 140, 0x1)
		ADD_STRUCT(ScriptName, BoneName, 132)
		ADD_STRUCT(RB_BodySetup::ESleepFamily, SleepFamily, 128)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
