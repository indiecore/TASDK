#pragma once
#include "Engine.PhysicsVolume.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTKillZVolume : public PhysicsVolume
	{
	public:
		ADD_OBJECT(ScriptClass, KillZDamageType, 584)
		void ActorEnteredVolume(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKillZVolume.ActorEnteredVolume");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKillZVolume.PawnEnteredVolume");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKillZVolume.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillActor(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTKillZVolume.KillActor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
