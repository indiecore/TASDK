#pragma once
#include "Engine.AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeSynch.SynchGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AnimNodeSynch.SynchGroup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SynchGroup
	{
	public:
		ADD_VAR(::FloatProperty, RateScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFireSlaveNotifies, 0x1)
		ADD_VAR(::NameProperty, GroupName, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeSequence, MasterNode)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
