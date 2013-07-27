#pragma once
#include "Engine.Mutator.h"
#include "Engine.Actor.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.OnlineSubsystem.h"
namespace UnrealScript
{
	class UTMutator : public Mutator
	{
	public:
		class UTMutator* GetNextUTMutator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.GetNextUTMutator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTMutator**)&params[0];
		}
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.MutatorIsAllowed");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ReplaceWith(class Actor* Other, ScriptString* aClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.ReplaceWith");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(ScriptString**)&params[4] = aClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.ProcessSpeechRecognition");
			byte params[16] = { NULL };
			*(class UTPlayerController**)&params[0] = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
		}
	};
}
