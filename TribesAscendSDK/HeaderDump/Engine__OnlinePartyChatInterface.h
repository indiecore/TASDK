#pragma once
#include "Core__Interface.h"
namespace UnrealScript
{
	class OnlinePartyChatInterface : public Interface
	{
	public:
		bool SendPartyGameInvites(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.SendPartyGameInvites");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnSendPartyGameInvitesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.OnSendPartyGameInvitesComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPartyMembersInfoChanged(ScriptArray<wchar_t> PlayerName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, int CustomData1, int CustomData2, int CustomData3, int CustomData4)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.OnPartyMembersInfoChanged");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 12) = PlayerID;
			*(int*)(params + 20) = CustomData1;
			*(int*)(params + 24) = CustomData2;
			*(int*)(params + 28) = CustomData3;
			*(int*)(params + 32) = CustomData4;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPartyMemberListChanged(bool bJoinedOrLeft, ScriptArray<wchar_t> PlayerName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.OnPartyMemberListChanged");
			byte* params = (byte*)malloc(24);
			*(bool*)params = bJoinedOrLeft;
			*(ScriptArray<wchar_t>*)(params + 4) = PlayerName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 16) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddSendPartyGameInvitesCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* SendPartyGameInvitesCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.AddSendPartyGameInvitesCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = SendPartyGameInvitesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearSendPartyGameInvitesCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* SendPartyGameInvitesCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.ClearSendPartyGameInvitesCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = SendPartyGameInvitesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetPartyMembersInformation(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PartyMembers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.GetPartyMembersInformation");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PartyMembers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetPartyMemberInformation(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* MemberId, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.OnlinePartyMember'!
void*& PartyMember)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.GetPartyMemberInformation");
			byte* params = (byte*)malloc(68);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = MemberId;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.OnlinePartyMember'!
void**)(params + 8) = PartyMember;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PartyMember = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.OnlinePartyMember'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 64);
			free(params);
			return returnVal;
		}
		void AddPartyMemberListChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMemberListChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.AddPartyMemberListChangedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = PartyMemberListChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPartyMemberListChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMemberListChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.ClearPartyMemberListChangedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = PartyMemberListChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddPartyMembersInfoChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMembersInfoChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.AddPartyMembersInfoChangedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = PartyMembersInfoChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPartyMembersInfoChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMembersInfoChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.ClearPartyMembersInfoChangedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = PartyMembersInfoChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetPartyMemberCustomData(byte LocalUserNum, int Data1, int Data2, int Data3, int Data4)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.SetPartyMemberCustomData");
			byte* params = (byte*)malloc(21);
			*params = LocalUserNum;
			*(int*)(params + 4) = Data1;
			*(int*)(params + 8) = Data2;
			*(int*)(params + 12) = Data3;
			*(int*)(params + 16) = Data4;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		int GetPartyBandwidth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.GetPartyBandwidth");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool ShowPartyUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.ShowPartyUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowVoiceChannelUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.ShowVoiceChannelUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowCommunitySessionsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.ShowCommunitySessionsUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsInPartyChat(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePartyChatInterface.IsInPartyChat");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
