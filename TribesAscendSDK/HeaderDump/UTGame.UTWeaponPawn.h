#pragma once
#include "UDKBase.UDKWeaponPawn.h"
#include "Core.Object.Vector.h"
#include "Engine.HUD.h"
#include "Core.Object.Rotator.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Controller.h"
#include "Engine.Actor.TraceHitInfo.h"
#include "UDKBase.UDKCarriedObject.h"
#include "Engine.Actor.h"
#include "UTGame.UTHUD.h"
#include "Engine.Canvas.h"
#include "Core.Object.Vector2D.h"
namespace UnrealScript
{
	class UTWeaponPawn : public UDKWeaponPawn
	{
	public:
		ScriptName GetVehicleDrivingStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.GetVehicleDrivingStatName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.CalcCamera");
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
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = out_ViewRotation;
			*(Rotator*)(params + 16) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 4);
			out_DeltaRot = *(Rotator*)(params + 16);
			free(params);
		}
		void SetFiringMode(class Weapon* Weap, byte FiringModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.SetFiringMode");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = Weap;
			*(params + 4) = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementFlashCount(class Weapon* Who, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.IncrementFlashCount");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = Who;
			*(params + 4) = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlashCount(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ClearFlashCount");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlashLocation(class Weapon* Who, byte FireModeNum, Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.SetFlashLocation");
			byte* params = (byte*)malloc(17);
			*(class Weapon**)params = Who;
			*(params + 4) = FireModeNum;
			*(Vector*)(params + 8) = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlashLocation(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ClearFlashLocation");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.PossessedBy");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ServerAdjacentSeat");
			byte* params = (byte*)malloc(8);
			*(int*)params = Direction;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ServerChangeSeat");
			byte* params = (byte*)malloc(4);
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustCameraScale(bool bIn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.AdjustCameraScale");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.PlaceExitingDriver");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DropToGround()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DropToGround");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.AddVelocity");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = NewVelocity;
			*(Vector*)(params + 12) = HitLocation;
			*(ScriptClass**)(params + 24) = DamageType;
			*(TraceHitInfo*)(params + 28) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.JumpOffPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BaseChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.BaseChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMovementPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.SetMovementPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DoJump");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetCollisionRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.GetCollisionRadius");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SetBaseEyeheight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.SetBaseEyeheight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.AttachDriver");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.HoldGameObject");
			byte* params = (byte*)malloc(4);
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.FaceRotation");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = NewRotation;
			*(float*)(params + 12) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DriverLeave");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.TooCloseToAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DisplayHud(class UTHUD* HUD, class Canvas* Canvas, Vector2D HudPOS, int SIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DisplayHud");
			byte* params = (byte*)malloc(20);
			*(class UTHUD**)params = HUD;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector2D*)(params + 8) = HudPOS;
			*(int*)(params + 16) = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ApplyWeaponEffects");
			byte* params = (byte*)malloc(8);
			*(int*)params = OverlayFlags;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
