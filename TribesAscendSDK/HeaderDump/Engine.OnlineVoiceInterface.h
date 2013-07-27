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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.MuteRemoteTalker");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool UnmuteRemoteTalker(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnmuteRemoteTalker");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool RegisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.RegisterLocalTalker");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool UnregisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnregisterLocalTalker");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RegisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.RegisterRemoteTalker");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnregisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnregisterRemoteTalker");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsLocalPlayerTalking(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.IsLocalPlayerTalking");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsRemotePlayerTalking(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.IsRemotePlayerTalking");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsHeadsetPresent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.IsHeadsetPresent");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetRemoteTalkerPriority(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, int Priority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.SetRemoteTalkerPriority");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(int*)&params[12] = Priority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void OnPlayerTalkingStateChange(OnlineSubsystem::UniqueNetId Player, bool bIsTalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.OnPlayerTalkingStateChange");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = Player;
			*(bool*)&params[8] = bIsTalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRecognitionComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.OnRecognitionComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.AddPlayerTalkingDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.ClearPlayerTalkingDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StartNetworkedVoice");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StopNetworkedVoice");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StartSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StartSpeechRecognition");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StopSpeechRecognition");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetRecognitionResults(byte LocalUserNum, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.GetRecognitionResults");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
			return *(bool*)&params[16];
		}
		void AddRecognitionCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecognitionDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.AddRecognitionCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRecognitionCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecognitionDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.ClearRecognitionCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SelectVocabulary(byte LocalUserNum, int VocabularyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.SelectVocabulary");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = VocabularyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetSpeechRecognitionObject(byte LocalUserNum, class SpeechRecognition* SpeechRecogObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.SetSpeechRecognitionObject");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(class SpeechRecognition**)&params[4] = SpeechRecogObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MuteAll(byte LocalUserNum, bool bAllowFriends)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.MuteAll");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(bool*)&params[4] = bAllowFriends;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnmuteAll(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnmuteAll");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
