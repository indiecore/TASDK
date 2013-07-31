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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86337);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSkelControlKnives(bool bForceFullAmmo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86339);
			byte params[4] = { NULL };
			*(bool*)params = bForceFullAmmo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFireSkelControlKnivesAnimNotify()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86341);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSkelControlKnivesAnimNotify()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86342);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86343);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86344);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86347);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86348);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
