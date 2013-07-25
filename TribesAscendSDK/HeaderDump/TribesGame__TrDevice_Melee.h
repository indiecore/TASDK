#pragma once
#include "TribesGame__TrDevice_AutoFire.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_Melee." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Melee : public TrDevice_AutoFire
	{
	public:
		ADD_OBJECT(AnimNodeSequence, FiringAnimSeqNode)
	};
}
#undef ADD_OBJECT
