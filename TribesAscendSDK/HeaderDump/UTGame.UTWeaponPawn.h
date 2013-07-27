#pragma once
#include "UDKBase.UDKWeaponPawn.h"
#include "Engine.HUD.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "UTGame.UTHUD.h"
#include "UDKBase.UDKCarriedObject.h"
#include "Engine.Canvas.h"
namespace UnrealScript
{
	class UTWeaponPawn : public UDKWeaponPawn
	{
	public:
		ScriptName GetVehicleDrivingStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.GetVehicleDrivingStatName");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcCamera(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.CalcCamera");
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
		void ProcessViewRotation(float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ProcessViewRotation");
			byte params[28] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Rotator*)&params[4] = out_ViewRotation;
			*(Object::Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[4];
			out_DeltaRot = *(Object::Rotator*)&params[16];
		}
		void SetFiringMode(class Weapon* Weap, byte FiringModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.SetFiringMode");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = Weap;
			params[4] = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFlashCount(class Weapon* Who, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.IncrementFlashCount");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = Who;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashCount(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ClearFlashCount");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(class Weapon* Who, byte FireModeNum, Object::Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.SetFlashLocation");
			byte params[17] = { NULL };
			*(class Weapon**)&params[0] = Who;
			params[4] = FireModeNum;
			*(Object::Vector*)&params[8] = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashLocation(class Weapon* Who)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ClearFlashLocation");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.PossessedBy");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ServerAdjacentSeat");
			byte params[8] = { NULL };
			*(int*)&params[0] = Direction;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ServerChangeSeat");
			byte params[4] = { NULL };
			*(int*)&params[0] = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustCameraScale(bool bIn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.AdjustCameraScale");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.PlaceExitingDriver");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DropToGround()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DropToGround");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVelocity(Object::Vector NewVelocity, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.AddVelocity");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = NewVelocity;
			*(Object::Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(bool*)&params[0] = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetCollisionRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.GetCollisionRadius");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void SetBaseEyeheight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.SetBaseEyeheight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.AttachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.HoldGameObject");
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)&params[0] = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FaceRotation(Object::Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.FaceRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DriverLeave");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.TooCloseToAttack");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DisplayHud(class UTHUD* HUD, class Canvas* Canvas, Object::Vector2D HudPOS, int SIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.DisplayHud");
			byte params[20] = { NULL };
			*(class UTHUD**)&params[0] = HUD;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector2D*)&params[8] = HudPOS;
			*(int*)&params[16] = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPawn.ApplyWeaponEffects");
			byte params[8] = { NULL };
			*(int*)&params[0] = OverlayFlags;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
