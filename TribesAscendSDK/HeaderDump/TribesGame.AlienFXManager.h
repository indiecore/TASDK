#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.AlienFXManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AlienFXManager : public Object
	{
	public:
		ADD_VAR(::ByteProperty, eLastOverlay, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, eCurrOverlay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fIntervalCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fBoundsPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fHighBounds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fLowBounds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fDamages, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fObjectiveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fDamageTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBrighten, 0x8)
		ADD_VAR(::BoolProperty, bMenuOpen, 0x4)
		ADD_VAR(::BoolProperty, bLoaded, 0x2)
		ADD_VAR(::BoolProperty, bShowFX, 0x1)
		ADD_VAR(::IntProperty, nHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nTeam, 0xFFFFFFFF)
		void Init(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Init");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Close()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Close");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Queued()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Queued");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Objective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Objective");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.SwapWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckHealth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.CheckHealth");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void menu(bool bOpen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.menu");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bOpen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Damage(byte Area)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Damage");
			byte* params = (byte*)malloc(1);
			*params = Area;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTeam(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.SetTeam");
			byte* params = (byte*)malloc(4);
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHealth(int Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.SetHealth");
			byte* params = (byte*)malloc(4);
			*(int*)params = Health;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Overlay(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Overlay");
			byte* params = (byte*)malloc(1);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DamageConvert(ScriptArray<wchar_t> Area)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.DamageConvert");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Area;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
