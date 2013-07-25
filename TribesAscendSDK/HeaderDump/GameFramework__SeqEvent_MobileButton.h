#pragma once
#include "GameFramework__SeqEvent_MobileZoneBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileButton." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileButton : public SeqEvent_MobileZoneBase
	{
	public:
		ADD_VAR(::BoolProperty, bSendPressedOnlyOnTouchUp, 0x4)
		ADD_VAR(::BoolProperty, bSendPressedOnlyOnTouchDown, 0x2)
		ADD_VAR(::BoolProperty, bWasActiveLastFrame, 0x1)
	};
}
#undef ADD_VAR
