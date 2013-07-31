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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43961);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43964);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43969);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43971);
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
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43978);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = out_ViewRotation;
			*(Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[4];
			out_DeltaRot = *(Rotator*)&params[16];
		}
		void SetFiringMode(class Weapon* Weap, byte FiringModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43985);
			byte params[5] = { NULL };
			*(class Weapon**)params = Weap;
			params[4] = FiringModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFlashCount(class Weapon* Who, byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43988);
			byte params[5] = { NULL };
			*(class Weapon**)params = Who;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashCount(class Weapon* Who)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43991);
			byte params[4] = { NULL };
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(class Weapon* Who, byte FireModeNum, Vector NewLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43993);
			byte params[17] = { NULL };
			*(class Weapon**)params = Who;
			params[4] = FireModeNum;
			*(Vector*)&params[8] = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashLocation(class Weapon* Who)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43997);
			byte params[4] = { NULL };
			*(class Weapon**)params = Who;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43999);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44002);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44004);
			byte params[8] = { NULL };
			*(int*)params = Direction;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44007);
			byte params[4] = { NULL };
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustCameraScale(bool bIn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44009);
			byte params[4] = { NULL };
			*(bool*)params = bIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44011);
			byte params[8] = { NULL };
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DropToGround()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44014);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44015);
			byte params[56] = { NULL };
			*(Vector*)params = NewVelocity;
			*(Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44020);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BaseChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMovementPhysics()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44023);
			byte params[8] = { NULL };
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetCollisionRadius()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44026);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SetBaseEyeheight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44028);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44029);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44032);
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44034);
			byte params[16] = { NULL };
			*(Rotator*)params = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44037);
			byte params[8] = { NULL };
			*(bool*)params = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44041);
			byte params[24] = { NULL };
			*(class Controller**)params = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44047);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DisplayHud(class UTHUD* HUD, class Canvas* Canvas, Object::Vector2D HudPOS, int SIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44051);
			byte params[20] = { NULL };
			*(class UTHUD**)params = HUD;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector2D*)&params[8] = HudPOS;
			*(int*)&params[16] = SIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44056);
			byte params[8] = { NULL };
			*(int*)params = OverlayFlags;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
