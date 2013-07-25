#pragma once
#include "TribesGame__TrDeviceAttachment.h"
#include "TribesGame__TrSkelControl_SpinControl.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAttachment_ChainGun_MKD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAttachment_ChainGun_MKD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAttachment_ChainGun_MKD : public TrDeviceAttachment
	{
	public:
		ADD_OBJECT(TrSkelControl_SpinControl, m_BarrelSpinControl)
		ADD_VAR(::FloatProperty, m_fLastFireTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrSpinTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bSpinningUp, 0x2)
		ADD_VAR(::BoolProperty, m_bIsFiring, 0x1)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_ChainGun_MKD.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ThirdPersonFireEffects(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_ChainGun_MKD.ThirdPersonFireEffects");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
