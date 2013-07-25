#pragma once
#include "Engine.SceneCaptureComponent.h"
#include "Engine.TextureRenderTarget2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SceneCapture2DComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SceneCapture2DComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCapture2DComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCapture2DComponent : public SceneCaptureComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'ProjMatrix'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'ViewMatrix'!
		ADD_VAR(::BoolProperty, bUpdateMatrices, 0x1)
		ADD_VAR(::FloatProperty, FarPlane, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NearPlane, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FieldOfView, 0xFFFFFFFF)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget)
		void SetCaptureParameters(class TextureRenderTarget2D* NewTextureTarget, float NewFOV, float NewNearPlane, float NewFarPlane)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DComponent.SetCaptureParameters");
			byte* params = (byte*)malloc(16);
			*(class TextureRenderTarget2D**)params = NewTextureTarget;
			*(float*)(params + 4) = NewFOV;
			*(float*)(params + 8) = NewNearPlane;
			*(float*)(params + 12) = NewFarPlane;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetView(Vector NewLocation, Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCapture2DComponent.SetView");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = NewLocation;
			*(Rotator*)(params + 12) = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
