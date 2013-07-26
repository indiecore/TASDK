#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxObject.ASDisplayInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ASDisplayInfo
	{
	public:
		ADD_VAR(::BoolProperty, hasVisible, 0x800)
		ADD_VAR(::BoolProperty, hasAlpha, 0x400)
		ADD_VAR(::BoolProperty, hasZScale, 0x200)
		ADD_VAR(::BoolProperty, hasYScale, 0x100)
		ADD_VAR(::BoolProperty, hasXScale, 0x80)
		ADD_VAR(::BoolProperty, hasYRotation, 0x40)
		ADD_VAR(::BoolProperty, hasXRotation, 0x20)
		ADD_VAR(::BoolProperty, hasRotation, 0x10)
		ADD_VAR(::BoolProperty, hasZ, 0x8)
		ADD_VAR(::BoolProperty, hasY, 0x4)
		ADD_VAR(::BoolProperty, hasX, 0x2)
		ADD_VAR(::BoolProperty, Visible, 0x1)
		ADD_VAR(::FloatProperty, Alpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, YScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, YRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Rotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Z, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, X, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
