#pragma once
#include "Engine.ActorComponent.h"
#include "Engine.MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RadialBlurComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.RadialBlurComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.RadialBlurComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class RadialBlurComponent : public ActorComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'LocalToWorld'!
		ADD_VAR(::BoolProperty, bEnabled, 0x2)
		ADD_VAR(::BoolProperty, bRenderAsVelocity, 0x1)
		ADD_VAR(::FloatProperty, DistanceFalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxCullDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlurOpacity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlurFalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlurScale, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DepthPriorityGroup, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, Material)
		void SetMaterial(class MaterialInterface* InMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetMaterial");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = InMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBlurScale(float InBlurScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetBlurScale");
			byte* params = (byte*)malloc(4);
			*(float*)params = InBlurScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBlurFalloffExponent(float InBlurFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetBlurFalloffExponent");
			byte* params = (byte*)malloc(4);
			*(float*)params = InBlurFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBlurOpacity(float InBlurOpacity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetBlurOpacity");
			byte* params = (byte*)malloc(4);
			*(float*)params = InBlurOpacity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RadialBlurComponent.SetEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
