#pragma once
#include "Engine__SkelControlSingleBone.h"
#include "TribesGame__TrDevice.h"
#include "Engine__Projectile.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_ThrowingKnives." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_ThrowingKnives : public TrDevice
	{
	public:
		ADD_OBJECT(SkelControlSingleBone, m_KnifeVisibilityBottomControl)
		ADD_OBJECT(SkelControlSingleBone, m_KnifeVisibilityTopControl)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSkelControlKnives(bool bForceFullAmmo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.UpdateSkelControlKnives");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForceFullAmmo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ThrowingKnives.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
