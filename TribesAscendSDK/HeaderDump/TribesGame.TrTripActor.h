#pragma once
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTripActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTripActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTripActor : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, m_fSleepTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, r_Left)
		ADD_OBJECT(Actor, r_Right)
		ADD_VAR(::BoolProperty, m_bRequiresTwoNotifiers, 0x4)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate)
		ADD_VAR(::FloatProperty, r_fSleepEndTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bIsInitialized, 0x2)
		ADD_VAR(::BoolProperty, r_bIsPowered, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = Notifier;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = Left;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)(params + 8) = Right;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GoToSleep(bool bIsPowered)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.GoToSleep");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsPowered;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTripActor.Touch");
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
