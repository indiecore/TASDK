#pragma once
#include "Engine__MaterialInterface.h"
#include "Engine__ActorComponent.h"
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
		// Here lies the not-yet-implemented method 'SetMaterial'
		// Here lies the not-yet-implemented method 'SetBlurScale'
		// Here lies the not-yet-implemented method 'SetBlurFalloffExponent'
		// Here lies the not-yet-implemented method 'SetBlurOpacity'
		// Here lies the not-yet-implemented method 'SetEnabled'
		// Here lies the not-yet-implemented method 'OnUpdatePropertyBlurScale'
		// Here lies the not-yet-implemented method 'OnUpdatePropertyBlurFalloffExponent'
		// Here lies the not-yet-implemented method 'OnUpdatePropertyBlurOpacity'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
