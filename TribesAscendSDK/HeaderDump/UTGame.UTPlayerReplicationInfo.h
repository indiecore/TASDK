#pragma once
#include "UTGame.UTPawn.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Texture.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "UTGame.UTSquadAI.h"
#include "UTGame.UTCarriedObject.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTPlayerReplicationInfo : public PlayerReplicationInfo
	{
	public:
		struct IntStat
		{
		public:
			ADD_STRUCT(int, StatValue, 8)
			ADD_STRUCT(ScriptName, StatName, 0)
		};
		struct TimeStat
		{
		public:
			ADD_STRUCT(float, CurrentStart, 12)
			ADD_STRUCT(float, TotalTime, 8)
			ADD_STRUCT(ScriptName, StatName, 0)
		};
		ADD_OBJECT(ScriptClass, CharClassInfo, 700)
		ADD_BOOL(bHasFlag, 652, 0x1)
		ADD_OBJECT(ScriptClass, VoiceClass, 676)
		ADD_BOOL(bIsFemale, 652, 0x4)
		ADD_OBJECT(Texture, CharPortrait, 704)
		ADD_OBJECT(UTPlayerReplicationInfo, LastKillerPRI, 680)
		ADD_STRUCT(int, spree, 656)
		ADD_OBJECT(UTSquadAI, Squad, 668)
		ADD_BOOL(bHolding, 652, 0x2)
		ADD_STRUCT(int, MultiKillLevel, 660)
		ADD_STRUCT(float, LastKillTime, 664)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::IntStat>, KillStats, 708)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::IntStat>, DeathStats, 720)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::IntStat>, SuicideStats, 732)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::IntStat>, EventStats, 744)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::IntStat>, VehicleKillStats, 756)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::IntStat>, PickupStats, 768)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::TimeStat>, DrivingStats, 780)
		ADD_STRUCT(ScriptArray<UTPlayerReplicationInfo::TimeStat>, PowerupTimeStats, 792)
		ADD_STRUCT(byte, OrdersIndex, 900)
		ADD_STRUCT(ScriptString*, OrdersString, 804)
		ADD_STRUCT(Vector, HUDLocation, 688)
		ADD_STRUCT(Object::Color, DefaultHudColor, 684)
		ADD_OBJECT(UTCarriedObject, HasFlag, 672)
		int IncrementEventStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37033);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39727);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTCarriedObject**)params;
		}
		int IncrementPickupStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40625);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int IncrementVehicleKillStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44685);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int IncrementSuicideStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44688);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int IncrementKillStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44690);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int IncrementDeathStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44692);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptString* GetCallSign()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45337);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool IsLocalPlayerPRI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48782);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldBroadCastWelcomeMessage(bool bExiting)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48786);
			byte params[8] = { NULL };
			*(bool*)params = bExiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StartDrivingStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48805);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopDrivingStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48810);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartPowerupTimeStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48822);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopPowerupTimeStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48827);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlag(class UTCarriedObject* NewFlag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48831);
			byte params[4] = { NULL };
			*(class UTCarriedObject**)params = NewFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementKills(bool bEnemyKill)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48833);
			byte params[4] = { NULL };
			*(bool*)params = bEnemyKill;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48835);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OverrideWith(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48836);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CopyProperties(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48839);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeamlessTravelTo(class PlayerReplicationInfo* NewPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48842);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = NewPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowClientToTeleport(class Actor* DestinationActor, class UTPawn*& OwnerPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48845);
			byte params[12] = { NULL };
			*(class Actor**)params = DestinationActor;
			*(class UTPawn**)&params[4] = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OwnerPawn = *(class UTPawn**)&params[4];
			return *(bool*)&params[8];
		}
		void ServerTeleportToActor(class Actor* DestinationActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48850);
			byte params[4] = { NULL };
			*(class Actor**)params = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48853);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowMidGameMenu(bool bInitial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48856);
			byte params[4] = { NULL };
			*(bool*)params = bInitial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AttemptMidGameMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48858);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
