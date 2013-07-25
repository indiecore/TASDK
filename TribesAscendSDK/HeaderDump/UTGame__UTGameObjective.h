#pragma once
#include "UTGame__UTPlayerController.h"
#include "Engine__Actor.h"
#include "UTGame__UTSquadAI.h"
#include "UDKBase__UDKGameObjective.h"
#include "UTGame__UTDefensePoint.h"
#include "Engine__Material.h"
#include "Engine__Pawn.h"
#include "Engine__Volume.h"
#include "UTGame__UTMapInfo.h"
#include "UTGame__UTCarriedObject.h"
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#include "UTGame__UTBot.h"
#include "Engine__SoundNodeWave.h"
#include "UTGame__UTTeamStaticMesh.h"
#include "Engine__AIController.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "UTGame__UTPawn.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGameObjective." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGameObjective : public UDKGameObjective
	{
	public:
		ADD_VAR(::BoolProperty, bAllowRemoteUse, 0x2)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'AttackLinearColor'!
		ADD_VAR(::FloatProperty, MaxBeaconDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHighlightUpdate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinimapIconScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxHighlightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightScale, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo' for the property named 'DefendAnnouncement'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo' for the property named 'AttackAnnouncement'!
		ADD_VAR(::FloatProperty, CameraViewDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSensorRange, 0xFFFFFFFF)
		ADD_OBJECT(Material, HudMaterial)
		ADD_VAR(::FloatProperty, IconExtentY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconExtentX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconPosY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconPosX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'AttackCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'ControlColor'!
		ADD_OBJECT(UTGameObjective, NextObjective)
		ADD_VAR(::IntProperty, Score, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseRadius, 0xFFFFFFFF)
		ADD_OBJECT(Volume, MyBaseVolume)
		ADD_VAR(::StrProperty, ObjectiveName, 0xFFFFFFFF)
		ADD_OBJECT(UTDefensePoint, DefensePoints)
		ADD_OBJECT(UTSquadAI, DefenseSquad)
		ADD_VAR(::ByteProperty, DefensePriority, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, StartTeam, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bScriptRenderAdditionalMinimap, 0x200)
		ADD_VAR(::BoolProperty, bHasLocationSpeech, 0x100)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x80)
		ADD_VAR(::BoolProperty, bIsActive, 0x40)
		ADD_VAR(::BoolProperty, bIsDisabled, 0x20)
		ADD_VAR(::BoolProperty, bIsConstructing, 0x10)
		ADD_VAR(::BoolProperty, bHasSensor, 0x8)
		ADD_VAR(::BoolProperty, bFirstObjective, 0x4)
		ADD_VAR(::BoolProperty, bAlreadyRendered, 0x1)
		// Here lies the not-yet-implemented method 'UsedBy'
		// Here lies the not-yet-implemented method 'GetAutoObjectiveActor'
		// Here lies the not-yet-implemented method 'GetFlag'
		// Here lies the not-yet-implemented method 'Shootable'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'IsStandalone'
		// Here lies the not-yet-implemented method 'GetHUDOffset'
		// Here lies the not-yet-implemented method 'GetLocationMessageIndex'
		// Here lies the not-yet-implemented method 'GetLocationSpeechFor'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'AddTeamStaticMesh'
		// Here lies the not-yet-implemented method 'UpdateTeamStaticMeshes'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'FindNearestFriendlyNode'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'HighlightOnMinimap'
		// Here lies the not-yet-implemented method 'RenderMinimap'
		// Here lies the not-yet-implemented method 'RenderExtraDetails'
		// Here lies the not-yet-implemented method 'DrawMapSelection'
		// Here lies the not-yet-implemented method 'IsCritical'
		// Here lies the not-yet-implemented method 'IsNeutral'
		// Here lies the not-yet-implemented method 'IsActive'
		// Here lies the not-yet-implemented method 'TellBotHowToHeal'
		// Here lies the not-yet-implemented method 'TeamLink'
		// Here lies the not-yet-implemented method 'NeedsHealing'
		// Here lies the not-yet-implemented method 'CanDoubleJump'
		// Here lies the not-yet-implemented method 'BotNearObjective'
		// Here lies the not-yet-implemented method 'NearObjective'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'TellBotHowToDisable'
		// Here lies the not-yet-implemented method 'GetNumDefenders'
		// Here lies the not-yet-implemented method 'BetterObjectiveThan'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ClientReset'
		// Here lies the not-yet-implemented method 'AddScorer'
		// Here lies the not-yet-implemented method 'ShareScore'
		// Here lies the not-yet-implemented method 'SetTeam'
		// Here lies the not-yet-implemented method 'FindGoodEndView'
		// Here lies the not-yet-implemented method 'TeleportTo'
		// Here lies the not-yet-implemented method 'ValidSpawnPointFor'
		// Here lies the not-yet-implemented method 'SetAlarm'
		// Here lies the not-yet-implemented method 'TriggerFlagEvent'
		// Here lies the not-yet-implemented method 'MarkShootSpotsFor'
		// Here lies the not-yet-implemented method 'ReachedParkingSpot'
		// Here lies the not-yet-implemented method 'FlagUpdated'
		// Here lies the not-yet-implemented method 'OnFlagComesHome'
		// Here lies the not-yet-implemented method 'OnFlagTaken'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
