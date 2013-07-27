#pragma once
#include "Engine.SequenceAction.h"
#include "GFxUI.GFxMoviePlayer.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxAction_CloseMovie : public SequenceAction
	{
	public:
		ADD_BOOL(bUnload, 236, 0x1)
		ADD_OBJECT(GFxMoviePlayer, Movie, 232)
		bool IsValidLevelSequenceObject()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29650);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
