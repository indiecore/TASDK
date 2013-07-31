#pragma once
#include "Engine.K2Node_Code.h"
#include "Core.Function.h"
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
	class K2Node_Event : public K2Node_Code
	{
	public:
		ADD_OBJECT(Function, Function, 104)
		ADD_STRUCT(ScriptString*, EventName, 92)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
