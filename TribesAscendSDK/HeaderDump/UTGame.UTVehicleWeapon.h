#pragma once
#include "Engine.Canvas.h"
#include "UTGame.UTWeapon.h"
#include "Engine.HUD.h"
#include "UTGame.UTVehicle.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.SoundCue.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Projectile.h"
#include "UTGame.UTPlayerController.h"
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
	class UTVehicleWeapon : public UTWeapon
	{
	public:
		ADD_STRUCT(int, SeatIndex, 1472)
		ADD_OBJECT(UTVehicle, MyVehicle, 1476)
		ADD_BOOL(bIgnoreSocketPitchRotation, 1644, 0x4)
		ADD_BOOL(bIgnoreDownwardPitch, 1644, 0x8)
		ADD_OBJECT(SoundCue, BulletWhip, 1624)
		ADD_STRUCT(ScriptArray<ScriptName>, FireTriggerTags, 1480)
		ADD_STRUCT(ScriptArray<ScriptName>, AltFireTriggerTags, 1492)
		ADD_STRUCT(ScriptArray<UDKPawn::MaterialImpactEffect>, ImpactEffects, 1504)
		ADD_STRUCT(ScriptArray<UDKPawn::MaterialImpactEffect>, AltImpactEffects, 1516)
		ADD_OBJECT(ScriptClass, VehicleClass, 1648)
		ADD_BOOL(bDebugTurret, 1644, 0x10)
		ADD_BOOL(bCurrentlyZoomed, 1644, 0x2)
		ADD_BOOL(bPlaySoundFromSocket, 1644, 0x1)
		ADD_STRUCT(float, MaxFinalAimAdjustment, 1640)
		ADD_STRUCT(float, CurrentCrosshairScaling, 1636)
		ADD_STRUCT(float, LastInCorrectAimTime, 1632)
		ADD_STRUCT(float, LastCorrectAimTime, 1628)
		ADD_STRUCT(UDKPawn::MaterialImpactEffect, DefaultAltImpactEffect, 1576)
		ADD_STRUCT(UDKPawn::MaterialImpactEffect, DefaultImpactEffect, 1528)
		float GetMaxFinalAimAdjustment()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetMaxFinalAimAdjustment");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Rotator GetAdjustedAim(Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetAdjustedAim");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		ScriptName GetFireTriggerTag(int BarrelIndex, int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetFireTriggerTag");
			byte params[16] = { NULL };
			*(int*)&params[0] = BarrelIndex;
			*(int*)&params[4] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		UDKPawn::MaterialImpactEffect GetImpactEffect(class Actor* HitActor, class PhysicalMaterial* HitMaterial, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetImpactEffect");
			byte params[57] = { NULL };
			*(class Actor**)&params[0] = HitActor;
			*(class PhysicalMaterial**)&params[4] = HitMaterial;
			params[8] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPawn::MaterialImpactEffect*)&params[12];
		}
		bool CanHitDesiredTarget(Object::Vector SocketLocation, Object::Rotator SocketRotation, Object::Vector DesiredAimPoint, class Actor* TargetActor, Object::Vector& RealAimPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.CanHitDesiredTarget");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = SocketLocation;
			*(Object::Rotator*)&params[12] = SocketRotation;
			*(Object::Vector*)&params[24] = DesiredAimPoint;
			*(class Actor**)&params[36] = TargetActor;
			*(Object::Vector*)&params[40] = RealAimPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RealAimPoint = *(Object::Vector*)&params[40];
			return *(bool*)&params[52];
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.DrawKillIcon");
			byte params[20] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(float*)&params[12] = HUDScaleX;
			*(float*)&params[16] = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCrosshairScaling(class HUD* HUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetCrosshairScaling");
			byte params[4] = { NULL };
			*(class HUD**)&params[0] = HUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawWeaponCrosshair(class HUD* HUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.DrawWeaponCrosshair");
			byte params[4] = { NULL };
			*(class HUD**)&params[0] = HUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetDesiredAimPoint(class Actor*& TargetActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetDesiredAimPoint");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = TargetActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TargetActor = *(class Actor**)&params[0];
			return *(Object::Vector*)&params[4];
		}
		void GetFireStartLocationAndRotation(Object::Vector& StartLocation, Object::Rotator& StartRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetFireStartLocationAndRotation");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartLocation;
			*(Object::Rotator*)&params[12] = StartRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StartLocation = *(Object::Vector*)&params[0];
			StartRotation = *(Object::Rotator*)&params[12];
		}
		bool IsAimCorrect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.IsAimCorrect");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetFireInterval");
			byte params[5] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.AttachWeaponTo");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.DetachWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.PutDownWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Vector GetPhysicalFireStartLoc(Object::Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetPhysicalFireStartLoc");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.BeginFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.EndFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.ProjectileFire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)&params[0];
		}
		Object::Vector InstantFireStartTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.InstantFireStartTrace");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		Object::Vector InstantFireEndTrace(Object::Vector StartTrace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.InstantFireEndTrace");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartTrace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetTraceOwner");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		void NotifyVehicleDeployed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.NotifyVehicleDeployed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyVehicleUndeployed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.NotifyVehicleUndeployed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponPlaySound(class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.WeaponPlaySound");
			byte params[12] = { NULL };
			*(class SoundCue**)&params[0] = Sound;
			*(float*)&params[4] = NoiseLoudness;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		UTWeapon::EZoomState GetZoomedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetZoomedState");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTWeapon::EZoomState*)&params[0];
		}
		void ServerSetZoom(bool bNowZoomed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.ServerSetZoom");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowZoomed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.StartZoom");
			byte params[4] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.EndZoom");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
