#pragma once
#include "Engine.SkelControlLookAt.h"
#include "TribesGame.TrDeployable.h"
#include "GameFramework.GameSkelCtrl_Recoil.h"
#include "Engine.SoundCue.h"
#include "Engine.Texture2D.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class TrDeployable_Turret : public TrDeployable
	{
	public:
		struct IgnorePawn
		{
		public:
			ADD_STRUCT(float, UnignoreTime, 4)
			ADD_OBJECT(TrPawn, PawnToIgnore, 0)
		};
		ADD_STRUCT(ScriptArray<class SkelControlLookAt*>, m_LookAtSkelControls, 1528)
		ADD_STRUCT(ScriptArray<ScriptName>, m_LookAtSkelControlNames, 1540)
		ADD_STRUCT(ScriptArray<class GameSkelCtrl_Recoil*>, m_RecoilSkelControls, 1552)
		ADD_STRUCT(ScriptArray<ScriptName>, m_RecoilSkelControlNames, 1564)
		ADD_STRUCT(ScriptArray<TrDeployable_Turret::IgnorePawn>, m_IgnorePawnList, 1604)
		ADD_STRUCT(float, m_fLastStallTime, 1624)
		ADD_STRUCT(float, m_fFireStallRestoreTime, 1620)
		ADD_STRUCT(float, m_fTimeToIgnoreInvulnerable, 1616)
		ADD_STRUCT(float, m_fTimeToAcquireTarget, 1600)
		ADD_STRUCT(float, m_fTargetAcquiredTime, 1596)
		ADD_OBJECT(SoundCue, m_TargetAcquiredSoundCue, 1592)
		ADD_STRUCT(float, m_fDeltaFireInterval, 1588)
		ADD_OBJECT(ScriptClass, m_MuzzleFlashLightClass, 1580)
		ADD_BOOL(m_bCanTargetVehicles, 1524, 0x2)
		ADD_BOOL(m_bEnabled, 1524, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71956);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71957);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DeployComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71960);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AcquireTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71961);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetAcquireDelayTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71966);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void CleanupIgnoreList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71975);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanTargetPawn(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71978);
			byte params[8] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Pawn* GetTargetPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71990);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pawn**)params;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72004);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateAim(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72006);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireEffects(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72011);
			byte params[20] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CauseMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72016);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MuzzleFlashTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72018);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMuzzleFlashParams(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC, Object::Color MuzzleFlashColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72019);
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			*(Object::Color*)&params[4] = MuzzleFlashColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72022);
			byte params[16] = { NULL };
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72029);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
		void AwardKillAssists()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72032);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
