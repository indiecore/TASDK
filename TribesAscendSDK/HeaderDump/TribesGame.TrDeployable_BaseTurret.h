#pragma once
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrDeployable_Turret.h"
#include "TribesGame.TrHelpTextManager.h"
#include "Engine.Texture2D.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
namespace UnrealScript
{
	class TrDeployable_BaseTurret : public TrDeployable_Turret
	{
	public:
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReceivesPowerFromGenerator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.ReceivesPowerFromGenerator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ShouldShowHelpText(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.ShouldShowHelpText");
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SpawnHelpTextCollisionProxy(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.SpawnHelpTextCollisionProxy");
			byte params[1] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
		void GiveDestroyAccolade(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.GiveDestroyAccolade");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RequiresLOSForRepairDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BaseTurret.RequiresLOSForRepairDeployable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
