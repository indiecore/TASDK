#pragma once
#include "GameFramework.GameStatsAggregator.GameEvents.h"
#include "GameFramework.GameStatsAggregator.PawnEvents.h"
#include "Engine.GameplayEventsHandler.h"
#include "GameFramework.GameStatsAggregator.DamageEvents.h"
#include "GameFramework.GameStatsAggregator.ProjectileEvents.h"
#include "GameFramework.GameStatsAggregator.WeaponEvents.h"
#include "Core.Object.Map_Mirror.h"
#include "GameFramework.GameStateObject.h"
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
		ADD_STRUCT(::NonArithmeticProperty<DamageEvents>, AllDamageEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PawnEvents>, AllPawnEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ProjectileEvents>, AllProjectileEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<WeaponEvents>, AllWeaponEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<GameEvents>, AllGameEvents, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Map_Mirror>, AggregateEventsMapping, 0xFFFFFFFF)
		ADD_OBJECT(GameStateObject, GameState)
		void PreProcessStream()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameStatsAggregator.PreProcessStream");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostProcessStream()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameStatsAggregator.PostProcessStream");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetAggregateMappingIDs(int EventID, int& AggregateID, int& TargetAggregateID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameStatsAggregator.GetAggregateMappingIDs");
			byte* params = (byte*)malloc(16);
			*(int*)params = EventID;
			*(int*)(params + 4) = AggregateID;
			*(int*)(params + 8) = TargetAggregateID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			AggregateID = *(int*)(params + 4);
			TargetAggregateID = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
