#pragma once
#include "TribesGame__TrDevice.h"
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
	};
}
#undef ADD_OBJECT
