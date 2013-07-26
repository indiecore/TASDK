#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MaterialInterface.LightmassMaterialInterfaceSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassMaterialInterfaceSettings
	{
	public:
		ADD_VAR(::BoolProperty, bOverrideDistanceFieldPenumbraScale, 0x20)
		ADD_VAR(::BoolProperty, bOverrideExportResolutionScale, 0x10)
		ADD_VAR(::BoolProperty, bOverrideSpecularBoost, 0x8)
		ADD_VAR(::BoolProperty, bOverrideDiffuseBoost, 0x4)
		ADD_VAR(::BoolProperty, bOverrideEmissiveBoost, 0x2)
		ADD_VAR(::BoolProperty, bOverrideCastShadowAsMasked, 0x1)
		ADD_VAR(::FloatProperty, DistanceFieldPenumbraScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExportResolutionScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpecularBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DiffuseBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmissiveBoost, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCastShadowAsMasked, 0x1)
	};
}
#undef ADD_VAR
