#pragma once
#include "GameFramework__SeqEvent_MobileBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileMotion." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileMotion : public SeqEvent_MobileBase
	{
	public:
		ADD_VAR(::FloatProperty, DeltaYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeltaPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeltaRoll, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Yaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Pitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Roll, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
