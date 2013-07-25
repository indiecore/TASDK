#pragma once
#include "Engine.SpriteComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.DynamicSpriteComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.DynamicSpriteComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DynamicSpriteComponent : public SpriteComponent
	{
	public:
		ADD_VAR(::IntProperty, LoopCount, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocationOffset, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector2D' for the property named 'AnimatedPosition'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveLinearColor' for the property named 'AnimatedColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'AnimatedScale'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
