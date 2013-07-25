#pragma once
#include "Engine__SkelControlSingleBone.h"
#include "TribesGame__TrDevice.h"
#include "TribesGame__TrSkelControl_SpinControl.h"
#include "Engine__SoundCue.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_Spinfusor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Spinfusor : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_SpinfusorIdleSound)
		ADD_OBJECT(SkelControlSingleBone, m_DiscVisibilityControl)
		ADD_OBJECT(TrSkelControl_SpinControl, m_DiscSpinControl)
		// Here lies the not-yet-implemented method 'UpdateReplicatedCarriedAmmo'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'OnAnimPlay'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'PlayFireEffects'
		// Here lies the not-yet-implemented method 'PlayWeaponEquip'
		// Here lies the not-yet-implemented method 'SetDiscVisibility'
		// Here lies the not-yet-implemented method 'SetDiscSpinning'
		// Here lies the not-yet-implemented method 'PlayWeaponPutDown'
		// Here lies the not-yet-implemented method 'PutDownFast'
		// Here lies the not-yet-implemented method 'OnSwitchAwayFromWeapon'
	};
}
#undef ADD_OBJECT
