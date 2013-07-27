#pragma once
#include "Engine.SequenceAction.h"
#include "GFxUI.GFxMoviePlayer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxAction_GetVariable : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptString*, Variable, 236)
		ADD_OBJECT(GFxMoviePlayer, Movie, 232)
		bool IsValidLevelSequenceObject()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxAction_GetVariable.IsValidLevelSequenceObject");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
