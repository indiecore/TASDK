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
		class ScorerRecord
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.UsedBy");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* GetAutoObjectiveActor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetAutoObjectiveActor");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetFlag");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTCarriedObject**)&params[0];
		}
		bool Shootable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.Shootable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsStandalone()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsStandalone");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Vector GetHUDOffset(class PlayerController* PC, class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetHUDOffset");
			byte params[20] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
		int GetLocationMessageIndex(class UTBot* B, class Pawn* StatusPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetLocationMessageIndex");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Pawn**)&params[4] = StatusPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		class SoundNodeWave* GetLocationSpeechFor(class PlayerController* PC, int LocationSpeechOffset, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetLocationSpeechFor");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(int*)&params[4] = LocationSpeechOffset;
			*(int*)&params[8] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddTeamStaticMesh(class UTTeamStaticMesh* SMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.AddTeamStaticMesh");
			byte params[4] = { NULL };
			*(class UTTeamStaticMesh**)&params[0] = SMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTeamStaticMeshes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.UpdateTeamStaticMeshes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTGameObjective* FindNearestFriendlyNode(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.FindNearestFriendlyNode");
			byte params[8] = { NULL };
			*(int*)&params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[4];
		}
		bool CalcCamera(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.CalcCamera");
			byte params[36] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		void HighlightOnMinimap(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.HighlightOnMinimap");
			byte params[4] = { NULL };
			*(int*)&params[0] = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderMinimap(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.RenderMinimap");
			byte params[16] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(float*)&params[12] = ColorPercent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderExtraDetails(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent, bool bSelected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.RenderExtraDetails");
			byte params[20] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(float*)&params[12] = ColorPercent;
			*(bool*)&params[16] = bSelected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMapSelection(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.DrawMapSelection");
			byte params[12] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsCritical()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsCritical");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsNeutral()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsNeutral");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool TellBotHowToHeal(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TellBotHowToHeal");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TeamLink(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TeamLink");
			byte params[8] = { NULL };
			*(int*)&params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NeedsHealing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.NeedsHealing");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanDoubleJump(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.CanDoubleJump");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool BotNearObjective(class AIController* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.BotNearObjective");
			byte params[8] = { NULL };
			*(class AIController**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NearObjective(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.NearObjective");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool TellBotHowToDisable(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TellBotHowToDisable");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetNumDefenders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetNumDefenders");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool BetterObjectiveThan(class UTGameObjective* Best, byte DesiredTeamNum, byte RequesterTeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.BetterObjectiveThan");
			byte params[10] = { NULL };
			*(class UTGameObjective**)&params[0] = Best;
			params[4] = DesiredTeamNum;
			params[5] = RequesterTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ClientReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddScorer(class UTPlayerReplicationInfo* PRI, float Pct)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.AddScorer");
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = PRI;
			*(float*)&params[4] = Pct;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShareScore(int TotalScore, ScriptString* EventDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ShareScore");
			byte params[16] = { NULL };
			*(int*)&params[0] = TotalScore;
			*(ScriptString**)&params[4] = EventDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeam(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.SetTeam");
			byte params[1] = { NULL };
			params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindGoodEndView(class PlayerController* PC, Object::Rotator& GoodRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.FindGoodEndView");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(Object::Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Object::Rotator*)&params[4];
		}
		bool TeleportTo(class UTPawn* Traveler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TeleportTo");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = Traveler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ValidSpawnPointFor(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ValidSpawnPointFor");
			byte params[5] = { NULL };
			params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetAlarm(bool bNowOn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.SetAlarm");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowOn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerFlagEvent(ScriptName EventType, class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TriggerFlagEvent");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = EventType;
			*(class Controller**)&params[8] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MarkShootSpotsFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.MarkShootSpotsFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReachedParkingSpot(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ReachedParkingSpot");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void FlagUpdated(bool bFlagHome)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.FlagUpdated");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bFlagHome;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFlagComesHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.OnFlagComesHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFlagTaken()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.OnFlagTaken");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
