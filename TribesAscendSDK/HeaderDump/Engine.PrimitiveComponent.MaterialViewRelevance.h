#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PrimitiveComponent.MaterialViewRelevance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialViewRelevance
	{
	public:
		ADD_VAR(::BoolProperty, bOpaque, 0x1)
		ADD_VAR(::BoolProperty, bTranslucent, 0x2)
		ADD_VAR(::BoolProperty, bDistortion, 0x4)
		ADD_VAR(::BoolProperty, bOneLayerDistortionRelevance, 0x8)
		ADD_VAR(::BoolProperty, bLit, 0x10)
		ADD_VAR(::BoolProperty, bUsesSceneColor, 0x20)
	};
}
#undef ADD_VAR
