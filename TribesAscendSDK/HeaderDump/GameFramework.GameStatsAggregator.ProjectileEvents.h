#pragma once
#include "GameFramework.GameStatsAggregator.GameEvents.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameStatsAggregator.ProjectileEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ProjectileEvents
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<GameEvents>, TotalEvents, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
