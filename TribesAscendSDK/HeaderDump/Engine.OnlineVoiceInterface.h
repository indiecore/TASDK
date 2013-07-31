#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.SpeechRecognition.h"
namespace UnrealScript
{
	class OnlineVoiceInterface : public Interface
	{
	public:
		bool MuteRemoteTalker(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9210);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool UnmuteRemoteTalker(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9216);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool RegisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22986);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool UnregisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22989);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RegisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22992);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnregisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22995);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsLocalPlayerTalking(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22998);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsRemotePlayerTalking(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23001);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsHeadsetPresent(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23004);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetRemoteTalkerPriority(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, int Priority)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23007);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(int*)&params[12] = Priority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void OnPlayerTalkingStateChange(OnlineSubsystem::UniqueNetId Player, bool bIsTalking)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23018);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = Player;
			*(bool*)&params[8] = bIsTalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRecognitionComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23024);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23026);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23028);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23030);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StartSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23032);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23035);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetRecognitionResults(byte LocalUserNum, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23038);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
			return *(bool*)&params[16];
		}
		void AddRecognitionCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecognitionDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23043);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRecognitionCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecognitionDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23046);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SelectVocabulary(byte LocalUserNum, int VocabularyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23049);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = VocabularyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetSpeechRecognitionObject(byte LocalUserNum, class SpeechRecognition* SpeechRecogObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23053);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(class SpeechRecognition**)&params[4] = SpeechRecogObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MuteAll(byte LocalUserNum, bool bAllowFriends)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23057);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bAllowFriends;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnmuteAll(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23061);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
