#pragma once
#include "Core__Function.h"
#include "Engine__K2Node_Code.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.K2Node_Event." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.K2Node_Event." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class K2Node_Event : public K2Node_Code
	{
	public:
		ADD_OBJECT(Function, Function)
		ADD_VAR(::StrProperty, EventName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
