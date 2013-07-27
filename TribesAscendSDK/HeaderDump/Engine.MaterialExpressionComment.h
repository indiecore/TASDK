#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionComment : public MaterialExpression
	{
	public:
		ADD_STRUCT(ScriptString*, Text, 124)
		ADD_STRUCT(int, SizeY, 120)
		ADD_STRUCT(int, SizeX, 116)
		ADD_STRUCT(int, PosY, 112)
		ADD_STRUCT(int, PosX, 108)
	};
}
#undef ADD_STRUCT
