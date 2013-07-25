#pragma once
#include "Engine.Weapon.h"
#include "UDKBase.UDKPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKWeapon : public Weapon
	{
	public:
		ADD_VAR(::FloatProperty, AimTraceRange, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, HitEnemy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AmmoCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bConsiderProjectileAcceleration, 0x2)
		ADD_VAR(::BoolProperty, bLeadTarget, 0x1)
		bool IsAimCorrect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.IsAimCorrect");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		byte BestMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.BestMode");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnsureWeaponOverlayComponentLast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.EnsureWeaponOverlayComponentLast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.SetPosition");
			byte* params = (byte*)malloc(8);
			*(class UDKPawn**)params = Holder;
			*(float*)(params + 4) = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
