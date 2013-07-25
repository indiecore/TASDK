#pragma once
#include "Engine__K2Output.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.K2Output_Object." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class K2Output_Object : public K2Output
	{
	public:
		ADD_OBJECT(ScriptClass, ObjClass)
	};
}
#undef ADD_OBJECT
