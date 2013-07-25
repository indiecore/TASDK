#pragma once
#include "Engine__SoundCue.h"
#include "TribesGame__TrDeployable.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Pawn.h"
#include "TribesGame__TrTripActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_PrismMine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_PrismMine : public TrDeployable
	{
	public:
		ADD_OBJECT(SoundCue, m_HitSound)
		ADD_OBJECT(SoundCue, m_DeactivateSound)
		ADD_OBJECT(SoundCue, m_ActivateSound)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate)
		ADD_VAR(::IntProperty, m_DamageAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSleepTimeAfterHit, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_DamageType)
		ADD_VAR(::NameProperty, m_nSocketTraceName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPrismRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_TrTripNotifier'!
		void CreateTripActor(class TrDeployable_PrismMine* Right, Vector LeftLocation, Vector RightLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.CreateTripActor");
			byte* params = (byte*)malloc(28);
			*(class TrDeployable_PrismMine**)params = Right;
			*(Vector*)(params + 4) = LeftLocation;
			*(Vector*)(params + 16) = RightLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DestroyTripActor(class TrTripActor* DestroyTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.DestroyTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = DestroyTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddTripActor(class TrTripActor* NewTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.AddTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = NewTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveTripActor(class TrTripActor* RemoveTrip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.RemoveTripActor");
			byte* params = (byte*)malloc(4);
			*(class TrTripActor**)params = RemoveTrip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TripActivated(class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.TripActivated");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = Other;
			*(Vector*)(params + 4) = ActivateLocation;
			*(class TrTripActor**)(params + 16) = TripActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class ParticleSystem* GetParticleSystemName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.GetParticleSystemName");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ParticleSystem**)params;
			free(params);
			return returnVal;
		}
		bool GetTripSocketPosition(bool bIsLeft, Vector& SocketPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.GetTripSocketPosition");
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
			byte* params = (byte*)malloc(8);
			*(class TrDeployable_PrismMine**)params = AdjacentMine;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_PrismMine.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
