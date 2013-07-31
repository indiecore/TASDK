#pragma once
#include "Engine.AnimNodeBlendPerBone.h"
#include "Engine.AnimNodeSlot.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendBySlotActive : public AnimNodeBlendPerBone
	{
	public:
		ADD_OBJECT(AnimNodeSlot, ChildSlot, 300)
	};
}
#undef ADD_OBJECT
