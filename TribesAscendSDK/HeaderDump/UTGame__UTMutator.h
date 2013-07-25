#pragma once
#include "Engine__Mutator.h"
#include "UTGame__UTPlayerController.h"
#include "Engine__Actor.h"
namespace UnrealScript
{
	class UTMutator : public Mutator
	{
	public:
		class UTMutator* GetNextUTMutator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.GetNextUTMutator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTMutator**)params;
			free(params);
			return returnVal;
		}
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.MutatorIsAllowed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ReplaceWith(class Actor* Other, ScriptArray<wchar_t> aClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.ReplaceWith");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = Other;
			*(ScriptArray<wchar_t>*)(params + 4) = aClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator.ProcessSpeechRecognition");
			byte* params = (byte*)malloc(16);
			*(class UTPlayerController**)params = Speaker;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Words;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Words = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
	};
}
