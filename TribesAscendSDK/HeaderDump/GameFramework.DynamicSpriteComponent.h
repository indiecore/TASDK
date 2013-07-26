#pragma once
#include "Core.Object.InterpCurveVector2D.h"
#include "Engine.SpriteComponent.h"
#include "Core.Object.Vector.h"
#include "Core.Object.InterpCurveLinearColor.h"
#include "Core.Object.InterpCurveFloat.h"
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
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector2D>, AnimatedPosition, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveLinearColor>, AnimatedColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveFloat>, AnimatedScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
