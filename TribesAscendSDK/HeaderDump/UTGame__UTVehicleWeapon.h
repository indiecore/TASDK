#pragma once
#include "UTGame__UTPlayerController.h"
#include "Engine__Actor.h"
#include "UTGame__UTWeapon.h"
#include "Engine__HUD.h"
#include "UTGame__UTVehicle.h"
#include "Engine__SoundCue.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Canvas.h"
#include "Engine__Projectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVehicleWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTVehicleWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVehicleWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVehicleWeapon : public UTWeapon
	{
	public:
		ADD_VAR(::IntProperty, SeatIndex, 0xFFFFFFFF)
		ADD_OBJECT(UTVehicle, MyVehicle)
		ADD_VAR(::BoolProperty, bIgnoreSocketPitchRotation, 0x4)
		ADD_VAR(::BoolProperty, bIgnoreDownwardPitch, 0x8)
		ADD_OBJECT(SoundCue, BulletWhip)
		ADD_OBJECT(ScriptClass, VehicleClass)
		ADD_VAR(::BoolProperty, bDebugTurret, 0x10)
		ADD_VAR(::BoolProperty, bCurrentlyZoomed, 0x2)
		ADD_VAR(::BoolProperty, bPlaySoundFromSocket, 0x1)
		ADD_VAR(::FloatProperty, MaxFinalAimAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentCrosshairScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastInCorrectAimTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCorrectAimTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultAltImpactEffect'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'DefaultImpactEffect'!
		float GetMaxFinalAimAdjustment()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetMaxFinalAimAdjustment");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetAdjustedAim");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptName GetFireTriggerTag(int BarrelIndex, int FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetFireTriggerTag");
			byte* params = (byte*)malloc(16);
			*(int*)params = BarrelIndex;
			*(int*)(params + 4) = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect'!
void* GetImpactEffect(class Actor* HitActor, class PhysicalMaterial* HitMaterial, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetImpactEffect");
			byte* params = (byte*)malloc(57);
			*(class Actor**)params = HitActor;
			*(class PhysicalMaterial**)(params + 4) = HitMaterial;
			*(params + 8) = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		bool CanHitDesiredTarget(Vector SocketLocation, Rotator SocketRotation, Vector DesiredAimPoint, class Actor* TargetActor, Vector& RealAimPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.CanHitDesiredTarget");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = SocketLocation;
			*(Rotator*)(params + 12) = SocketRotation;
			*(Vector*)(params + 24) = DesiredAimPoint;
			*(class Actor**)(params + 36) = TargetActor;
			*(Vector*)(params + 40) = RealAimPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			RealAimPoint = *(Vector*)(params + 40);
			auto returnVal = *(bool*)(params + 52);
			free(params);
			return returnVal;
		}
		void DrawKillIcon(class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.DrawKillIcon");
			byte* params = (byte*)malloc(20);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = ScreenX;
			*(float*)(params + 8) = ScreenY;
			*(float*)(params + 12) = HUDScaleX;
			*(float*)(params + 16) = HUDScaleY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetCrosshairScaling(class HUD* HUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetCrosshairScaling");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = HUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawWeaponCrosshair(class HUD* HUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.DrawWeaponCrosshair");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = HUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetDesiredAimPoint(class Actor*& TargetActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetDesiredAimPoint");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = TargetActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			TargetActor = *(class Actor**)params;
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetFireStartLocationAndRotation(Vector& StartLocation, Rotator& StartRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetFireStartLocationAndRotation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartLocation;
			*(Rotator*)(params + 12) = StartRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			StartLocation = *(Vector*)params;
			StartRotation = *(Rotator*)(params + 12);
			free(params);
		}
		bool IsAimCorrect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.IsAimCorrect");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetFireInterval");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.AttachWeaponTo");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)(params + 4) = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetPhysicalFireStartLoc");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.BeginFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.EndFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		Vector InstantFireStartTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.InstantFireStartTrace");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector InstantFireEndTrace(Vector StartTrace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.InstantFireEndTrace");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartTrace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetTraceOwner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(12);
			*(class SoundCue**)params = Sound;
			*(float*)(params + 4) = NoiseLoudness;
			*(bool*)(params + 8) = bStopWhenOwnerDestroyed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetZoomedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.GetZoomedState");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void ServerSetZoom(bool bNowZoomed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.ServerSetZoom");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowZoomed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.StartZoom");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleWeapon.EndZoom");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			*(bool*)(params + 4) = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
