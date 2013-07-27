#pragma once
#include "TribesGame.TrDeviceAttachment.h"
#include "TribesGame.TrSkelControl_SpinControl.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrAttachment_ChainGun_MKD : public TrDeviceAttachment
	{
	public:
		ADD_OBJECT(TrSkelControl_SpinControl, m_BarrelSpinControl, 796)
		ADD_STRUCT(float, m_fLastFireTime, 792)
		ADD_STRUCT(float, m_fCurrSpinTime, 788)
		ADD_BOOL(m_bSpinningUp, 784, 0x2)
		ADD_BOOL(m_bIsFiring, 784, 0x1)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_ChainGun_MKD.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThirdPersonFireEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_ChainGun_MKD.ThirdPersonFireEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
