#pragma once
#include "GameFramework__SeqEvent_MobileBase.h"
#include "GameFramework__MobilePlayerInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileZoneBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileZoneBase : public SeqEvent_MobileBase
	{
	public:
		ADD_VAR(::StrProperty, TargetZoneName, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AddToMobileInput'
	};
}
#undef ADD_VAR
