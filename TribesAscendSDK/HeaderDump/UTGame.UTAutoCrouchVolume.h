#pragma once
#include "Engine.Volume.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTAutoCrouchVolume : public Volume
	{
	public:
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40659);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCrouch(class Pawn* P, byte bCrouch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40665);
			byte params[5] = { NULL };
			*(class Pawn**)params = P;
			params[4] = bCrouch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40672);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CrouchTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40675);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
