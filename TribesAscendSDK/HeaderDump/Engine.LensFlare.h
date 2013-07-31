#pragma once
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.InterpCurveEdSetup.h"
#include "Engine.Scene.h"
#include "Core.DistributionFloat.h"
#include "Engine.StaticMesh.h"
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
	class LensFlare : public Object
	{
	public:
		struct LensFlareElement
		{
		public:
			ADD_STRUCT(ScriptArray<class MaterialInterface*>, LFMaterials, 28)
			ADD_STRUCT(DistributionFloat::RawDistributionFloat, DistMap_Alpha, 296)
			ADD_STRUCT(DistributionVector::RawDistributionVector, DistMap_Color, 268)
			ADD_STRUCT(DistributionVector::RawDistributionVector, DistMap_Scale, 240)
			ADD_STRUCT(DistributionVector::RawDistributionVector, Offset, 212)
			ADD_STRUCT(DistributionFloat::RawDistributionFloat, Alpha, 184)
			ADD_STRUCT(DistributionVector::RawDistributionVector, Color, 156)
			ADD_BOOL(bOrientTowardsSource, 152, 0x1)
			ADD_STRUCT(DistributionFloat::RawDistributionFloat, Rotation, 124)
			ADD_STRUCT(DistributionVector::RawDistributionVector, AxisScaling, 96)
			ADD_STRUCT(DistributionFloat::RawDistributionFloat, Scaling, 68)
			ADD_STRUCT(DistributionFloat::RawDistributionFloat, LFMaterialIndex, 40)
			ADD_STRUCT(Vector, Size, 16)
			ADD_BOOL(bModulateColorBySource, 12, 0x8)
			ADD_BOOL(bNormalizeRadialDistance, 12, 0x4)
			ADD_BOOL(bUseSourceDistance, 12, 0x2)
			ADD_BOOL(bIsEnabled, 12, 0x1)
			ADD_STRUCT(float, RayDistance, 8)
			ADD_STRUCT(ScriptName, ElementName, 0)
		};
		struct LensFlareElementCurvePair
		{
		public:
			ADD_OBJECT(Object, CurveObject, 12)
			ADD_STRUCT(ScriptString*, CurveName, 0)
		};
		ADD_STRUCT(ScriptArray<LensFlare::LensFlareElement>, Reflections, 392)
		ADD_OBJECT(Texture2D, ThumbnailImage, 504)
		ADD_STRUCT(float, ThumbnailDistance, 500)
		ADD_STRUCT(Rotator, ThumbnailAngle, 488)
		ADD_STRUCT(int, ReflectionCount, 484)
		ADD_OBJECT(InterpCurveEdSetup, CurveEdSetup, 480)
		ADD_STRUCT(Object::Box, FixedRelativeBoundingBox, 452)
		ADD_BOOL(ThumbnailImageOutOfDate, 448, 0x4)
		ADD_BOOL(bRenderDebugLines, 448, 0x2)
		ADD_BOOL(bUseFixedRelativeBoundingBox, 448, 0x1)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, ScreenPercentageMap, 420)
		ADD_STRUCT(float, Radius, 416)
		ADD_STRUCT(float, ConeFudgeFactor, 412)
		ADD_STRUCT(float, InnerCone, 408)
		ADD_STRUCT(float, OuterCone, 404)
		ADD_STRUCT(Scene::ESceneDepthPriorityGroup, ReflectionsDPG, 389)
		ADD_STRUCT(Scene::ESceneDepthPriorityGroup, SourceDPG, 388)
		ADD_OBJECT(StaticMesh, SourceMesh, 384)
		ADD_STRUCT(LensFlare::LensFlareElement, SourceElement, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
