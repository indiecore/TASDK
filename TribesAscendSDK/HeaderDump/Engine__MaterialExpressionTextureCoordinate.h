#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionTextureCoordinate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTextureCoordinate : public MaterialExpression
	{
	public:
		ADD_VAR(::BoolProperty, UnMirrorV, 0x2)
		ADD_VAR(::BoolProperty, UnMirrorU, 0x1)
		ADD_VAR(::FloatProperty, VTiling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UTiling, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CoordinateIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
