#pragma once
#include "Engine.SceneCaptureComponent.h"
#include "Engine.TextureRenderTarget2D.h"
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
	class SceneCapture2DHitMaskComponent : public SceneCaptureComponent
	{
	public:
		ADD_STRUCT(float, FadingIntervalTime, 176)
		ADD_STRUCT(float, FadingDurationTime, 172)
		ADD_STRUCT(float, FadingPercentage, 168)
		ADD_STRUCT(float, FadingStartTimeSinceHit, 164)
		ADD_STRUCT(int, HitMaskCullDistance, 160)
		ADD_STRUCT(int, ForceLOD, 156)
		ADD_STRUCT(int, MaterialIndex, 152)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget, 144)
		void SetCaptureTargetTexture(class TextureRenderTarget2D* InTextureTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DHitMaskComponent.SetCaptureTargetTexture");
			byte params[4] = { NULL };
			*(class TextureRenderTarget2D**)&params[0] = InTextureTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCaptureParameters(Object::Vector InMaskPosition, float InMaskRadius, Object::Vector InStartupPosition, bool bOnlyWhenFacing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DHitMaskComponent.SetCaptureParameters");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = InMaskPosition;
			*(float*)&params[12] = InMaskRadius;
			*(Object::Vector*)&params[16] = InStartupPosition;
			*(bool*)&params[28] = bOnlyWhenFacing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFadingStartTimeSinceHit(float InFadingStartTimeSinceHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DHitMaskComponent.SetFadingStartTimeSinceHit");
			byte params[4] = { NULL };
			*(float*)&params[0] = InFadingStartTimeSinceHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
