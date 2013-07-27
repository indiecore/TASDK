#pragma once
#include "Engine.PhysicsVolume.h"
#include "Engine.SoundCue.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class WaterVolume : public PhysicsVolume
	{
	public:
		ADD_OBJECT(ScriptClass, ExitActor, 596)
		ADD_OBJECT(SoundCue, ExitSound, 592)
		ADD_OBJECT(ScriptClass, EntryActor, 588)
		ADD_OBJECT(SoundCue, EntrySound, 584)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WaterVolume.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayEntrySplash(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WaterVolume.PlayEntrySplash");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WaterVolume.UnTouch");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayExitSplash(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WaterVolume.PlayExitSplash");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
