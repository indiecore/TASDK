#pragma once
#include "Engine.UIRoot.TextureCoordinates.h"
#include "UDKBase.UDKGameObjective.h"
#include "Engine.SoundNodeWave.h"
#include "Core.Object.LinearColor.h"
#include "UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo.h"
#include "Engine.Material.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.Volume.h"
#include "UTGame.UTDefensePoint.h"
#include "UTGame.UTSquadAI.h"
#include "Engine.Pawn.h"
#include "Engine.Actor.h"
#include "UTGame.UTPlayerController.h"
#include "Core.Object.Vector.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTTeamStaticMesh.h"
#include "Core.Object.Rotator.h"
#include "UTGame.UTMapInfo.h"
#include "Engine.AIController.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "Engine.Controller.h"
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
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, AttackLinearColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxBeaconDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHighlightUpdate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinimapIconScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxHighlightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightScale, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ObjectiveAnnouncementInfo>, DefendAnnouncement, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ObjectiveAnnouncementInfo>, AttackAnnouncement, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraViewDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSensorRange, 0xFFFFFFFF)
		ADD_OBJECT(Material, HudMaterial)
		ADD_VAR(::FloatProperty, IconExtentY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconExtentX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconPosY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconPosX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, AttackCoords, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ControlColor, 0xFFFFFFFF)
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
		bool UsedBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.UsedBy");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Actor* GetAutoObjectiveActor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetAutoObjectiveActor");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetFlag");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTCarriedObject**)params;
			free(params);
			return returnVal;
		}
		bool Shootable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.Shootable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsStandalone()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsStandalone");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Vector GetHUDOffset(class PlayerController* PC, class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetHUDOffset");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetLocationMessageIndex(class UTBot* B, class Pawn* StatusPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetLocationMessageIndex");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Pawn**)(params + 4) = StatusPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		class SoundNodeWave* GetLocationSpeechFor(class PlayerController* PC, int LocationSpeechOffset, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetLocationSpeechFor");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			*(int*)(params + 4) = LocationSpeechOffset;
			*(int*)(params + 8) = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 12);
			free(params);
			return returnVal;
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddTeamStaticMesh(class UTTeamStaticMesh* SMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.AddTeamStaticMesh");
			byte* params = (byte*)malloc(4);
			*(class UTTeamStaticMesh**)params = SMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTeamStaticMeshes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.UpdateTeamStaticMeshes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UTGameObjective* FindNearestFriendlyNode(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.FindNearestFriendlyNode");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGameObjective**)(params + 4);
			free(params);
			return returnVal;
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.CalcCamera");
			byte* params = (byte*)malloc(36);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void HighlightOnMinimap(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.HighlightOnMinimap");
			byte* params = (byte*)malloc(4);
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderMinimap(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.RenderMinimap");
			byte* params = (byte*)malloc(16);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			*(float*)(params + 12) = ColorPercent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderExtraDetails(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, float ColorPercent, bool bSelected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.RenderExtraDetails");
			byte* params = (byte*)malloc(20);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			*(float*)(params + 12) = ColorPercent;
			*(bool*)(params + 16) = bSelected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMapSelection(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.DrawMapSelection");
			byte* params = (byte*)malloc(12);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsCritical()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsCritical");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsNeutral()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsNeutral");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.IsActive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool TellBotHowToHeal(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TellBotHowToHeal");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TeamLink(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TeamLink");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NeedsHealing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.NeedsHealing");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanDoubleJump(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.CanDoubleJump");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool BotNearObjective(class AIController* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.BotNearObjective");
			byte* params = (byte*)malloc(8);
			*(class AIController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NearObjective(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.NearObjective");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool TellBotHowToDisable(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TellBotHowToDisable");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetNumDefenders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.GetNumDefenders");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool BetterObjectiveThan(class UTGameObjective* Best, byte DesiredTeamNum, byte RequesterTeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.BetterObjectiveThan");
			byte* params = (byte*)malloc(10);
			*(class UTGameObjective**)params = Best;
			*(params + 4) = DesiredTeamNum;
			*(params + 5) = RequesterTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = PRI;
			*(float*)(params + 4) = Pct;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShareScore(int TotalScore, ScriptArray<wchar_t> EventDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ShareScore");
			byte* params = (byte*)malloc(16);
			*(int*)params = TotalScore;
			*(ScriptArray<wchar_t>*)(params + 4) = EventDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTeam(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.SetTeam");
			byte* params = (byte*)malloc(1);
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FindGoodEndView(class PlayerController* PC, Rotator& GoodRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.FindGoodEndView");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			*(Rotator*)(params + 4) = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			GoodRotation = *(Rotator*)(params + 4);
			free(params);
		}
		bool TeleportTo(class UTPawn* Traveler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TeleportTo");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = Traveler;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ValidSpawnPointFor(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ValidSpawnPointFor");
			byte* params = (byte*)malloc(5);
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetAlarm(bool bNowOn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.SetAlarm");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowOn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TriggerFlagEvent(ScriptName EventType, class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.TriggerFlagEvent");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = EventType;
			*(class Controller**)(params + 8) = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MarkShootSpotsFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.MarkShootSpotsFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReachedParkingSpot(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.ReachedParkingSpot");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void FlagUpdated(bool bFlagHome)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameObjective.FlagUpdated");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFlagHome;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
