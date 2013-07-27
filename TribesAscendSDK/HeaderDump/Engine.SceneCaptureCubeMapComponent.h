#pragma once
#include "Engine.TextureRenderTargetCube.h"
#include "Engine.SceneCaptureComponent.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SceneCaptureCubeMapComponent : public SceneCaptureComponent
	{
	public:
		ADD_STRUCT(Object::Vector, WorldLocation, 156)
		ADD_STRUCT(float, FarPlane, 152)
		ADD_STRUCT(float, NearPlane, 148)
		ADD_OBJECT(TextureRenderTargetCube, TextureTarget, 144)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
