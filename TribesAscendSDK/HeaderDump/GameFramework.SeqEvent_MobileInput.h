#pragma once
#include "GameFramework.SeqEvent_MobileZoneBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileInput : public SeqEvent_MobileZoneBase
	{
	public:
		ADD_VAR(::FloatProperty, CurrentY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CenterY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CenterX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, YAxisValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XAxisValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
