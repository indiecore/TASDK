#pragma once
#include "Core.Object.Vector.h"
#include "Core.Interface.h"
#include "Engine.ParticleSystem.h"
#include "TribesGame.TrTripActor.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class Interface_TrTripNotifier : public Interface
	{
	public:
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.AddTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.RemoveTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TripActivated(class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.TripActivated");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = Other;
			*(Vector*)(params + 4) = ActivateLocation;
			*(class TrTripActor**)(params + 16) = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.GetParticleSystemName");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ParticleSystem**)params;
			free(params);
			return returnVal;
		}
		bool GetTripSocketPosition(bool bIsLeft, Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.Interface_TrTripNotifier.GetTripSocketPosition");
			byte* params = (byte*)malloc(20);
			*(bool*)params = bIsLeft;
			*(Vector*)(params + 4) = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SocketPosition = *(Vector*)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
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
