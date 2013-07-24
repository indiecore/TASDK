#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SceneCapture2DHitMaskComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCapture2DHitMaskComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCapture2DHitMaskComponent : public SceneCaptureComponent
	{
	public:
		ADD_VAR(::FloatProperty, FadingIntervalTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadingDurationTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadingPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadingStartTimeSinceHit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HitMaskCullDistance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ForceLOD, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaterialIndex, 0xFFFFFFFF)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
