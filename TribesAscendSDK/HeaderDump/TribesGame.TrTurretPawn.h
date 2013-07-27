#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Weapon.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrDeployable.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Canvas.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrTurretPawn : public TrPawn
	{
	public:
		ADD_OBJECT(TrDeployable, m_OwnerDeployable, 3192)
		Object::Vector LeadingAimLocation(class Actor* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.LeadingAimLocation");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		Object::Vector GetValidAimTarget(Object::Vector PawnLocation, Object::Vector PawnTargetLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.GetValidAimTarget");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = PawnLocation;
			*(Object::Vector*)&params[12] = PawnTargetLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.WeaponFired");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetAimVectorFor(class Weapon* InWeapon, Object::Vector projStart, class Actor* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.GetAimVectorFor");
			byte params[32] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(Object::Vector*)&params[4] = projStart;
			*(class Actor**)&params[16] = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[20];
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* InWeapon, Object::Vector projStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(Object::Vector*)&params[4] = projStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		Object::Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.GetWeaponStartTraceLocation");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeRadiusDamage(class Controller* EventInstigator, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.TakeRadiusDamage");
			byte params[44] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.RefreshPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshInventory(bool bIsRespawn, bool bCallin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.RefreshInventory");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bIsRespawn;
			*(bool*)&params[4] = bCallin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCharacterClassFromInfo(ScriptClass* Info, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.SetCharacterClassFromInfo");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = Info;
			*(bool*)&params[4] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFlashCount(class Weapon* W, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTurretPawn.IncrementFlashCount");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = W;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
