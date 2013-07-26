#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SplineMeshComponent.SplineMeshParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SplineMeshComponent.SplineMeshParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SplineMeshParams
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, EndOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndRoll, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, EndScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EndTangent, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EndPos, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, StartOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartRoll, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, StartScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartTangent, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartPos, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
