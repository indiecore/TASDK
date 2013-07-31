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
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74611);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74616);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceProximityScan(float Radius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74618);
			byte params[4] = { NULL };
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
