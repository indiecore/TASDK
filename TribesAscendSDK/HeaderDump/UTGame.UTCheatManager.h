#pragma once
#include "Engine.CheatManager.h"
#include "Engine.SpeechRecognition.h"
#include "Core.Object.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTCheatManager : public CheatManager
	{
	public:
		ADD_OBJECT(SpeechRecognition, RecogObject, 96)
		ADD_OBJECT(ScriptClass, LMC, 92)
		void ViewFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.ViewFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Glow(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.Glow");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LM(ScriptString* MessageClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.LM");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = MessageClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LMS(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.LMS");
			byte params[4] = { NULL };
			*(int*)&params[0] = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SummonV(ScriptString* ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.SummonV");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AllWeapons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.AllWeapons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoubleUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.DoubleUp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChainGun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.ChainGun");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.AllAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Invisible(bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.Invisible");
			byte params[4] = { NULL };
			*(bool*)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FreeCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.FreeCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewBot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.ViewBot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillBadGuys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.KillBadGuys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RBGrav(float NewGravityScaling)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.RBGrav");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewGravityScaling;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SuicideBy(ScriptString* Type, int DeathHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.SuicideBy");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Type;
			*(int*)&params[12] = DeathHealth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EditWeapon(ScriptString* WhichWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.EditWeapon");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = WhichWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillOtherBots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.KillOtherBots");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnABloodDecal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.SpawnABloodDecal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveADecal(Object::Vector HitLoc, Object::Vector HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.LeaveADecal");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLoc;
			*(Object::Vector*)&params[12] = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TiltIt(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.TiltIt");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowStickBindings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.ShowStickBindings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStickBind(float val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.SetStickBind");
			byte params[4] = { NULL };
			*(float*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAll(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.KillAll");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAllPawns(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.KillAllPawns");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
