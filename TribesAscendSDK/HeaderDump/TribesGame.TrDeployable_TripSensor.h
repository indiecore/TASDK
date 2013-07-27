#pragma once
#include "TribesGame.TrDeployable_Sensor.h"
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
#include "TribesGame.TrTripActor.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_TripSensor : public TrDeployable_Sensor
	{
	public:
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_TrTripNotifier, 1540)
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.AddTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.RemoveTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TripActivated(class Pawn* Other, Object::Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.TripActivated");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(Object::Vector*)&params[4] = ActivateLocation;
			*(class TrTripActor**)&params[16] = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.GetParticleSystemName");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)&params[0];
		}
		bool GetTripSocketPosition(bool bIsLeft, Object::Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.GetTripSocketPosition");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bIsLeft;
			*(Object::Vector*)&params[4] = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketPosition = *(Object::Vector*)&params[4];
			return *(bool*)&params[16];
		}
		void OnTripAwake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.OnTripAwake");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTripSleep()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.OnTripSleep");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
