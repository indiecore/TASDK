#pragma once
#include "Engine.SceneCaptureComponent.h"
#include "Core.Object.h"
#include "Engine.TextureRenderTarget2D.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class SceneCapture2DComponent : public SceneCaptureComponent
	{
	public:
		ADD_STRUCT(Object::Matrix, ProjMatrix, 240)
		ADD_STRUCT(Object::Matrix, ViewMatrix, 176)
		ADD_BOOL(bUpdateMatrices, 160, 0x1)
		ADD_STRUCT(float, FarPlane, 156)
		ADD_STRUCT(float, NearPlane, 152)
		ADD_STRUCT(float, FieldOfView, 148)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget, 144)
		void SetCaptureParameters(class TextureRenderTarget2D* NewTextureTarget, float NewFOV, float NewNearPlane, float NewFarPlane)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25429);
			byte params[16] = { NULL };
			*(class TextureRenderTarget2D**)params = NewTextureTarget;
			*(float*)&params[4] = NewFOV;
			*(float*)&params[8] = NewNearPlane;
			*(float*)&params[12] = NewFarPlane;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetView(Vector NewLocation, Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25434);
			byte params[24] = { NULL };
			*(Vector*)params = NewLocation;
			*(Rotator*)&params[12] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
