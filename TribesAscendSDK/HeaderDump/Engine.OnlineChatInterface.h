#pragma once
#include "Core.Interface.h"
namespace UnrealScript
{
	class OnlineChatInterface : public Interface
	{
	public:
		void OnChatMessage(int Channel, ScriptArray<wchar_t> Sender, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.OnChatMessage");
			byte* params = (byte*)malloc(28);
			*(int*)params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Sender;
			*(ScriptArray<wchar_t>*)(params + 16) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.AddChatMessageDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.ClearChatMessageDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendChatMessage(int Channel, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.SendChatMessage");
			byte* params = (byte*)malloc(16);
			*(int*)params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendPrivateChatMessage(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.SendPrivateChatMessage");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyTeamChange(QWord PlayerUid, byte TeamID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineChatInterface.NotifyTeamChange");
			byte* params = (byte*)malloc(9);
			*(QWord*)params = PlayerUid;
			*(params + 8) = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
