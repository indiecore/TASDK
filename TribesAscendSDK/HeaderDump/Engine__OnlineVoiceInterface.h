#pragma once
#include "Core__Interface.h"
#include "Engine__SpeechRecognition.h"
namespace UnrealScript
{
	class OnlineVoiceInterface : public Interface
	{
	public:
		bool MuteRemoteTalker(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.MuteRemoteTalker");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = PlayerID;
			*(bool*)(params + 12) = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool UnmuteRemoteTalker(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnmuteRemoteTalker");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = PlayerID;
			*(bool*)(params + 12) = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool RegisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.RegisterLocalTalker");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool UnregisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnregisterLocalTalker");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RegisterRemoteTalker(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.RegisterRemoteTalker");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool UnregisterRemoteTalker(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnregisterRemoteTalker");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsLocalPlayerTalking(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.IsLocalPlayerTalking");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsRemotePlayerTalking(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.IsRemotePlayerTalking");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsHeadsetPresent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.IsHeadsetPresent");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetRemoteTalkerPriority(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, int Priority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.SetRemoteTalkerPriority");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = PlayerID;
			*(int*)(params + 12) = Priority;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void OnPlayerTalkingStateChange(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Player, bool bIsTalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.OnPlayerTalkingStateChange");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = Player;
			*(bool*)(params + 8) = bIsTalking;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.ClearPlayerTalkingDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StartNetworkedVoice");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StopNetworkedVoice");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool StartSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StartSpeechRecognition");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool StopSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.StopSpeechRecognition");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetRecognitionResults(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.GetRecognitionResults");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Words;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Words = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddRecognitionCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecognitionDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.AddRecognitionCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearRecognitionCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecognitionDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.ClearRecognitionCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SelectVocabulary(byte LocalUserNum, int VocabularyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.SelectVocabulary");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = VocabularyId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetSpeechRecognitionObject(byte LocalUserNum, class SpeechRecognition* SpeechRecogObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.SetSpeechRecognitionObject");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(class SpeechRecognition**)(params + 4) = SpeechRecogObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool MuteAll(byte LocalUserNum, bool bAllowFriends)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.MuteAll");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bAllowFriends;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool UnmuteAll(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineVoiceInterface.UnmuteAll");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
