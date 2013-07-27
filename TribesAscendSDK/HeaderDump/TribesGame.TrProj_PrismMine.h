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
		ADD_STRUCT(Object::Vector, r_vRightHit, 936)
		ADD_STRUCT(Object::Vector, r_vLeftHit, 924)
		ADD_STRUCT(ScriptName, m_nSocketTraceName, 916)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate, 912)
		ADD_STRUCT(float, m_fTripDistance, 908)
		ADD_OBJECT(TrTripActor, m_TripActor, 904)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_TrTripNotifier, 900)
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.PawnEnteredDetonationArea");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitProjectile(Object::Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.InitProjectile");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArmedTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.ArmedTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateTripActor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.CreateTripActor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TripActivated(class Pawn* Other, Object::Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.TripActivated");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(Object::Vector*)&params[4] = ActivateLocation;
			*(class TrTripActor**)&params[16] = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.GetParticleSystemName");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)&params[0];
		}
		bool GetTripSocketPosition(bool bIsLeft, Object::Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.GetTripSocketPosition");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bIsLeft;
			*(Object::Vector*)&params[4] = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketPosition = *(Object::Vector*)&params[4];
			return *(bool*)&params[16];
		}
		void OnTripAwake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.OnTripAwake");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTripSleep()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.OnTripSleep");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.AddTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.RemoveTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
