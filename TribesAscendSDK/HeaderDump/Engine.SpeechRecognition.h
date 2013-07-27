#pragma once
#include "Core.Object.h"
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
	class SpeechRecognition : public Object
	{
	public:
		struct RecognisableWord
		{
		public:
			ADD_STRUCT(ScriptString*, PhoneticWord, 16)
			ADD_STRUCT(ScriptString*, ReferenceWord, 4)
			ADD_STRUCT(int, Id, 0)
		};
		struct RecogUserData
		{
		public:
			ADD_STRUCT(ScriptArray<byte>, UserData, 4)
			ADD_STRUCT(int, ActiveVocabularies, 0)
		};
		struct RecogVocabulary
		{
		public:
			ADD_STRUCT(ScriptArray<SpeechRecognition::RecognisableWord>, WhoDictionary, 0)
			ADD_STRUCT(ScriptArray<SpeechRecognition::RecognisableWord>, WhatDictionary, 12)
			ADD_STRUCT(ScriptArray<SpeechRecognition::RecognisableWord>, WhereDictionary, 24)
			ADD_STRUCT(ScriptArray<byte>, VocabData, 48)
			ADD_STRUCT(ScriptArray<byte>, WorkingVocabData, 60)
			ADD_STRUCT(ScriptString*, VocabName, 36)
		};
		ADD_STRUCT(ScriptArray<SpeechRecognition::RecogVocabulary>, Vocabularies, 76)
		ADD_STRUCT(ScriptArray<byte>, VoiceData, 88)
		ADD_STRUCT(ScriptArray<byte>, WorkingVoiceData, 100)
		ADD_STRUCT(ScriptArray<byte>, UserData, 112)
		ADD_STRUCT(Object::Pointer, FnxVoiceData, 192)
		ADD_BOOL(bInitialised, 188, 0x2)
		ADD_BOOL(bDirty, 188, 0x1)
		ADD_STRUCT(SpeechRecognition::RecogUserData, InstanceData, 124)
		ADD_STRUCT(float, ConfidenceThreshhold, 72)
		ADD_STRUCT(ScriptString*, Language, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
