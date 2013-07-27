#pragma once
#include "Core.Interface.h"
#include "Engine.ParticleSystem.h"
#include "TribesGame.TrTripActor.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class Interface_TrTripNotifier : public Interface
	{
	public:
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65248);
			byte params[4] = { NULL };
			*(class TrTripActor**)params = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65250);
			byte params[4] = { NULL };
			*(class TrTripActor**)params = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TripActivated(class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65252);
			byte params[20] = { NULL };
			*(class Pawn**)params = Other;
			*(Vector*)&params[4] = ActivateLocation;
			*(class TrTripActor**)&params[16] = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65256);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)params;
		}
		bool GetTripSocketPosition(bool bIsLeft, Vector& SocketPosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65258);
			byte params[20] = { NULL };
			*(bool*)params = bIsLeft;
			*(Vector*)&params[4] = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketPosition = *(Vector*)&params[4];
			return *(bool*)&params[16];
		}
		void OnTripAwake()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65262);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTripSleep()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65263);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
