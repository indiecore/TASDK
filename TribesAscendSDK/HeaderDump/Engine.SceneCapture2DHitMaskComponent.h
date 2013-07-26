#pragma once
#include "Engine.SceneCaptureComponent.h"
#include "Engine.TextureRenderTarget2D.h"
#include "Core.Object.Vector.h"
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
		void SetCaptureTargetTexture(class TextureRenderTarget2D* InTextureTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DHitMaskComponent.SetCaptureTargetTexture");
			byte* params = (byte*)malloc(4);
			*(class TextureRenderTarget2D**)params = InTextureTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCaptureParameters(Vector InMaskPosition, float InMaskRadius, Vector InStartupPosition, bool bOnlyWhenFacing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DHitMaskComponent.SetCaptureParameters");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = InMaskPosition;
			*(float*)(params + 12) = InMaskRadius;
			*(Vector*)(params + 16) = InStartupPosition;
			*(bool*)(params + 28) = bOnlyWhenFacing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFadingStartTimeSinceHit(float InFadingStartTimeSinceHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DHitMaskComponent.SetFadingStartTimeSinceHit");
			byte* params = (byte*)malloc(4);
			*(float*)params = InFadingStartTimeSinceHit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
