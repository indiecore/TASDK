#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.SoundCue.h"
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
	class TrProj_RepairDeployable : public TrProj_Mine
	{
	public:
		ADD_STRUCT(ScriptArray<class Actor*>, ActorsToRepair, 920)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, RepairBeams, 932)
		ADD_STRUCT(float, m_fTickFrequency, 956)
		ADD_STRUCT(float, m_fTimeSinceLastTick, 952)
		ADD_OBJECT(SoundCue, RepairBeamSound, 944)
		ADD_STRUCT(float, m_fVehicleRepairPercentage, 916)
		ADD_STRUCT(float, m_fRepairPercentage, 912)
		ADD_STRUCT(float, m_fRepairBuff, 908)
		ADD_STRUCT(float, m_fRepairRadius, 904)
		ADD_STRUCT(float, m_fCheckNearbyActorsFrequency, 900)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108974);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108975);
			byte params[16] = { NULL };
			*(Vector*)params = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArmedTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108981);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108982);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckRepair()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108987);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108993);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetonateObsolete(bool bDetonateFromDamage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108996);
			byte params[4] = { NULL };
			*(bool*)params = bDetonateFromDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
