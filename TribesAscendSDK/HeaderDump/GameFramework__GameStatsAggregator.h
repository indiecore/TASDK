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
