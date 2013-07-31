#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "Core.Object.h"
#include "TribesGame.TrTripActor.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Pawn.h"
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
	class TrProj_PrismMine : public TrProj_Mine
	{
	public:
		ADD_STRUCT(Vector, r_vRightHit, 936)
		ADD_STRUCT(Vector, r_vLeftHit, 924)
		ADD_STRUCT(ScriptName, m_nSocketTraceName, 916)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate, 912)
		ADD_STRUCT(float, m_fTripDistance, 908)
		ADD_OBJECT(TrTripActor, m_TripActor, 904)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_TrTripNotifier, 900)
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108871);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108873);
			byte params[16] = { NULL };
			*(Vector*)params = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArmedTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108876);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108885);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateTripActor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108886);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TripActivated(class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108890);
			byte params[20] = { NULL };
			*(class Pawn**)params = Other;
			*(Vector*)&params[4] = ActivateLocation;
			*(class TrTripActor**)&params[16] = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108894);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)params;
		}
		bool GetTripSocketPosition(bool bIsLeft, Vector& SocketPosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108896);
			byte params[20] = { NULL };
			*(bool*)params = bIsLeft;
			*(Vector*)&params[4] = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketPosition = *(Vector*)&params[4];
			return *(bool*)&params[16];
		}
		void OnTripAwake()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108900);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTripSleep()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108901);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108902);
			byte params[4] = { NULL };
			*(class TrTripActor**)params = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108904);
			byte params[4] = { NULL };
			*(class TrTripActor**)params = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
