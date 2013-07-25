#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleTypeDataTrail2." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTypeDataTrail2 : public ParticleModuleTypeDataBase
	{
	public:
		ADD_VAR(::BoolProperty, RenderTessellation, 0x20)
		ADD_VAR(::BoolProperty, RenderLines, 0x10)
		ADD_VAR(::BoolProperty, RenderDirectLine, 0x8)
		ADD_VAR(::BoolProperty, RenderGeometry, 0x4)
		ADD_VAR(::BoolProperty, bClearTangents, 0x2)
		ADD_VAR(::BoolProperty, bClipSourceSegement, 0x1)
		ADD_VAR(::IntProperty, MaxParticleInTrailCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxTrailCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Sheets, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TextureTile, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TessellationStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TessellationFactorDistance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TessellationFactor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
