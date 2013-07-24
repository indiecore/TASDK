#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SphericalHarmonicLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SphericalHarmonicLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SphericalHarmonicLightComponent : public LightComponent
	{
	public:
		ADD_VAR(::BoolProperty, bRenderBeforeModShadows, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.SHVectorRGB' for the property named 'WorldSpaceIncidentLighting'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
