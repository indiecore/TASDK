#pragma once
#include "TribesGame.TrDeployable.h"
#include "Engine.SoundCue.h"
#include "Engine.Texture2D.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_Turret." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_Turret." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_Turret : public TrDeployable
	{
	public:
		ADD_VAR(::FloatProperty, m_fLastStallTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFireStallRestoreTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeToIgnoreInvulnerable, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeToAcquireTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTargetAcquiredTime, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_TargetAcquiredSoundCue)
		ADD_VAR(::FloatProperty, m_fDeltaFireInterval, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_MuzzleFlashLightClass)
		ADD_VAR(::BoolProperty, m_bCanTargetVehicles, 0x2)
		ADD_VAR(::BoolProperty, m_bEnabled, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AcquireTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.AcquireTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetAcquireDelayTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.GetAcquireDelayTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void CleanupIgnoreList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.CleanupIgnoreList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanTargetPawn(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.CanTargetPawn");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Pawn* GetTargetPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.GetTargetPawn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Pawn**)params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateAim(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.UpdateAim");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFireEffects(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.PlayFireEffects");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.CauseMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.MuzzleFlashTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMuzzleFlashParams(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* MuzzleFlashColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.SetMuzzleFlashParams");
			byte* params = (byte*)malloc(8);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4) = MuzzleFlashColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.GetWeaponStartTraceLocation");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
		void AwardKillAssists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Turret.AwardKillAssists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
