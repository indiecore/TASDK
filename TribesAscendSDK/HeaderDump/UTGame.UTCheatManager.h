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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43897);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Glow(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43899);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LM(ScriptString* MessageClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43902);
			byte params[12] = { NULL };
			*(ScriptString**)params = MessageClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LMS(int Switch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43904);
			byte params[4] = { NULL };
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SummonV(ScriptString* ClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43906);
			byte params[12] = { NULL };
			*(ScriptString**)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AllWeapons()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43910);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoubleUp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43911);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChainGun()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43912);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43913);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Invisible(bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43914);
			byte params[4] = { NULL };
			*(bool*)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FreeCamera()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43916);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewBot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43917);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillBadGuys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43921);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RBGrav(float NewGravityScaling)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43924);
			byte params[4] = { NULL };
			*(float*)params = NewGravityScaling;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SuicideBy(ScriptString* Type, int DeathHealth)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43926);
			byte params[16] = { NULL };
			*(ScriptString**)params = Type;
			*(int*)&params[12] = DeathHealth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EditWeapon(ScriptString* WhichWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43930);
			byte params[12] = { NULL };
			*(ScriptString**)params = WhichWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillOtherBots()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43937);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnABloodDecal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43939);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveADecal(Vector HitLoc, Vector HitNorm)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43940);
			byte params[24] = { NULL };
			*(Vector*)params = HitLoc;
			*(Vector*)&params[12] = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TiltIt(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43943);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowStickBindings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43945);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStickBind(float val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43947);
			byte params[4] = { NULL };
			*(float*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAll(ScriptClass* aClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43951);
			byte params[4] = { NULL };
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAllPawns(ScriptClass* aClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43955);
			byte params[4] = { NULL };
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
