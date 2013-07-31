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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39530);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39917);
			byte params[24] = { NULL };
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		ScriptName GetFireTriggerTag(int BarrelIndex, int FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39947);
			byte params[16] = { NULL };
			*(int*)params = BarrelIndex;
			*(int*)&params[4] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		UDKPawn::MaterialImpactEffect GetImpactEffect(class Actor* HitActor, class PhysicalMaterial* HitMaterial, byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39974);
			byte params[57] = { NULL };
			*(class Actor**)params = HitActor;
			*(class PhysicalMaterial**)&params[4] = HitMaterial;
			params[8] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPawn::MaterialImpactEffect*)&params[12];
		}
		bool CanHitDesiredTarget(Vector SocketLocation, Rotator SocketRotation, Vector DesiredAimPoint, class Actor* TargetActor, Vector& RealAimPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49833);
			byte params[56] = { NULL };
			*(Vector*)params = SocketLocation;
			*(Rotator*)&params[12] = SocketRotation;
			*(Vector*)&params[24] = DesiredAimPoint;
			*(class Actor**)&params[36] = TargetActor;
			*(Vector*)&params[40] = RealAimPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RealAimPoint = *(Vector*)&params[40];
			return *(bool*)&params[52];
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49847);
			byte params[20] = { NULL };
			*(class Canvas**)params = Canvas;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(float*)&params[12] = HUDScaleX;
			*(float*)&params[16] = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCrosshairScaling(class HUD* HUD)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49853);
			byte params[4] = { NULL };
			*(class HUD**)params = HUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawWeaponCrosshair(class HUD* HUD)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49855);
			byte params[4] = { NULL };
			*(class HUD**)params = HUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetDesiredAimPoint(class Actor*& TargetActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49865);
			byte params[16] = { NULL };
			*(class Actor**)params = TargetActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TargetActor = *(class Actor**)params;
			return *(Vector*)&params[4];
		}
		void GetFireStartLocationAndRotation(Vector& StartLocation, Rotator& StartRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49875);
			byte params[24] = { NULL };
			*(Vector*)params = StartLocation;
			*(Rotator*)&params[12] = StartRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StartLocation = *(Vector*)params;
			StartRotation = *(Rotator*)&params[12];
		}
		bool IsAimCorrect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49878);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49886);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49895);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49898);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Activate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49899);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49900);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49901);
			byte params[24] = { NULL };
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49904);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49907);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49911);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		Vector InstantFireStartTrace()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49914);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector InstantFireEndTrace(Vector StartTrace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49916);
			byte params[24] = { NULL };
			*(Vector*)params = StartTrace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49919);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		void NotifyVehicleDeployed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49921);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyVehicleUndeployed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49922);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponPlaySound(class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49923);
			byte params[12] = { NULL };
			*(class SoundCue**)params = Sound;
			*(float*)&params[4] = NoiseLoudness;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		UTWeapon::EZoomState GetZoomedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49931);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTWeapon::EZoomState*)params;
		}
		void ServerSetZoom(bool bNowZoomed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49933);
			byte params[4] = { NULL };
			*(bool*)params = bNowZoomed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49935);
			byte params[4] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49937);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
