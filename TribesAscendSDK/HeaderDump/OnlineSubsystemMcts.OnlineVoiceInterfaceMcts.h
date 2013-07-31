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
		struct LocalTalkerMcts
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157037);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPlayerTalkingStateChange(OnlineSubsystem::UniqueNetId Player, bool bIsTalking)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157040);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = Player;
			*(bool*)&params[8] = bIsTalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RegisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157054);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool UnregisterLocalTalker(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157057);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RegisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157060);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnregisterRemoteTalker(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157063);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsLocalPlayerTalking(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157066);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsRemotePlayerTalking(OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157069);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsHeadsetPresent(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157072);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetRemoteTalkerPriority(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, int Priority)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157075);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(int*)&params[12] = Priority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool MuteRemoteTalker(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157080);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool UnmuteRemoteTalker(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID, bool bIsSystemWide)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157085);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			*(bool*)&params[12] = bIsSystemWide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddPlayerTalkingDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* TalkerDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157092);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157095);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = TalkerDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157098);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopNetworkedVoice(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157100);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StartSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157102);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool StopSpeechRecognition(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157105);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetRecognitionResults(byte LocalUserNum, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157108);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157113);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157116);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = RecognitionDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SelectVocabulary(byte LocalUserNum, int VocabularyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157120);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = VocabularyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetSpeechRecognitionObject(byte LocalUserNum, class SpeechRecognition* SpeechRecogObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157124);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(class SpeechRecognition**)&params[4] = SpeechRecogObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MuteAll(byte LocalUserNum, bool bAllowFriends)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157128);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bAllowFriends;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnmuteAll(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(157132);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
