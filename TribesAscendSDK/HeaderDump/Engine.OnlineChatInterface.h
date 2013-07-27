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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.OnChatMessage");
			byte params[28] = { NULL };
			*(int*)&params[0] = Channel;
			*(ScriptString**)&params[4] = Sender;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.AddChatMessageDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.ClearChatMessageDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendChatMessage(int Channel, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.SendChatMessage");
			byte params[16] = { NULL };
			*(int*)&params[0] = Channel;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendPrivateChatMessage(ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.SendPrivateChatMessage");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTeamChange(Object::QWord PlayerUid, byte TeamID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.NotifyTeamChange");
			byte params[9] = { NULL };
			*(Object::QWord*)&params[0] = PlayerUid;
			params[8] = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
