#pragma once
#include "Engine__AnimNodeBlendPerBone.h"
#include "Engine__AnimNodeSlot.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimBlendBySlotActive." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendBySlotActive : public AnimNodeBlendPerBone
	{
	public:
		ADD_OBJECT(AnimNodeSlot, ChildSlot)
	};
}
#undef ADD_OBJECT
