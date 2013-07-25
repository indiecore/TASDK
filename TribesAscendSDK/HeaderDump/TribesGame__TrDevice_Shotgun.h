#pragma once
#include "TribesGame__TrDevice.h"
#include "Engine__AnimNodePlayCustomAnim.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_Shotgun." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_Shotgun." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Shotgun : public TrDevice
	{
	public:
		ADD_OBJECT(AnimNodePlayCustomAnim, ReloadCustomAnimNode)
		ADD_VAR(::IntProperty, m_nConsumeShotsFired, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nShotsFired, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInnerDefaultAccuracy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fConsumeAmmoTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nImpactCounter, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMinShotCount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'SetFlashLocation'
		// Here lies the not-yet-implemented method 'PerformInactiveReload'
		// Here lies the not-yet-implemented method 'CustomFire'
		// Here lies the not-yet-implemented method 'FireAmmunition'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'ConsumeAmmo'
		// Here lies the not-yet-implemented method 'ConsumeAmmo_Internal'
		// Here lies the not-yet-implemented method 'ProcessInstantHit_Internal'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
