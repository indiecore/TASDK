#pragma once
#include "TribesGame.TrHUD.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrHUDTeam : public TrHUD
	{
	public:
		ADD_STRUCT(int, m_nLastMessageCode, 2492)
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96623);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
