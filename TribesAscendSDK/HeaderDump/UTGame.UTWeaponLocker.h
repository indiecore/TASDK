#pragma once
#include "UTGame.UTBot.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "UTGame.UTPickupFactory.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
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
	class UTWeaponLocker : public UTPickupFactory
	{
	public:
		class WeaponEntry
		{
		public:
			ADD_OBJECT(ScriptClass, WeaponClass, 0)
		};
		class PawnToucher
		{
		public:
			ADD_STRUCT(float, NextTouchTime, 4)
			ADD_OBJECT(Pawn, P, 0)
		};
		class ReplacementWeaponEntry
		{
		public:
			ADD_OBJECT(ScriptClass, WeaponClass, 4)
			ADD_BOOL(bReplaced, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<UTWeaponLocker::WeaponEntry>, Weapons, 944)
		ADD_STRUCT(ScriptArray<Object::Vector>, LockerPositions, 1004)
		ADD_STRUCT(ScriptArray<UTWeaponLocker::PawnToucher>, Customers, 1028)
		ADD_STRUCT(float, NextProximityCheckTime, 1076)
		ADD_STRUCT(float, ScaleRate, 1072)
		ADD_OBJECT(ParticleSystem, WeaponSpawnEffectTemplate, 1068)
		ADD_OBJECT(ParticleSystem, ActiveEffectTemplate, 1064)
		ADD_OBJECT(ParticleSystem, InactiveEffectTemplate, 1060)
		ADD_STRUCT(float, ProximityDistanceSquared, 1048)
		ADD_STRUCT(float, CurrentWeaponScaleX, 1044)
		ADD_BOOL(bScalingUp, 1040, 0x4)
		ADD_BOOL(bPlayerNearby, 1040, 0x2)
		ADD_BOOL(bIsActive, 1040, 0x1)
		ADD_STRUCT(ScriptString*, LockerString, 1016)
		ADD_STRUCT(UTWeaponLocker::ReplacementWeaponEntry, ReplacementWeapons, 956)
		float BotDesireability(class Pawn* Bot, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.BotDesireability");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = Bot;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void SetInitialState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.SetInitialState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldCamp(class UTBot* B, float MaxWait)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ShouldCamp");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(float*)&params[4] = MaxWait;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AddCustomer(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.AddCustomer");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasCustomer(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.HasCustomer");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeWeapons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.InitializeWeapons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplaceWeapon(int Index, ScriptClass* NewWeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ReplaceWeapon");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptClass**)&params[4] = NewWeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.DetourWeight");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void InitializePickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.InitializePickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ShowActive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyLocalPlayerDead(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.NotifyLocalPlayerDead");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerNearby(class PlayerController* PC, bool bNewPlayerNearby, bool bPlayEffects)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.SetPlayerNearby");
			byte params[12] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(bool*)&params[4] = bNewPlayerNearby;
			*(bool*)&params[8] = bPlayEffects;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyWeapons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.DestroyWeapons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHidden()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ShowHidden");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
