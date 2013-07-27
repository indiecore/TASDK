#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
namespace UnrealScript
{
	class OnlinePartyChatInterface : public Interface
	{
	public:
		bool SendPartyGameInvites(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21882);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnSendPartyGameInvitesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21885);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPartyMembersInfoChanged(ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID, int CustomData1, int CustomData2, int CustomData3, int CustomData4)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21888);
			byte params[36] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[12] = PlayerID;
			*(int*)&params[20] = CustomData1;
			*(int*)&params[24] = CustomData2;
			*(int*)&params[28] = CustomData3;
			*(int*)&params[32] = CustomData4;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPartyMemberListChanged(bool bJoinedOrLeft, ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21890);
			byte params[24] = { NULL };
			*(bool*)params = bJoinedOrLeft;
			*(ScriptString**)&params[4] = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[16] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSendPartyGameInvitesCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* SendPartyGameInvitesCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21892);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = SendPartyGameInvitesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearSendPartyGameInvitesCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* SendPartyGameInvitesCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21895);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = SendPartyGameInvitesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetPartyMembersInformation(ScriptArray<OnlineSubsystem::OnlinePartyMember>& PartyMembers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21898);
			byte params[16] = { NULL };
			*(ScriptArray<OnlineSubsystem::OnlinePartyMember>*)params = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyMembers = *(ScriptArray<OnlineSubsystem::OnlinePartyMember>*)params;
			return *(bool*)&params[12];
		}
		bool GetPartyMemberInformation(OnlineSubsystem::UniqueNetId MemberId, OnlineSubsystem::OnlinePartyMember& PartyMember)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21902);
			byte params[68] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = MemberId;
			*(OnlineSubsystem::OnlinePartyMember*)&params[8] = PartyMember;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyMember = *(OnlineSubsystem::OnlinePartyMember*)&params[8];
			return *(bool*)&params[64];
		}
		void AddPartyMemberListChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMemberListChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21909);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = PartyMemberListChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPartyMemberListChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMemberListChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21912);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = PartyMemberListChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddPartyMembersInfoChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMembersInfoChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21921);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = PartyMembersInfoChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPartyMembersInfoChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* PartyMembersInfoChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21924);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = PartyMembersInfoChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetPartyMemberCustomData(byte LocalUserNum, int Data1, int Data2, int Data3, int Data4)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21927);
			byte params[21] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = Data1;
			*(int*)&params[8] = Data2;
			*(int*)&params[12] = Data3;
			*(int*)&params[16] = Data4;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		int GetPartyBandwidth()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21934);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool ShowPartyUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21936);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowVoiceChannelUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21939);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowCommunitySessionsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21942);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsInPartyChat(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21945);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
