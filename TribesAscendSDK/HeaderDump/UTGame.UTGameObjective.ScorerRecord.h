#pragma once
#include "UTGame.UTPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGameObjective.ScorerRecord." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGameObjective.ScorerRecord." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ScorerRecord
	{
	public:
		ADD_VAR(::FloatProperty, Pct, 0xFFFFFFFF)
		ADD_OBJECT(UTPlayerReplicationInfo, PRI)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
