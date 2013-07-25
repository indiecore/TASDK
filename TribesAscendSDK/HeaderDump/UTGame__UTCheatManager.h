#pragma once
#include "Engine__CheatManager.h"
#include "Engine__SpeechRecognition.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCheatManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCheatManager : public CheatManager
	{
	public:
		ADD_OBJECT(SpeechRecognition, RecogObject)
		ADD_OBJECT(ScriptClass, LMC)
		void ViewFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.ViewFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Glow(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.Glow");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LM(ScriptArray<wchar_t> MessageClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.LM");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = MessageClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LMS(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.LMS");
			byte* params = (byte*)malloc(4);
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SummonV(ScriptArray<wchar_t> ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.SummonV");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = NewGravityScaling;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SuicideBy(ScriptArray<wchar_t> Type, int DeathHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.SuicideBy");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Type;
			*(int*)(params + 12) = DeathHealth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EditWeapon(ScriptArray<wchar_t> WhichWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.EditWeapon");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = WhichWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void LeaveADecal(Vector HitLoc, Vector HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.LeaveADecal");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLoc;
			*(Vector*)(params + 12) = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TiltIt(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.TiltIt");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowStickBindings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.ShowStickBindings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStickBind(float val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.SetStickBind");
			byte* params = (byte*)malloc(4);
			*(float*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KillAll(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.KillAll");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KillAllPawns(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCheatManager.KillAllPawns");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
