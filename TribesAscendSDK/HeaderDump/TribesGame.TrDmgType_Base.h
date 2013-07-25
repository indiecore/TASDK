#pragma once
#include "UTGame.UTDamageType.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.SoundCue.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.Vehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDmgType_Base." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDmgType_Base." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDmgType_Base." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDmgType_Base : public UTDamageType
	{
	public:
		ADD_VAR(::IntProperty, DBWeaponId, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDamageMultiplierAgainstArmor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDamageMultiplierAgainstNonArmoredObjectives, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_EnergyDrainAmount, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_RingingSound)
		ADD_VAR(::NameProperty, m_nmTakeHitSoundMode, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bCausesGib, 0x1)
		ADD_VAR(::FloatProperty, m_fGibRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fGibStrength, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_GibFalloff, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bEnableMotors, 0x2)
		ADD_VAR(::FloatProperty, m_fDamageMultiplierAgainstGenerators, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2DDamageNumbersMinMaxZ'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2DDamageNumbersMinMaxY'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2DDamageNumbersMinMaxX'!
		ADD_VAR(::IntProperty, m_nKillIconIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_nmCameraShake, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOffhandType, 0x10)
		ADD_VAR(::BoolProperty, m_bImpulsesFlags, 0x8)
		ADD_VAR(::BoolProperty, m_bIgnoreDamageFalloff, 0x4)
		ADD_VAR(::FloatProperty, m_fDamageMultiplierAgainstShrike, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBulletDamageRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinDamagePct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinDamageRangePct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxDamageRangePct, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DBWeaponTypeId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DBWeaponBaseId, 0xFFFFFFFF)
		float CalculateRangeDamageFalloff(float Dist, float damageRange, class TrPlayerController* TrPCDamager, byte EquipPoint, bool bMinDamageAlwaysApplied)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDmgType_Base.CalculateRangeDamageFalloff");
			byte* params = (byte*)malloc(21);
			*(float*)params = Dist;
			*(float*)(params + 4) = damageRange;
			*(class TrPlayerController**)(params + 8) = TrPCDamager;
			*(params + 12) = EquipPoint;
			*(bool*)(params + 16) = bMinDamageAlwaysApplied;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 20);
			free(params);
			return returnVal;
		}
		class Actor* GetActorCausingDamage(class Controller* EventInstigator, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDmgType_Base.GetActorCausingDamage");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = EventInstigator;
			*(class Actor**)(params + 4) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 8);
			free(params);
			return returnVal;
		}
		Vector ModifyOverheadNumberLocation(Vector InLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDmgType_Base.ModifyOverheadNumberLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetDamageScale(class Actor* DamageCauser, float Dist, ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDmgType_Base.GetDamageScale");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = DamageCauser;
			*(float*)(params + 4) = Dist;
			*(ScriptClass**)(params + 8) = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptName GetRandomDeathAnimName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDmgType_Base.GetRandomDeathAnimName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		float VehicleDamageScalingFor(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDmgType_Base.VehicleDamageScalingFor");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetCameraShake(int Damage, ScriptName& outCameraShakeName, float& outScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDmgType_Base.GetCameraShake");
			byte* params = (byte*)malloc(16);
			*(int*)params = Damage;
			*(ScriptName*)(params + 4) = outCameraShakeName;
			*(float*)(params + 12) = outScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			outCameraShakeName = *(ScriptName*)(params + 4);
			outScale = *(float*)(params + 12);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
