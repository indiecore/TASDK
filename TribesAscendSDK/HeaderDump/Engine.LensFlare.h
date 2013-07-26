#pragma once
#include "Engine.LensFlare.LensFlareElement.h"
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.InterpCurveEdSetup.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Box.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.StaticMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LensFlare." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LensFlare." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LensFlare." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LensFlare : public Object
	{
	public:
		ADD_OBJECT(Texture2D, ThumbnailImage)
		ADD_VAR(::FloatProperty, ThumbnailDistance, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, ThumbnailAngle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ReflectionCount, 0xFFFFFFFF)
		ADD_OBJECT(InterpCurveEdSetup, CurveEdSetup)
		ADD_STRUCT(::NonArithmeticProperty<Box>, FixedRelativeBoundingBox, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, ThumbnailImageOutOfDate, 0x4)
		ADD_VAR(::BoolProperty, bRenderDebugLines, 0x2)
		ADD_VAR(::BoolProperty, bUseFixedRelativeBoundingBox, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, ScreenPercentageMap, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConeFudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerCone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterCone, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ReflectionsDPG, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SourceDPG, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, SourceMesh)
		ADD_STRUCT(::NonArithmeticProperty<LensFlareElement>, SourceElement, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
