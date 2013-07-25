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
		// Here lies the not-yet-implemented method 'OnRecognitionComplete'
		// Here lies the not-yet-implemented method 'OnPlayerTalkingStateChange'
		// Here lies the not-yet-implemented method 'RegisterLocalTalker'
		// Here lies the not-yet-implemented method 'UnregisterLocalTalker'
		// Here lies the not-yet-implemented method 'RegisterRemoteTalker'
		// Here lies the not-yet-implemented method 'UnregisterRemoteTalker'
		// Here lies the not-yet-implemented method 'IsLocalPlayerTalking'
		// Here lies the not-yet-implemented method 'IsRemotePlayerTalking'
		// Here lies the not-yet-implemented method 'IsHeadsetPresent'
		// Here lies the not-yet-implemented method 'SetRemoteTalkerPriority'
		// Here lies the not-yet-implemented method 'MuteRemoteTalker'
		// Here lies the not-yet-implemented method 'UnmuteRemoteTalker'
		// Here lies the not-yet-implemented method 'AddPlayerTalkingDelegate'
		// Here lies the not-yet-implemented method 'ClearPlayerTalkingDelegate'
		// Here lies the not-yet-implemented method 'StartNetworkedVoice'
		// Here lies the not-yet-implemented method 'StopNetworkedVoice'
		// Here lies the not-yet-implemented method 'StartSpeechRecognition'
		// Here lies the not-yet-implemented method 'StopSpeechRecognition'
		// Here lies the not-yet-implemented method 'GetRecognitionResults'
		// Here lies the not-yet-implemented method 'AddRecognitionCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearRecognitionCompleteDelegate'
		// Here lies the not-yet-implemented method 'SelectVocabulary'
		// Here lies the not-yet-implemented method 'SetSpeechRecognitionObject'
		// Here lies the not-yet-implemented method 'MuteAll'
		// Here lies the not-yet-implemented method 'UnmuteAll'
	};
}
#undef ADD_STRUCT
