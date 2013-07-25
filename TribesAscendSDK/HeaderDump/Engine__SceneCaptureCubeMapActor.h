#pragma once
#include "Engine__SceneCaptureActor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCaptureCubeMapActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCaptureCubeMapActor : public SceneCaptureActor
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, CubeMaterialInst)
	};
}
#undef ADD_OBJECT
