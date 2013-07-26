#pragma once
#include "TribesGame.TrVehicle.h"
#include "Core.Object.Vector.h"
#include "Engine.CameraShake.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicle_Tank." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrVehicle_Tank." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicle_Tank." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicle_Tank : public TrVehicle
	{
	public:
		ADD_VAR(::FloatProperty, m_CameraShakeEffectiveRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraShake, m_FireCameraShake)
		ADD_VAR(::ByteProperty, GunnerFiringMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, GunnerFlashCount, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, GunnerWeaponRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, GunnerFlashLocation, 0xFFFFFFFF)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleWeaponFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.VehicleWeaponFireEffects");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitLocation;
			*(int*)(params + 12) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessViewRotationBasedOnSeat(int SeatIndex, float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.ProcessViewRotationBasedOnSeat");
			byte* params = (byte*)malloc(32);
			*(int*)params = SeatIndex;
			*(float*)(params + 4) = DeltaTime;
			*(Rotator*)(params + 8) = out_ViewRotation;
			*(Rotator*)(params + 20) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 8);
			out_DeltaRot = *(Rotator*)(params + 20);
			free(params);
		}
		Rotator LimitViewRotation(Rotator LimitViewRotation, float LimitViewPitchMin, float LimitViewPitchMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.LimitViewRotation");
			byte* params = (byte*)malloc(32);
			*(Rotator*)params = LimitViewRotation;
			*(float*)(params + 12) = LimitViewPitchMin;
			*(float*)(params + 16) = LimitViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
