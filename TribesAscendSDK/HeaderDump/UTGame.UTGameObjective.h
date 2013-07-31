#pragma once
#include "UDKBase.UDKGameObjective.h"
#include "UTGame.UTVehicleFactory.h"
#include "Engine.NavigationPoint.h"
#include "Core.Object.h"
#include "UTGame.UTTeamStaticMesh.h"
#include "Engine.PlayerStart.h"
#include "Engine.SoundNodeWave.h"
#include "UDKBase.UDKPlayerController.h"
#include "Engine.Material.h"
#include "Engine.UIRoot.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.Volume.h"
#include "UTGame.UTDefensePoint.h"
#include "UTGame.UTSquadAI.h"
#include "Engine.Pawn.h"
#include "Engine.Actor.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTMapInfo.h"
#include "Engine.AIController.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "Engine.Controller.h"
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
	class UTGameObjective : public UDKGameObjective
	{
	public:
		struct ScorerRecord
		{
		public:
			ADD_STRUCT(float, Pct, 4)
			ADD_OBJECT(UTPlayerReplicationInfo, PRI, 0)
		};
		ADD_BOOL(bAllowRemoteUse, 744, 0x2)
		ADD_STRUCT(ScriptArray<class NavigationPoint*>, VehicleParkingSpots, 772)
		ADD_STRUCT(ScriptArray<UTGameObjective::ScorerRecord>, Scorers, 792)
		ADD_STRUCT(ScriptArray<class UTVehicleFactory*>, VehicleFactories, 904)
		ADD_STRUCT(ScriptArray<class PlayerStart*>, PlayerStarts, 916)
		ADD_STRUCT(ScriptArray<class UTTeamStaticMesh*>, TeamStaticMeshes, 928)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, LocationSpeech, 1000)
		ADD_STRUCT(Object::LinearColor, AttackLinearColor, 1012)
		ADD_STRUCT(float, MaxBeaconDistance, 996)
		ADD_STRUCT(float, LastPostRenderTraceTime, 992)
		ADD_STRUCT(float, LastHighlightUpdate, 988)
		ADD_STRUCT(float, MinimapIconScale, 984)
		ADD_STRUCT(float, HighlightSpeed, 980)
		ADD_STRUCT(float, MaxHighlightScale, 976)
		ADD_STRUCT(float, HighlightScale, 972)
		ADD_STRUCT(UDKPlayerController::ObjectiveAnnouncementInfo, DefendAnnouncement, 956)
		ADD_STRUCT(UDKPlayerController::ObjectiveAnnouncementInfo, AttackAnnouncement, 940)
		ADD_STRUCT(float, CameraViewDistance, 900)
		ADD_STRUCT(float, MaxSensorRange, 896)
		ADD_OBJECT(Material, HudMaterial, 892)
		ADD_STRUCT(float, IconExtentY, 888)
		ADD_STRUCT(float, IconExtentX, 884)
		ADD_STRUCT(float, IconPosY, 880)
		ADD_STRUCT(float, IconPosX, 876)
		ADD_STRUCT(UIRoot::TextureCoordinates, AttackCoords, 860)
		ADD_STRUCT(Object::LinearColor, ControlColor, 812)
		ADD_OBJECT(UTGameObjective, NextObjective, 808)
		ADD_STRUCT(int, Score, 804)
		ADD_STRUCT(float, BaseRadius, 788)
		ADD_OBJECT(Volume, MyBaseVolume, 784)
		ADD_STRUCT(ScriptString*, ObjectiveName, 760)
		ADD_OBJECT(UTDefensePoint, DefensePoints, 756)
		ADD_OBJECT(UTSquadAI, DefenseSquad, 752)
		ADD_STRUCT(byte, DefensePriority, 749)
		ADD_STRUCT(byte, StartTeam, 748)
		ADD_BOOL(bScriptRenderAdditionalMinimap, 744, 0x200)
		ADD_BOOL(bHasLocationSpeech, 744, 0x100)
		ADD_BOOL(bPostRenderTraceSucceeded, 744, 0x80)
		ADD_BOOL(bIsActive, 744, 0x40)
		ADD_BOOL(bIsDisabled, 744, 0x20)
		ADD_BOOL(bIsConstructing, 744, 0x10)
		ADD_BOOL(bHasSensor, 744, 0x8)
		ADD_BOOL(bFirstObjective, 744, 0x4)
		ADD_BOOL(bAlreadyRendered, 744, 0x1)
		bool UsedBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36480);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* GetAutoObjectiveActor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36543);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42577);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTCarriedObject**)params;
		}
		bool Shootable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43024);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44331);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsStandalone()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44338);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Vector GetHUDOffset(class PlayerController* PC, class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44340);
			byte params[20] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		int GetLocationMessageIndex(class UTBot* B, class Pawn* StatusPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44345);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Pawn**)&params[4] = StatusPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		class SoundNodeWave* GetLocationSpeechFor(class PlayerController* PC, int LocationSpeechOffset, int MessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44349);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			*(int*)&params[4] = LocationSpeechOffset;
			*(int*)&params[8] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44355);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddTeamStaticMesh(class UTTeamStaticMesh* SMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44357);
			byte params[4] = { NULL };
			*(class UTTeamStaticMesh**)params = SMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTeamStaticMeshes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44359);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44361);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTGameObjective* FindNearestFriendlyNode(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44363);
			byte params[8] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[4];
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44367);
			byte params[36] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		void HighlightOnMinimap(int Switch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44375);
			byte params[4] = { NULL };
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderMinimap(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44377);
			byte params[16] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(float*)&params[12] = ColorPercent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderExtraDetails(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent, bool bSelected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44382);
			byte params[20] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(float*)&params[12] = ColorPercent;
			*(bool*)&params[16] = bSelected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMapSelection(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44388);
			byte params[12] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsCritical()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44393);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsNeutral()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44395);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44397);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool TellBotHowToHeal(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44399);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TeamLink(int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44402);
			byte params[8] = { NULL };
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NeedsHealing()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44405);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanDoubleJump(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44407);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool BotNearObjective(class AIController* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44410);
			byte params[8] = { NULL };
			*(class AIController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NearObjective(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44414);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44418);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool TellBotHowToDisable(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44420);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetNumDefenders()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44425);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool BetterObjectiveThan(class UTGameObjective* Best, byte DesiredTeamNum, byte RequesterTeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44429);
			byte params[10] = { NULL };
			*(class UTGameObjective**)params = Best;
			params[4] = DesiredTeamNum;
			params[5] = RequesterTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44434);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44435);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddScorer(class UTPlayerReplicationInfo* PRI, float Pct)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44436);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = PRI;
			*(float*)&params[4] = Pct;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShareScore(int TotalScore, ScriptString* EventDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44441);
			byte params[16] = { NULL };
			*(int*)params = TotalScore;
			*(ScriptString**)&params[4] = EventDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeam(byte TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44446);
			byte params[1] = { NULL };
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindGoodEndView(class PlayerController* PC, Rotator& GoodRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44448);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			*(Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Rotator*)&params[4];
		}
		bool TeleportTo(class UTPawn* Traveler)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44458);
			byte params[8] = { NULL };
			*(class UTPawn**)params = Traveler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ValidSpawnPointFor(byte TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44461);
			byte params[5] = { NULL };
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetAlarm(bool bNowOn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44464);
			byte params[4] = { NULL };
			*(bool*)params = bNowOn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerFlagEvent(ScriptName EventType, class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44466);
			byte params[12] = { NULL };
			*(ScriptName*)params = EventType;
			*(class Controller**)&params[8] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MarkShootSpotsFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44472);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReachedParkingSpot(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44476);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void FlagUpdated(bool bFlagHome)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44480);
			byte params[4] = { NULL };
			*(bool*)params = bFlagHome;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFlagComesHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44482);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFlagTaken()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44483);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
