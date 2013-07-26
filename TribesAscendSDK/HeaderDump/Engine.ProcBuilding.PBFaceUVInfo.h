#pragma once
#include "Core.Object.Vector2D.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ProcBuilding.PBFaceUVInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBFaceUVInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Offset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Size, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
