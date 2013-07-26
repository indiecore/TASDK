#pragma once
#include "GameFramework.GameStatsAggregator.GameEvents.h"
#include "GameFramework.GameStatsAggregator.PawnEvents.h"
#include "GameFramework.GameStatsAggregator.ProjectileEvents.h"
#include "GameFramework.GameStatsAggregator.DamageEvents.h"
#include "GameFramework.GameStatsAggregator.WeaponEvents.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameStatsAggregator.PlayerEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerEvents
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<PawnEvents>, PawnEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ProjectileEvents>, ProjectileEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<DamageEvents>, DamageAsTargetEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<DamageEvents>, DamageAsPlayerEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<WeaponEvents>, WeaponEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<GameEvents>, TotalEvents, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
