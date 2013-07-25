#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleTypeDataRibbon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTypeDataRibbon : public ParticleModuleTypeDataBase
	{
	public:
		ADD_VAR(::FloatProperty, TangentTessellationScalar, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DistanceTessellationStepSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TilingDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TangentSpawningScalar, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RenderAxis, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxTessellationBetweenParticles, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRenderTessellation, 0x100)
		ADD_VAR(::BoolProperty, bRenderTangents, 0x80)
		ADD_VAR(::BoolProperty, bRenderSpawnPoints, 0x40)
		ADD_VAR(::BoolProperty, bRenderGeometry, 0x20)
		ADD_VAR(::BoolProperty, bTangentRecalculationEveryFrame, 0x10)
		ADD_VAR(::BoolProperty, bEnablePreviousTangentRecalculation, 0x8)
		ADD_VAR(::BoolProperty, bClipSourceSegement, 0x4)
		ADD_VAR(::BoolProperty, bDeadTrailsOnSourceLoss, 0x2)
		ADD_VAR(::BoolProperty, bDeadTrailsOnDeactivate, 0x1)
		ADD_VAR(::IntProperty, MaxParticleInTrailCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxTrailCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SheetsPerTrail, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
