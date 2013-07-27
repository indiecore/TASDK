#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrTripActor : public Actor
	{
	public:
		ADD_STRUCT(float, m_fSleepTime, 492)
		ADD_OBJECT(Actor, r_Left, 476)
		ADD_OBJECT(Actor, r_Right, 480)
		ADD_BOOL(m_bRequiresTwoNotifiers, 484, 0x4)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate, 520)
		ADD_STRUCT(float, r_fSleepEndTime, 488)
		ADD_BOOL(r_bIsInitialized, 484, 0x2)
		ADD_BOOL(r_bIsPowered, 484, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateTripComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.CreateTripComponent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientCreateVisualEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.ClientCreateVisualEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyNotify(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Notifier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.DestroyNotify");
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = Notifier;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeTripPhysics(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Left, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Right)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.InitializeTripPhysics");
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = Left;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[8] = Right;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GoToSleep(bool bIsPowered)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.GoToSleep");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsPowered;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
