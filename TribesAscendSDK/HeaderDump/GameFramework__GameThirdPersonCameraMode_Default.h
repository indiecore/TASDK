#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameThirdPersonCameraMode_Default." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameThirdPersonCameraMode_Default : public GameThirdPersonCameraMode
	{
	public:
		ADD_VAR(::FloatProperty, TemporaryOriginRotInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTemporaryOriginRotInterp, 0x1)
		ADD_VAR(::FloatProperty, WorstLocAimingZOffset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
