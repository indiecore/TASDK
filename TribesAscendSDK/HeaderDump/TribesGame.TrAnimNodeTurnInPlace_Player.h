#pragma once
#include "Engine.AnimNodeSequence.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrAnimNodeTurnInPlace_Player : public AnimNodeSequence
	{
	public:
		struct TIP_Transition
		{
		public:
			ADD_STRUCT(ScriptName, AnimName, 8)
			ADD_STRUCT(ScriptName, TransName, 0)
		};
		ADD_STRUCT(ScriptArray<TrAnimNodeTurnInPlace_Player::TIP_Transition>, TIP_Transitions, 320)
	};
}
#undef ADD_STRUCT
