#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.Projectile.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_ThrowingKnives : public TrDevice
	{
	public:
		ADD_OBJECT(SkelControlSingleBone, m_KnifeVisibilityBottomControl, 2152)
		ADD_OBJECT(SkelControlSingleBone, m_KnifeVisibilityTopControl, 2148)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSkelControlKnives(bool bForceFullAmmo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.UpdateSkelControlKnives");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForceFullAmmo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFireSkelControlKnivesAnimNotify()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.OnFireSkelControlKnivesAnimNotify");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSkelControlKnivesAnimNotify()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.OnSkelControlKnivesAnimNotify");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.ProjectileFire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)&params[0];
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
