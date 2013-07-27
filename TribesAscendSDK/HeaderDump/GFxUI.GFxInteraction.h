#pragma once
#include "Engine.LocalPlayer.h"
#include "Engine.Interaction.h"
#include "Core.Object.h"
#include "GFxUI.GFxMoviePlayer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxInteraction : public Interaction
	{
	public:
		ADD_STRUCT(Object::Pointer, VfTable_FCallbackEventDevice, 108)
		class GFxMoviePlayer* GetFocusMovie(int ControllerId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30303);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxMoviePlayer**)&params[4];
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30306);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30307);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30310);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CloseAllMoviePlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30313);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
