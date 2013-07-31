#pragma once
#include "Engine.SceneCaptureComponent.h"
#include "Engine.Actor.h"
#include "Engine.TextureRenderTarget2D.h"
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
	class SceneCapturePortalComponent : public SceneCaptureComponent
	{
	public:
		ADD_OBJECT(Actor, ViewDestination, 152)
		ADD_STRUCT(float, ScaleFOV, 148)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget, 144)
		void SetCaptureParameters(class TextureRenderTarget2D* NewTextureTarget, float NewScaleFOV, class Actor* NewViewDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24713);
			byte params[12] = { NULL };
			*(class TextureRenderTarget2D**)params = NewTextureTarget;
			*(float*)&params[4] = NewScaleFOV;
			*(class Actor**)&params[8] = NewViewDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
