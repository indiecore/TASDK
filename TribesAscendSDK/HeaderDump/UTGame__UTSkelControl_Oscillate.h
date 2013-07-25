#pragma once
#include "Engine__SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSkelControl_Oscillate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTSkelControl_Oscillate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSkelControl_Oscillate : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::BoolProperty, bReverseDirection, 0x1)
		ADD_VAR(::FloatProperty, CurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Period, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MaxDelta, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'TickSkelControl'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
