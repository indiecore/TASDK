#pragma once
#include "TribesGame__TrDeployable_Sensor.h"
#include "Engine__Pawn.h"
#include "TribesGame__TrTripActor.h"
#include "Engine__ParticleSystem.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable_TripSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_TripSensor : public TrDeployable_Sensor
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_TrTripNotifier'!
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.AddTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.RemoveTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TripActivated(class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.TripActivated");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = Other;
			*(Vector*)(params + 4) = ActivateLocation;
			*(class TrTripActor**)(params + 16) = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.GetParticleSystemName");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ParticleSystem**)params;
			free(params);
			return returnVal;
		}
		bool GetTripSocketPosition(bool bIsLeft, Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TripSensor.GetTripSocketPosition");
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
