#pragma once
#include "Engine.SceneCaptureComponent.h"
#include "Engine.Actor.h"
#include "Engine.TextureRenderTarget2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SceneCapturePortalComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCapturePortalComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCapturePortalComponent : public SceneCaptureComponent
	{
	public:
		ADD_OBJECT(Actor, ViewDestination)
		ADD_VAR(::FloatProperty, ScaleFOV, 0xFFFFFFFF)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget)
		void SetCaptureParameters(class TextureRenderTarget2D* NewTextureTarget, float NewScaleFOV, class Actor* NewViewDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapturePortalComponent.SetCaptureParameters");
			byte* params = (byte*)malloc(12);
			*(class TextureRenderTarget2D**)params = NewTextureTarget;
			*(float*)(params + 4) = NewScaleFOV;
			*(class Actor**)(params + 8) = NewViewDest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
