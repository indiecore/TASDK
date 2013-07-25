#pragma once
#include "Engine__GameplayEventsHandler.h"
#include "GameFramework__GameStateObject.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameStatsAggregator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameStatsAggregator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameStatsAggregator : public GameplayEventsHandler
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameStatsAggregator.DamageEvents' for the property named 'AllDamageEvents'!
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameStatsAggregator.PawnEvents' for the property named 'AllPawnEvents'!
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameStatsAggregator.ProjectileEvents' for the property named 'AllProjectileEvents'!
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameStatsAggregator.WeaponEvents' for the property named 'AllWeaponEvents'!
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameStatsAggregator.GameEvents' for the property named 'AllGameEvents'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'AggregateEventsMapping'!
		ADD_OBJECT(GameStateObject, GameState)
		// Here lies the not-yet-implemented method 'PreProcessStream'
		// Here lies the not-yet-implemented method 'PostProcessStream'
		// Here lies the not-yet-implemented method 'GetAggregateMappingIDs'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
