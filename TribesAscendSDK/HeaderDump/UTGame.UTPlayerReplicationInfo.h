#pragma once
#include "UTGame.UTPawn.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Texture.h"
#include "Engine.Actor.h"
#include "UTGame.UTSquadAI.h"
#include "UTGame.UTCarriedObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTPlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPlayerReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPlayerReplicationInfo : public PlayerReplicationInfo
	{
	public:
		ADD_OBJECT(ScriptClass, CharClassInfo)
		ADD_VAR(::BoolProperty, bHasFlag, 0x1)
		ADD_OBJECT(ScriptClass, VoiceClass)
		ADD_VAR(::BoolProperty, bIsFemale, 0x4)
		ADD_OBJECT(Texture, CharPortrait)
		ADD_OBJECT(UTPlayerReplicationInfo, LastKillerPRI)
		ADD_VAR(::IntProperty, spree, 0xFFFFFFFF)
		ADD_OBJECT(UTSquadAI, Squad)
		ADD_VAR(::BoolProperty, bHolding, 0x2)
		ADD_VAR(::IntProperty, MultiKillLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastKillTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OrdersIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OrdersString, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DefaultHudColor'!
		ADD_OBJECT(UTCarriedObject, HasFlag)
		int IncrementEventStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IncrementEventStat");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.GetFlag");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTCarriedObject**)params;
			free(params);
			return returnVal;
		}
		int IncrementPickupStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IncrementPickupStat");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int IncrementVehicleKillStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IncrementVehicleKillStat");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int IncrementSuicideStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IncrementSuicideStat");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int IncrementKillStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IncrementKillStat");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int IncrementDeathStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IncrementDeathStat");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetCallSign()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.GetCallSign");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool IsLocalPlayerPRI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IsLocalPlayerPRI");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldBroadCastWelcomeMessage(bool bExiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.ShouldBroadCastWelcomeMessage");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bExiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StartDrivingStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.StartDrivingStat");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopDrivingStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.StopDrivingStat");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartPowerupTimeStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.StartPowerupTimeStat");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopPowerupTimeStat(ScriptName NewStatName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.StopPowerupTimeStat");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewStatName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlag(class UTCarriedObject* NewFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.SetFlag");
			byte* params = (byte*)malloc(4);
			*(class UTCarriedObject**)params = NewFlag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementKills(bool bEnemyKill)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.IncrementKills");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnemyKill;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OverrideWith(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.OverrideWith");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CopyProperties(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.CopyProperties");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeamlessTravelTo(class PlayerReplicationInfo* NewPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.SeamlessTravelTo");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = NewPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowClientToTeleport(class Actor* DestinationActor, class UTPawn*& OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.AllowClientToTeleport");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = DestinationActor;
			*(class UTPawn**)(params + 4) = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OwnerPawn = *(class UTPawn**)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void ServerTeleportToActor(class Actor* DestinationActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.ServerTeleportToActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowMidGameMenu(bool bInitial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.ShowMidGameMenu");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInitial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AttemptMidGameMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerReplicationInfo.AttemptMidGameMenu");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
