#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ShadowMap2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ShadowMap2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ShadowMap2D." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ShadowMap2D : public Object
	{
	public:
		ADD_VAR(::IntProperty, InstanceIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsShadowFactorTexture, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'LightGuid'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'CoordinateBias'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'CoordinateScale'!
		ADD_OBJECT(ShadowMapTexture2D, Texture)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
