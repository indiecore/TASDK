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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.AddTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.RemoveTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TripActivated(class Pawn* Other, Object::Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.TripActivated");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(Object::Vector*)&params[4] = ActivateLocation;
			*(class TrTripActor**)&params[16] = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.GetParticleSystemName");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)&params[0];
		}
		bool GetTripSocketPosition(bool bIsLeft, Object::Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.GetTripSocketPosition");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bIsLeft;
			*(Object::Vector*)&params[4] = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketPosition = *(Object::Vector*)&params[4];
			return *(bool*)&params[16];
		}
		void OnTripAwake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.OnTripAwake");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTripSleep()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.OnTripSleep");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
