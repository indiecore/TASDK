#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraModifier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CameraModifier." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CameraModifier : public Object
	{
	public:
		ADD_VAR(::FloatProperty, TargetAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Alpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaInTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(Camera, CameraOwner)
		ADD_VAR(::BoolProperty, bDebug, 0x8)
		ADD_VAR(::BoolProperty, bExclusive, 0x4)
		ADD_VAR(::BoolProperty, bPendingDisable, 0x2)
		ADD_VAR(::BoolProperty, bDisabled, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
