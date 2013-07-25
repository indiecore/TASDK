#pragma once
#include "Engine__SequenceAction.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_UseHoverboard." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_UseHoverboard : public SequenceAction
	{
	public:
		ADD_OBJECT(UTVehicle, Hoverboard)
	};
}
#undef ADD_OBJECT
