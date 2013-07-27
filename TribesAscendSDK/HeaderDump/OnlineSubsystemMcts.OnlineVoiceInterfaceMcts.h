#pragma once
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.SpeechRecognition.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineVoiceInterfaceMcts : public Object
	{
	public:
		enum EMuteType : byte
		{
			MUTE_None = 0,
			MUTE_AllButFriends = 1,
			MUTE_All = 2,
			MUTE_MAX = 3,
		};
		class LocalTalkerMcts
		{
		public:
			ADD_STRUCT(OnlineVoiceInterfaceMcts::EMuteType, MuteType, 4)
			ADD_BOOL(bIsRegistered, 0, 0x20)
			ADD_BOOL(bIsTalking, 0, 0x10)
			ADD_BOOL(bWasTalking, 0, 0x8)
			ADD_BOOL(bIsRecognizingSpeech, 0, 0x4)
			ADD_BOOL(bHasNetworkedVoice, 0, 0x2)
			ADD_BOOL(bHasVoice, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<OnlineSubsystem::RemoteTalker>, RemoteTalkers, 76)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, MuteList, 88)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, SpeechRecognitionCompleteDelegates, 100)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, TalkingDelegates, 112)
		ADD_STRUCT(OnlineVoiceInterfaceMcts::LocalTalkerMcts, CurrentLocalTalker, 68)
		ADD_STRUCT(Object::Pointer, VoiceEnginePtr, 64)
		ADD_STRUCT(Object::Pointer, MctsSubsystem, 60)
		void OnRecognitionComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnRecognitionComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPlayerTalkingStateChange(OnlineSubsystem::UniqueNetId Player, bool bIsTalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnPlayerTalkingStateChange");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = Player;
			*(bool*)&params[8] = bIsTalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RegisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterLocalTalker");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool UnregisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterLocalTalker");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RegisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterRemoteTalker");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnregisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterRemoteTalker");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsLocalPlayerTalking(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsLocalPlayerTalking");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsRemotePlayerTalking(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsRemotePlayerTalking");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsHeadsetPresent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsHeadsetPresent");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetRemoteTalkerPriority(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, int Priority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetRemoteTalkerPriority");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(int*)&params[12] = Priority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool MuteRemoteTalker(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteRemoteTalker");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool UnmuteRemoteTalker(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteRemoteTalker");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddPlayerTalkingDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearPlayerTalkingDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartNetworkedVoice");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopNetworkedVoice");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StartSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartSpeechRecognition");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopSpeechRecognition");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetRecognitionResults(byte LocalUserNum, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.GetRecognitionResults");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddRecognitionCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearRecognitionCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SelectVocabulary(byte LocalUserNum, int VocabularyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SelectVocabulary");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = VocabularyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetSpeechRecognitionObject(byte LocalUserNum, class SpeechRecognition* SpeechRecogObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetSpeechRecognitionObject");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(class SpeechRecognition**)&params[4] = SpeechRecogObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MuteAll(byte LocalUserNum, bool bAllowFriends)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteAll");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(bool*)&params[4] = bAllowFriends;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnmuteAll(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteAll");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
