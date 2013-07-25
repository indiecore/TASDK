#pragma once
#include "Engine__InterpTrackInst.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpTrackInstProperty." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrackInstProperty : public InterpTrackInst
	{
	public:
		ADD_OBJECT(Object, PropertyOuterObjectInst)
		ADD_OBJECT(Function, PropertyUpdateCallback)
	};
}
#undef ADD_OBJECT
