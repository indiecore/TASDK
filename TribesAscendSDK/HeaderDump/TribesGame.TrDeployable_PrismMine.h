#pragma once
#include "TribesGame.TrDeployable.h"
#include "Engine.ParticleSystem.h"
#include "TribesGame.TrTripActor.h"
#include "Engine.SoundCue.h"
#include "Core.Object.h"
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
	class TrDeployable_PrismMine : public TrDeployable
	{
	public:
		ADD_STRUCT(ScriptArray<class TrTripActor*>, m_aTripActors, 1528)
		ADD_OBJECT(SoundCue, m_HitSound, 1576)
		ADD_OBJECT(SoundCue, m_DeactivateSound, 1572)
		ADD_OBJECT(SoundCue, m_ActivateSound, 1568)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate, 1564)
		ADD_STRUCT(int, m_DamageAmount, 1560)
		ADD_STRUCT(float, m_fSleepTimeAfterHit, 1556)
		ADD_OBJECT(ScriptClass, m_DamageType, 1552)
		ADD_STRUCT(ScriptName, m_nSocketTraceName, 1544)
		ADD_STRUCT(float, m_fPrismRadius, 1540)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_TrTripNotifier, 1524)
		void CreateTripActor(class TrDeployable_PrismMine* Right, Object::Vector LeftLocation, Object::Vector RightLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.CreateTripActor");
			byte params[28] = { NULL };
			*(class TrDeployable_PrismMine**)&params[0] = Right;
			*(Object::Vector*)&params[4] = LeftLocation;
			*(Object::Vector*)&params[16] = RightLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyTripActor(class TrTripActor* DestroyTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.DestroyTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = DestroyTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.AddTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.RemoveTripActor");
			byte params[4] = { NULL };
			*(class TrTripActor**)&params[0] = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TripActivated(class Pawn* Other, Object::Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.TripActivated");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(Object::Vector*)&params[4] = ActivateLocation;
			*(class TrTripActor**)&params[16] = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.GetParticleSystemName");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)&params[0];
		}
		bool GetTripSocketPosition(bool bIsLeft, Object::Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.GetTripSocketPosition");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bIsLeft;
			*(Object::Vector*)&params[4] = SocketPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SocketPosition = *(Object::Vector*)&params[4];
			return *(bool*)&params[16];
		}
		void OnTripAwake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.OnTripAwake");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTripSleep()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.OnTripSleep");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NoConnectionExists(class TrDeployable_PrismMine* AdjacentMine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.NoConnectionExists");
			byte params[8] = { NULL };
			*(class TrDeployable_PrismMine**)&params[0] = AdjacentMine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
