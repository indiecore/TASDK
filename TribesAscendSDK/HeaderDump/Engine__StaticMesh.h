#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.StaticMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.StaticMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class StaticMesh : public Object
	{
	public:
		ADD_VAR(::BoolProperty, UseSimpleLineCollision, 0x1)
		ADD_VAR(::BoolProperty, UseSimpleBoxCollision, 0x1)
		ADD_VAR(::BoolProperty, UseSimpleRigidBodyCollision, 0x1)
		ADD_VAR(::BoolProperty, UseFullPrecisionUVs, 0x1)
		ADD_VAR(::BoolProperty, bUsedForInstancing, 0x1)
		ADD_VAR(::BoolProperty, bUseMaximumStreamingTexelRatio, 0x1)
		ADD_VAR(::BoolProperty, bPartitionForEdgeGeometry, 0x1)
		ADD_VAR(::BoolProperty, bCanBecomeDynamic, 0x1)
		ADD_VAR(::IntProperty, LightMapResolution, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LightMapCoordinateIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LODDistanceRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LODMaxRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StreamingDistanceMultiplier, 0xFFFFFFFF)
		ADD_OBJECT(RB_BodySetup, BodySetup)
		ADD_VAR(::StrProperty, SourceFilePath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SourceFileTimestamp, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
