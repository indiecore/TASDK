#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.h"
#include "Engine.Scene.h"
#include "Engine.MaterialInterface.h"
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
	class RadialBlurComponent : public ActorComponent
	{
	public:
		ADD_STRUCT(Object::Matrix, LocalToWorld, 128)
		ADD_BOOL(bEnabled, 116, 0x2)
		ADD_BOOL(bRenderAsVelocity, 116, 0x1)
		ADD_STRUCT(float, DistanceFalloffExponent, 112)
		ADD_STRUCT(float, MaxCullDistance, 108)
		ADD_STRUCT(float, BlurOpacity, 104)
		ADD_STRUCT(float, BlurFalloffExponent, 100)
		ADD_STRUCT(float, BlurScale, 96)
		ADD_STRUCT(Scene::ESceneDepthPriorityGroup, DepthPriorityGroup, 92)
		ADD_OBJECT(MaterialInterface, Material, 88)
		void SetMaterial(class MaterialInterface* InMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetMaterial");
			byte params[4] = { NULL };
			*(class MaterialInterface**)&params[0] = InMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBlurScale(float InBlurScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetBlurScale");
			byte params[4] = { NULL };
			*(float*)&params[0] = InBlurScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBlurFalloffExponent(float InBlurFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetBlurFalloffExponent");
			byte params[4] = { NULL };
			*(float*)&params[0] = InBlurFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBlurOpacity(float InBlurOpacity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetBlurOpacity");
			byte params[4] = { NULL };
			*(float*)&params[0] = InBlurOpacity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdatePropertyBlurScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.OnUpdatePropertyBlurScale");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBlurFalloffExponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.OnUpdatePropertyBlurFalloffExponent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBlurOpacity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.OnUpdatePropertyBlurOpacity");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
