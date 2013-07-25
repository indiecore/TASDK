#pragma once
#include "TribesGame__TrProj_Mine.h"
#include "Engine__SoundCue.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_RepairDeployable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_RepairDeployable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_RepairDeployable : public TrProj_Mine
	{
	public:
		ADD_VAR(::FloatProperty, m_fTickFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeSinceLastTick, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RepairBeamSound)
		ADD_VAR(::FloatProperty, m_fVehicleRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairPercentage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRepairRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCheckNearbyActorsFrequency, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_RepairDeployable.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_RepairDeployable.InitProjectile");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(ScriptClass**)(params + 12) = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArmedTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_RepairDeployable.ArmedTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_RepairDeployable.HitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckRepair()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_RepairDeployable.CheckRepair");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_RepairDeployable.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetonateObsolete(bool bDetonateFromDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_RepairDeployable.DetonateObsolete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDetonateFromDamage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
