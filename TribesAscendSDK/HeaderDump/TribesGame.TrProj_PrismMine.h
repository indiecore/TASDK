#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "TribesGame.TrTripActor.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_PrismMine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_PrismMine : public TrProj_Mine
	{
	public:
		ADD_STRUCT(::VectorProperty, r_vRightHit, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, r_vLeftHit, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_nSocketTraceName, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate)
		ADD_VAR(::FloatProperty, m_fTripDistance, 0xFFFFFFFF)
		ADD_OBJECT(TrTripActor, m_TripActor)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_TrTripNotifier'!
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.PawnEnteredDetonationArea");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.InitProjectile");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(ScriptClass**)(params + 12) = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void TripActivated(class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.TripActivated");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = Other;
			*(Vector*)(params + 4) = ActivateLocation;
			*(class TrTripActor**)(params + 16) = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.GetParticleSystemName");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ParticleSystem**)params;
			free(params);
			return returnVal;
		}
		bool GetTripSocketPosition(bool bIsLeft, Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.GetTripSocketPosition");
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
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PrismMine.RemoveTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
