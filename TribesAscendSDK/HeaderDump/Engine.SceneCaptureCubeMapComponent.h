#pragma once
#include "Engine.TextureRenderTargetCube.h"
#include "Engine.SceneCaptureComponent.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SceneCaptureCubeMapComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SceneCaptureCubeMapComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCaptureCubeMapComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCaptureCubeMapComponent : public SceneCaptureComponent
	{
	public:
		ADD_STRUCT(::VectorProperty, WorldLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FarPlane, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NearPlane, 0xFFFFFFFF)
		ADD_OBJECT(TextureRenderTargetCube, TextureTarget)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
