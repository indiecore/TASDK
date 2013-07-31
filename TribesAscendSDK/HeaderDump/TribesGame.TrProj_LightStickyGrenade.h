#pragma once
#include "TribesGame.TrProj_Grenade.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class TrProj_LightStickyGrenade : public TrProj_Grenade
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108623);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108624);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108628);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
