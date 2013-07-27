#pragma once
#include "Core.Interface.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class OnlineChatInterface : public Interface
	{
	public:
		void OnChatMessage(int Channel, ScriptString* Sender, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21389);
			byte params[28] = { NULL };
			*(int*)params = Channel;
			*(ScriptString**)&params[4] = Sender;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21394);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21396);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendChatMessage(int Channel, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21398);
			byte params[16] = { NULL };
			*(int*)params = Channel;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendPrivateChatMessage(ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21401);
			byte params[24] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTeamChange(QWord PlayerUid, byte TeamID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21404);
			byte params[9] = { NULL };
			*(QWord*)params = PlayerUid;
			params[8] = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
