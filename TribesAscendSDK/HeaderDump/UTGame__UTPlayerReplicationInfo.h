#pragma once
#include "UTGame__UTPawn.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Texture.h"
#include "Engine__Actor.h"
#include "UTGame__UTSquadAI.h"
#include "UTGame__UTCarriedObject.h"
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
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DefaultHudColor'!
		ADD_OBJECT(UTCarriedObject, HasFlag)
		// Here lies the not-yet-implemented method 'IncrementEventStat'
		// Here lies the not-yet-implemented method 'GetFlag'
		// Here lies the not-yet-implemented method 'IncrementPickupStat'
		// Here lies the not-yet-implemented method 'IncrementVehicleKillStat'
		// Here lies the not-yet-implemented method 'IncrementSuicideStat'
		// Here lies the not-yet-implemented method 'IncrementKillStat'
		// Here lies the not-yet-implemented method 'IncrementDeathStat'
		// Here lies the not-yet-implemented method 'GetCallSign'
		// Here lies the not-yet-implemented method 'IsLocalPlayerPRI'
		// Here lies the not-yet-implemented method 'ShouldBroadCastWelcomeMessage'
		// Here lies the not-yet-implemented method 'StartDrivingStat'
		// Here lies the not-yet-implemented method 'StopDrivingStat'
		// Here lies the not-yet-implemented method 'StartPowerupTimeStat'
		// Here lies the not-yet-implemented method 'StopPowerupTimeStat'
		// Here lies the not-yet-implemented method 'SetFlag'
		// Here lies the not-yet-implemented method 'IncrementKills'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'OverrideWith'
		// Here lies the not-yet-implemented method 'CopyProperties'
		// Here lies the not-yet-implemented method 'SeamlessTravelTo'
		// Here lies the not-yet-implemented method 'AllowClientToTeleport'
		// Here lies the not-yet-implemented method 'ServerTeleportToActor'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ShowMidGameMenu'
		// Here lies the not-yet-implemented method 'AttemptMidGameMenu'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
