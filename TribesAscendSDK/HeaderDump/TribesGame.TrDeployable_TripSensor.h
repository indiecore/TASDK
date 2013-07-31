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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80439);
			byte params[4] = { NULL };
			*(class TrTripActor**)params = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80441);
			byte params[4] = { NULL };
			*(class TrTripActor**)params = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TripActivated(class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80443);
			byte params[20] = { NULL };
			*(class Pawn**)params = Other;
			*(Vector*)&params[4] = ActivateLocation;
			*(class TrTripActor**)&params[16] = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80447);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)params;
		}
		bool GetTripSocketPosition(bool bIsLeft, Vector& SocketPosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80449);
			byte params[20] = { NULL };
			*(bool*)params = bIsLeft;
			*(Vector*)&params[4] = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketPosition = *(Vector*)&params[4];
			return *(bool*)&params[16];
		}
		void OnTripAwake()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTripSleep()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80454);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
