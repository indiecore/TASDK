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
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'UpdateSkelControlKnives'
		// Here lies the not-yet-implemented method 'OnFireSkelControlKnivesAnimNotify'
		// Here lies the not-yet-implemented method 'OnSkelControlKnivesAnimNotify'
		// Here lies the not-yet-implemented method 'PlayWeaponEquip'
		// Here lies the not-yet-implemented method 'ProjectileFire'
		// Here lies the not-yet-implemented method 'FireAmmunition'
		// Here lies the not-yet-implemented method 'StartFire'
	};
}
#undef ADD_OBJECT
