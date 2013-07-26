#pragma once
#include "Core.Object.Vector2D.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Canvas.CanvasUVTri." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CanvasUVTri
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, V2_UV, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, V2_Pos, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, V1_UV, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, V1_Pos, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, V0_UV, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, V0_Pos, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
