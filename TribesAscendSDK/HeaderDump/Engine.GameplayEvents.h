#pragma once
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameplayEvents : public Object
	{
	public:
		static const auto HeaderFlags_NoEventStrings = 1;
		enum EGameStatGroups : byte
		{
			GSG_EngineStats = 0,
			GSG_Game = 1,
			GSG_Team = 2,
			GSG_Player = 3,
			GSG_Weapon = 4,
			GSG_Damage = 5,
			GSG_Projectile = 6,
			GSG_Pawn = 7,
			GSG_GameSpecific = 8,
			GSG_Aggregate = 9,
			GSG_MAX = 10,
		};
		class PlayerInformationNew
		{
		public:
			ADD_BOOL(bIsBot, 32, 0x1)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, UniqueId, 24)
			ADD_STRUCT(ScriptString*, PlayerName, 12)
			ADD_STRUCT(ScriptString*, ControllerName, 0)
		};
		class TeamInformation
		{
		public:
			ADD_STRUCT(int, MaxSize, 20)
			ADD_STRUCT(Object::Color, TeamColor, 16)
			ADD_STRUCT(ScriptString*, TeamName, 4)
			ADD_STRUCT(int, TeamIndex, 0)
		};
		class WeaponClassEventData
		{
		public:
			ADD_STRUCT(ScriptString*, WeaponClassName, 0)
		};
		class DamageClassEventData
		{
		public:
			ADD_STRUCT(ScriptString*, DamageClassName, 0)
		};
		class ProjectileClassEventData
		{
		public:
			ADD_STRUCT(ScriptString*, ProjectileClassName, 0)
		};
		class PawnClassEventData
		{
		public:
			ADD_STRUCT(ScriptString*, PawnClassName, 0)
		};
		class GameplayEventsHeader
		{
		public:
			ADD_STRUCT(int, Flags, 40)
			ADD_STRUCT(ScriptString*, FilterClass, 28)
			ADD_STRUCT(int, FileSize, 24)
			ADD_STRUCT(int, TotalStreamSize, 20)
			ADD_STRUCT(int, FooterOffset, 16)
			ADD_STRUCT(int, AggregateOffset, 12)
			ADD_STRUCT(int, StreamOffset, 8)
			ADD_STRUCT(int, StatsWriterVersion, 4)
			ADD_STRUCT(int, EngineVersion, 0)
		};
		class GameSessionInformation
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, OwningNetId, 100)
			ADD_STRUCT(int, GameTypeId, 96)
			ADD_STRUCT(int, SessionInstance, 92)
			ADD_STRUCT(ScriptString*, MapURL, 80)
			ADD_STRUCT(ScriptString*, MapName, 68)
			ADD_STRUCT(ScriptString*, GameClassName, 56)
			ADD_STRUCT(ScriptString*, GameplaySessionID, 44)
			ADD_BOOL(bGameplaySessionInProgress, 40, 0x1)
			ADD_STRUCT(float, GameplaySessionEndTime, 36)
			ADD_STRUCT(float, GameplaySessionStartTime, 32)
			ADD_STRUCT(ScriptString*, GameplaySessionTimestamp, 20)
			ADD_STRUCT(ScriptString*, Language, 8)
			ADD_STRUCT(int, PlatformType, 4)
			ADD_STRUCT(int, AppTitleID, 0)
		};
		class GameStatGroup
		{
		public:
			ADD_STRUCT(int, Level, 4)
			ADD_STRUCT(GameplayEvents::EGameStatGroups, Group, 0)
		};
		class GameplayEventMetaData
		{
		public:
			ADD_STRUCT(int, EventDataType, 20)
			ADD_STRUCT(GameplayEvents::GameStatGroup, StatGroup, 12)
			ADD_STRUCT(ScriptName, EventName, 4)
			ADD_STRUCT(int, EventID, 0)
		};
		ADD_STRUCT(ScriptArray<GameplayEvents::PlayerInformationNew>, PlayerList, 228)
		ADD_STRUCT(ScriptArray<GameplayEvents::TeamInformation>, TeamList, 240)
		ADD_STRUCT(ScriptArray<GameplayEvents::GameplayEventMetaData>, SupportedEvents, 252)
		ADD_STRUCT(ScriptArray<GameplayEvents::WeaponClassEventData>, WeaponClassArray, 264)
		ADD_STRUCT(ScriptArray<GameplayEvents::DamageClassEventData>, DamageClassArray, 276)
		ADD_STRUCT(ScriptArray<GameplayEvents::ProjectileClassEventData>, ProjectileClassArray, 288)
		ADD_STRUCT(ScriptArray<GameplayEvents::PawnClassEventData>, PawnClassArray, 300)
		ADD_STRUCT(ScriptArray<ScriptString*>, ActorArray, 312)
		ADD_STRUCT(ScriptArray<ScriptString*>, SoundCueArray, 324)
		ADD_STRUCT(GameplayEvents::GameSessionInformation, CurrentSessionInfo, 120)
		ADD_STRUCT(GameplayEvents::GameplayEventsHeader, Header, 76)
		ADD_STRUCT(ScriptString*, StatsFileName, 64)
		ADD_STRUCT(Object::Pointer, Archive, 60)
		bool OpenStatsFile(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEvents.OpenStatsFile");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEvents.CloseStatsFile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetFilename()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEvents.GetFilename");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
