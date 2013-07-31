#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ApexDestructibleDamageParameters : public Object
	{
	public:
		enum EDamageParameterOverrideMode : byte
		{
			DPOM_Absolute = 0,
			DPOM_Multiplier = 1,
			DPOM_MAX = 2,
		};
		struct DamageParameters
		{
		public:
			ADD_STRUCT(float, Momentum, 12)
			ADD_STRUCT(float, Radius, 8)
			ADD_STRUCT(float, BaseDamage, 4)
			ADD_STRUCT(ApexDestructibleDamageParameters::EDamageParameterOverrideMode, OverrideMode, 0)
		};
		struct DamagePair
		{
		public:
			ADD_STRUCT(ApexDestructibleDamageParameters::DamageParameters, Params, 8)
			ADD_STRUCT(ScriptName, DamageCauserName, 0)
		};
		ADD_STRUCT(ScriptArray<ApexDestructibleDamageParameters::DamagePair>, DamageMap, 60)
	};
}
#undef ADD_STRUCT
