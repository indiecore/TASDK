#pragma once
#include "Engine__Pawn.h"
#include "Engine__Volume.h"
#include "Engine__Actor.h"
namespace UnrealScript
{
	class UTAutoCrouchVolume : public Volume
	{
	public:
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAutoCrouchVolume.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCrouch(class Pawn* P, byte bCrouch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAutoCrouchVolume.SetCrouch");
			byte* params = (byte*)malloc(5);
			*(class Pawn**)params = P;
			*(params + 4) = bCrouch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAutoCrouchVolume.UnTouch");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CrouchTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAutoCrouchVolume.CrouchTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
