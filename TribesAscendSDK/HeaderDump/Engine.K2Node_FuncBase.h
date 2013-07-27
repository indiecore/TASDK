#pragma once
#include "Engine.K2Node_Code.h"
#include "Core.Function.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class K2Node_FuncBase : public K2Node_Code
	{
	public:
		ADD_OBJECT(Function, Function, 92)
	};
}
#undef ADD_OBJECT
