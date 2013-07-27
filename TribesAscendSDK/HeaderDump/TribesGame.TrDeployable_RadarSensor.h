#pragma once
#include "TribesGame.TrDeployable_Sensor.h"
#include "TribesGame.TrHelpTextManager.h"
#include "Engine.Texture2D.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_RadarSensor : public TrDeployable_Sensor
	{
	public:
		ADD_STRUCT(float, m_fBlipIntervalTime, 1540)
		void ApplyServerSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80306);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReceivesPowerFromGenerator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80308);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SpawnHelpTextCollisionProxy(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80310);
			byte params[1] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldShowHelpText(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80313);
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80323);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
		void SetPowered(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80335);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RadarBlip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80337);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsDeployed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80339);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void GiveDestroyAccolade(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80341);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReleaseOutOfSightEnemies()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80343);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80344);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AwardUpgradeAssists()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80355);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
