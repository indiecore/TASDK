#pragma once
#include "UTGame.UTDamageType.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.SoundCue.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Vehicle.h"
#include "TribesGame.TrObject.h"
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
	class TrDmgType_Base : public UTDamageType
	{
	public:
		ADD_STRUCT(int, DBWeaponId, 300)
		ADD_STRUCT(float, m_fDamageMultiplierAgainstArmor, 328)
		ADD_STRUCT(float, m_fDamageMultiplierAgainstNonArmoredObjectives, 336)
		ADD_STRUCT(float, m_EnergyDrainAmount, 396)
		ADD_OBJECT(SoundCue, m_RingingSound, 380)
		ADD_STRUCT(ScriptName, m_nmTakeHitSoundMode, 384)
		ADD_BOOL(m_bCausesGib, 344, 0x1)
		ADD_STRUCT(float, m_fGibRadius, 348)
		ADD_STRUCT(float, m_fGibStrength, 352)
		ADD_STRUCT(PrimitiveComponent::ERadialImpulseFalloff, m_GibFalloff, 356)
		ADD_BOOL(m_bEnableMotors, 344, 0x2)
		ADD_STRUCT(float, m_fDamageMultiplierAgainstGenerators, 332)
		ADD_STRUCT(ScriptArray<ScriptName>, m_nmDeathAnimNames, 360)
		ADD_STRUCT(Object::Vector2D, m_v2DDamageNumbersMinMaxZ, 416)
		ADD_STRUCT(Object::Vector2D, m_v2DDamageNumbersMinMaxY, 408)
		ADD_STRUCT(Object::Vector2D, m_v2DDamageNumbersMinMaxX, 400)
		ADD_STRUCT(int, m_nKillIconIndex, 392)
		ADD_STRUCT(ScriptName, m_nmCameraShake, 372)
		ADD_BOOL(bOffhandType, 344, 0x10)
		ADD_BOOL(m_bImpulsesFlags, 344, 0x8)
		ADD_BOOL(m_bIgnoreDamageFalloff, 344, 0x4)
		ADD_STRUCT(float, m_fDamageMultiplierAgainstShrike, 340)
		ADD_STRUCT(float, m_fBulletDamageRange, 324)
		ADD_STRUCT(float, m_fMinDamagePct, 320)
		ADD_STRUCT(float, m_fMinDamageRangePct, 316)
		ADD_STRUCT(float, m_fMaxDamageRangePct, 312)
		ADD_STRUCT(int, DBWeaponTypeId, 308)
		ADD_STRUCT(int, DBWeaponBaseId, 304)
		float CalculateRangeDamageFalloff(float Dist, float damageRange, class TrPlayerController* TrPCDamager, TrObject::TR_EQUIP_POINT EquipPoint, bool bMinDamageAlwaysApplied)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67461);
			byte params[21] = { NULL };
			*(float*)params = Dist;
			*(float*)&params[4] = damageRange;
			*(class TrPlayerController**)&params[8] = TrPCDamager;
			*(TrObject::TR_EQUIP_POINT*)&params[12] = EquipPoint;
			*(bool*)&params[16] = bMinDamageAlwaysApplied;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[20];
		}
		class Actor* GetActorCausingDamage(class Controller* EventInstigator, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71538);
			byte params[12] = { NULL };
			*(class Controller**)params = EventInstigator;
			*(class Actor**)&params[4] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[8];
		}
		Vector ModifyOverheadNumberLocation(Vector InLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71540);
			byte params[24] = { NULL };
			*(Vector*)params = InLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		float GetDamageScale(class Actor* DamageCauser, float Dist, ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71815);
			byte params[16] = { NULL };
			*(class Actor**)params = DamageCauser;
			*(float*)&params[4] = Dist;
			*(ScriptClass**)&params[8] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		ScriptName GetRandomDeathAnimName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73055);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		float VehicleDamageScalingFor(class Vehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86444);
			byte params[8] = { NULL };
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void GetCameraShake(int Damage, ScriptName& outCameraShakeName, float& outScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86471);
			byte params[16] = { NULL };
			*(int*)params = Damage;
			*(ScriptName*)&params[4] = outCameraShakeName;
			*(float*)&params[12] = outScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			outCameraShakeName = *(ScriptName*)&params[4];
			outScale = *(float*)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
