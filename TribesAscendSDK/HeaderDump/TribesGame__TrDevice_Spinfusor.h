#pragma once
#include "TribesGame__TrDevice.h"
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
	};
}
#undef ADD_OBJECT
