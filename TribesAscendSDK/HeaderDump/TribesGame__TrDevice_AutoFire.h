#pragma once
#include "TribesGame__TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_AutoFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_AutoFire." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_AutoFire : public TrDevice
	{
	public:
		ADD_VAR(::BoolProperty, m_bPullPinFire, 0x1)
		ADD_VAR(::FloatProperty, m_fPullPinTime, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_PostFireDevice)
		ADD_VAR(::FloatProperty, m_fBuildupTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
