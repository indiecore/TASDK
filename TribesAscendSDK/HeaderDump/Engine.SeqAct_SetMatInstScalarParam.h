#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetMatInstScalarParam : public SequenceAction
	{
	public:
		ADD_STRUCT(float, ScalarValue, 244)
		ADD_STRUCT(ScriptName, ParamName, 236)
		ADD_OBJECT(MaterialInstanceConstant, MatInst, 232)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
