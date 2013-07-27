#pragma once
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
namespace UnrealScript
{
	class AlienFXManager : public Object
	{
	public:
		enum FXOverlay : byte
		{
			FXO_NONE = 0,
			FXO_RAGE = 1,
			FXO_REGEN = 2,
			FXO_DYING = 3,
			FXO_INVULN = 4,
			FXO_JAMMER = 5,
			FXO_SHIELD = 6,
			FXO_STEALTH = 7,
			FXO_MAX = 8,
		};
		enum FXArea : byte
		{
			FXA_ALL = 0,
			FXA_RIGHT = 1,
			FXA_LEFT = 2,
			FXA_UPPER = 3,
			FXA_LOWER = 4,
			FXA_FRONT = 5,
			FXA_REAR = 6,
			FXA_MAX = 7,
		};
		ADD_STRUCT(AlienFXManager::FXOverlay, eLastOverlay, 141)
		ADD_STRUCT(AlienFXManager::FXOverlay, eCurrOverlay, 140)
		ADD_STRUCT(float, fIntervalCount, 136)
		ADD_STRUCT(float, fInterval, 132)
		ADD_STRUCT(float, fSpeed, 128)
		ADD_STRUCT(float, fBoundsPct, 124)
		ADD_STRUCT(float, fHighBounds, 120)
		ADD_STRUCT(float, fLowBounds, 116)
		ADD_STRUCT(int, nTarget, 112)
		ADD_STRUCT(float, fDamages, 80)
		ADD_STRUCT(float, fObjectiveTime, 76)
		ADD_STRUCT(float, fDamageTime, 72)
		ADD_BOOL(bBrighten, 68, 0x8)
		ADD_BOOL(bMenuOpen, 68, 0x4)
		ADD_BOOL(bLoaded, 68, 0x2)
		ADD_BOOL(bShowFX, 68, 0x1)
		ADD_STRUCT(int, nHealth, 64)
		ADD_STRUCT(int, nTeam, 60)
		void Init(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Init");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bOpen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Damage(AlienFXManager::FXArea Area)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Damage");
			byte params[1] = { NULL };
			*(AlienFXManager::FXArea*)&params[0] = Area;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeam(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.SetTeam");
			byte params[4] = { NULL };
			*(int*)&params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHealth(int Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.SetHealth");
			byte params[4] = { NULL };
			*(int*)&params[0] = Health;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Overlay(AlienFXManager::FXOverlay Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.Overlay");
			byte params[1] = { NULL };
			*(AlienFXManager::FXOverlay*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DamageConvert(ScriptString* Area)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.AlienFXManager.DamageConvert");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Area;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
