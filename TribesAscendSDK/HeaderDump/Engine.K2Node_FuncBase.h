#pragma once
#include "Engine.K2Node_Code.h"
#include "Core.Function.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.K2Node_FuncBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class K2Node_FuncBase : public K2Node_Code
	{
	public:
		ADD_OBJECT(Function, Function)
	};
}
#undef ADD_OBJECT
