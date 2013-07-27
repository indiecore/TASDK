#pragma once
#include "Engine.GameplayEventsHandler.h"
#include "Engine.GameplayEvents.h"
#include "Core.Object.h"
#include "GameFramework.GameStateObject.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameStatsAggregator : public GameplayEventsHandler
	{
	public:
		static const auto GAMEEVENT_AGGREGATED_DATA = 10000;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_TIMEALIVE = 10001;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_KILLS = 10002;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_DEATHS = 10003;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_MATCH_WON = 10004;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_ROUND_WON = 10005;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_NORMALKILL = 10006;
		static const auto GAMEEVENT_AGGREGATED_PLAYER_WASNORMALKILL = 10007;
		static const auto GAMEEVENT_AGGREGATED_TEAM_KILLS = 10100;
		static const auto GAMEEVENT_AGGREGATED_TEAM_DEATHS = 10101;
		static const auto GAMEEVENT_AGGREGATED_TEAM_GAME_SCORE = 10102;
		static const auto GAMEEVENT_AGGREGATED_TEAM_MATCH_WON = 10103;
		static const auto GAMEEVENT_AGGREGATED_TEAM_ROUND_WON = 10104;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_KILLS = 10200;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_DEATHS = 10201;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_DEALT_WEAPON_DAMAGE = 10202;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_DEALT_MELEE_DAMAGE = 10203;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_WEAPON_DAMAGE = 10204;
		static const auto GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_MELEE_DAMAGE = 10205;
		static const auto GAMEEVENT_AGGREGATED_WEAPON_FIRED = 10300;
		static const auto GAMEEVENT_AGGREGATED_PAWN_SPAWN = 10400;
		static const auto GAMEEVENT_AGGREGATED_GAME_SPECIFIC = 11000;
		struct AggregateEventMapping
		{
		public:
			ADD_STRUCT(int, TargetAggregateID, 8)
			ADD_STRUCT(int, AggregateID, 4)
			ADD_STRUCT(int, EventID, 0)
		};
		struct GameEvents
		{
		public:
			ADD_STRUCT(Object::Map_Mirror, Events, 0)
		};
		struct GameEvent
		{
		public:
			ADD_STRUCT(ScriptArray<float>, EventCountByTimePeriod, 0)
		};
		struct DamageEvents
		{
		public:
			ADD_STRUCT(ScriptArray<GameStatsAggregator::GameEvents>, EventsByDamageClass, 60)
			ADD_STRUCT(GameStatsAggregator::GameEvents, TotalEvents, 0)
		};
		struct PawnEvents
		{
		public:
			ADD_STRUCT(ScriptArray<GameStatsAggregator::GameEvents>, EventsByPawnClass, 60)
			ADD_STRUCT(GameStatsAggregator::GameEvents, TotalEvents, 0)
		};
		struct ProjectileEvents
		{
		public:
			ADD_STRUCT(ScriptArray<GameStatsAggregator::GameEvents>, EventsByProjectileClass, 60)
			ADD_STRUCT(GameStatsAggregator::GameEvents, TotalEvents, 0)
		};
		struct WeaponEvents
		{
		public:
			ADD_STRUCT(ScriptArray<GameStatsAggregator::GameEvents>, EventsByWeaponClass, 60)
			ADD_STRUCT(GameStatsAggregator::GameEvents, TotalEvents, 0)
		};
		struct TeamEvents
		{
		public:
			ADD_STRUCT(GameStatsAggregator::PawnEvents, PawnEvents, 348)
			ADD_STRUCT(GameStatsAggregator::ProjectileEvents, ProjectileEvents, 276)
			ADD_STRUCT(GameStatsAggregator::DamageEvents, DamageAsTargetEvents, 204)
			ADD_STRUCT(GameStatsAggregator::DamageEvents, DamageAsPlayerEvents, 132)
			ADD_STRUCT(GameStatsAggregator::WeaponEvents, WeaponEvents, 60)
			ADD_STRUCT(GameStatsAggregator::GameEvents, TotalEvents, 0)
		};
		struct PlayerEvents
		{
		public:
			ADD_STRUCT(GameStatsAggregator::PawnEvents, PawnEvents, 348)
			ADD_STRUCT(GameStatsAggregator::ProjectileEvents, ProjectileEvents, 276)
			ADD_STRUCT(GameStatsAggregator::DamageEvents, DamageAsTargetEvents, 204)
			ADD_STRUCT(GameStatsAggregator::DamageEvents, DamageAsPlayerEvents, 132)
			ADD_STRUCT(GameStatsAggregator::WeaponEvents, WeaponEvents, 60)
			ADD_STRUCT(GameStatsAggregator::GameEvents, TotalEvents, 0)
		};
		ADD_STRUCT(ScriptArray<GameStatsAggregator::AggregateEventMapping>, AggregatesList, 92)
		ADD_STRUCT(ScriptArray<GameplayEvents::GameplayEventMetaData>, AggregateEvents, 164)
		ADD_STRUCT(ScriptArray<GameStatsAggregator::TeamEvents>, AllTeamEvents, 236)
		ADD_STRUCT(ScriptArray<GameStatsAggregator::PlayerEvents>, AllPlayerEvents, 248)
		ADD_STRUCT(GameStatsAggregator::DamageEvents, AllDamageEvents, 476)
		ADD_STRUCT(GameStatsAggregator::PawnEvents, AllPawnEvents, 404)
		ADD_STRUCT(GameStatsAggregator::ProjectileEvents, AllProjectileEvents, 332)
		ADD_STRUCT(GameStatsAggregator::WeaponEvents, AllWeaponEvents, 260)
		ADD_STRUCT(GameStatsAggregator::GameEvents, AllGameEvents, 176)
		ADD_STRUCT(Object::Map_Mirror, AggregateEventsMapping, 104)
		ADD_OBJECT(GameStateObject, GameState, 88)
		void PreProcessStream()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostProcessStream()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32034);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetAggregateMappingIDs(int EventID, int& AggregateID, int& TargetAggregateID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32035);
			byte params[16] = { NULL };
			*(int*)params = EventID;
			*(int*)&params[4] = AggregateID;
			*(int*)&params[8] = TargetAggregateID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			AggregateID = *(int*)&params[4];
			TargetAggregateID = *(int*)&params[8];
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
