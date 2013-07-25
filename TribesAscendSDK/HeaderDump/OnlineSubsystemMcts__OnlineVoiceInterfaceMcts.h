#pragma once
#include "Core__Object.h"
#include "Engine__SpeechRecognition.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystemMcts.OnlineVoiceInterfaceMcts." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineVoiceInterfaceMcts : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.LocalTalkerMcts' for the property named 'CurrentLocalTalker'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VoiceEnginePtr'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'MctsSubsystem'!
		void OnRecognitionComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnRecognitionComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPlayerTalkingStateChange(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Player, bool bIsTalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnPlayerTalkingStateChange");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = Player;
			*(bool*)(params + 8) = bIsTalking;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RegisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterLocalTalker");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool UnregisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterLocalTalker");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterRemoteTalker");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterRemoteTalker");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsLocalPlayerTalking");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsRemotePlayerTalking");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsHeadsetPresent");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetRemoteTalkerPriority");
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
		bool MuteRemoteTalker(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteRemoteTalker");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteRemoteTalker");
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
		void AddPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddPlayerTalkingDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearPlayerTalkingDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartNetworkedVoice");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopNetworkedVoice");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool StartSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartSpeechRecognition");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool StopSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopSpeechRecognition");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.GetRecognitionResults");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddRecognitionCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearRecognitionCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SelectVocabulary");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetSpeechRecognitionObject");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteAll");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteAll");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
