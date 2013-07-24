#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DrawConeComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DrawConeComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DrawConeComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::IntProperty, ConeSides, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConeAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConeRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ConeColor'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
