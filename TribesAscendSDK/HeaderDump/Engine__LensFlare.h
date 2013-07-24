#pragma once
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
		ADD_STRUCT(::RotatorProperty, ThumbnailAngle, 0xFFFFFFFF
		ADD_VAR(::IntProperty, ReflectionCount, 0xFFFFFFFF)
		ADD_OBJECT(InterpCurveEdSetup, CurveEdSetup)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box' for the property named 'FixedRelativeBoundingBox'!
		ADD_VAR(::BoolProperty, ThumbnailImageOutOfDate, 0x4)
		ADD_VAR(::BoolProperty, bRenderDebugLines, 0x2)
		ADD_VAR(::BoolProperty, bUseFixedRelativeBoundingBox, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'ScreenPercentageMap'!
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConeFudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerCone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterCone, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ReflectionsDPG, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SourceDPG, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, SourceMesh)
		// WARNING: Unknown structure type 'ScriptStruct Engine.LensFlare.LensFlareElement' for the property named 'SourceElement'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
