#pragma once
#include "Engine.GameInfo.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.PlayerController.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PlayerCollectorGame : public GameInfo
	{
	public:
		ADD_STRUCT(ScriptString*, URLToLoad, 888)
		ADD_STRUCT(int, NumberOfClientsToWaitFor, 884)
		class PlayerController* Login(ScriptString* Portal, ScriptString* Options, OnlineSubsystem::UniqueNetId UniqueId, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32885);
			byte params[48] = { NULL };
			*(ScriptString**)params = Portal;
			*(ScriptString**)&params[12] = Options;
			*(OnlineSubsystem::UniqueNetId*)&params[24] = UniqueId;
			*(ScriptString**)&params[32] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[32];
			return *(class PlayerController**)&params[44];
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32892);
			byte params[16] = { NULL };
			*(bool*)params = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
	};
}
#undef ADD_STRUCT
