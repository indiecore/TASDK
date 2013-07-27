#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionCustom : public MaterialExpression
	{
	public:
		enum ECustomMaterialOutputType : byte
		{
			CMOT_Float1 = 0,
			CMOT_Float2 = 1,
			CMOT_Float3 = 2,
			CMOT_Float4 = 3,
			CMOT_MAX = 4,
		};
		class CustomInput
		{
		public:
			ADD_STRUCT(MaterialExpression::ExpressionInput, Input, 12)
			ADD_STRUCT(ScriptString*, InputName, 0)
		};
		ADD_STRUCT(ScriptArray<MaterialExpressionCustom::CustomInput>, Inputs, 136)
		ADD_STRUCT(ScriptString*, Description, 124)
		ADD_STRUCT(MaterialExpressionCustom::ECustomMaterialOutputType, OutputType, 120)
		ADD_STRUCT(ScriptString*, Code, 108)
	};
}
#undef ADD_STRUCT
