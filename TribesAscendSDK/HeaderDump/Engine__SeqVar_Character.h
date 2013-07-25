#pragma once
#include "Engine__SeqVar_Object.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqVar_Character." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqVar_Character : public SeqVar_Object
	{
	public:
		ADD_OBJECT(ScriptClass, PawnClass)
	};
}
#undef ADD_OBJECT
