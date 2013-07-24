#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ImageReflectionSceneCapture." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ImageReflectionSceneCapture : public ImageReflection
	{
	public:
		ADD_VAR(::FloatProperty, ColorRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DepthRange, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
