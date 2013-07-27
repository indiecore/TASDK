#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrCollisionProxy_Rage : public TrCollisionProxy
	{
	public:
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_Rage.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_Rage.UnTouch");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceProximityScan(float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_Rage.ForceProximityScan");
			byte params[4] = { NULL };
			*(float*)&params[0] = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
