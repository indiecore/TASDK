#pragma once
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimNodeSequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSequence : public AnimNodeSequence
	{
	public:
		ADD_VAR(::BoolProperty, bLoopLastSequence, 0x2)
		ADD_VAR(::BoolProperty, bAutoStart, 0x1)
		// Here lies the not-yet-implemented method 'PlayAnimation'
		// Here lies the not-yet-implemented method 'PlayAnimationSet'
		// Here lies the not-yet-implemented method 'OnInit'
	};
}
#undef ADD_VAR
