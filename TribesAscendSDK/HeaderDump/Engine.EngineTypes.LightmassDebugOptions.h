#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.LightmassDebugOptions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassDebugOptions
	{
	public:
		ADD_VAR(::BoolProperty, bInitialized, 0x1)
		ADD_VAR(::FloatProperty, ExecutionTimeDivisor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bColorByExecutionTime, 0x800)
		ADD_VAR(::BoolProperty, bColorBordersGreen, 0x400)
		ADD_VAR(::BoolProperty, bUseRandomColors, 0x200)
		ADD_VAR(::BoolProperty, bOnlyCalcDebugTexelMappings, 0x100)
		ADD_VAR(::BoolProperty, bDebugPaddings, 0x80)
		ADD_VAR(::BoolProperty, bPadMappings, 0x40)
		ADD_VAR(::BoolProperty, bDebugMaterials, 0x20)
		ADD_VAR(::BoolProperty, bDumpBinaryFiles, 0x10)
		ADD_VAR(::BoolProperty, bSortMappings, 0x8)
		ADD_VAR(::BoolProperty, bImmediateProcessMappings, 0x4)
		ADD_VAR(::BoolProperty, bUseImmediateImport, 0x2)
		ADD_VAR(::BoolProperty, bUseDeterministicLighting, 0x1)
		ADD_VAR(::FloatProperty, CoplanarTolerance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGatherBSPSurfacesAcrossComponents, 0x4)
		ADD_VAR(::BoolProperty, bStatsEnabled, 0x2)
		ADD_VAR(::BoolProperty, bDebugMode, 0x1)
	};
}
#undef ADD_VAR
