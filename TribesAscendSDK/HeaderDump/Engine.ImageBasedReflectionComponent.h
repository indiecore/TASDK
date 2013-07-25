#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Engine.Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ImageBasedReflectionComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ImageBasedReflectionComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ImageBasedReflectionComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ImageBasedReflectionComponent : public StaticMeshComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'ReflectionColor'!
		ADD_OBJECT(Texture2D, ReflectionTexture)
		ADD_VAR(::BoolProperty, bTwoSided, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
