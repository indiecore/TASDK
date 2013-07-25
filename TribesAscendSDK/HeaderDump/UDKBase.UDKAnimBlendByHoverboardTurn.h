#pragma once
#include "Engine.AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByHoverboardTurn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByHoverboardTurn : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::FloatProperty, CurrentAnimWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxBlendPerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
