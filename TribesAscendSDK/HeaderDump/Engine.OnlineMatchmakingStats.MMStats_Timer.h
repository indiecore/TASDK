#pragma once
#include "Core.Object.Double.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineMatchmakingStats.MMStats_Timer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineMatchmakingStats.MMStats_Timer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MMStats_Timer
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Double>, MSecs, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInProgress, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
