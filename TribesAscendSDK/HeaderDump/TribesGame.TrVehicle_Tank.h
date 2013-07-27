#pragma once
#include "TribesGame.TrVehicle.h"
#include "Engine.CameraShake.h"
#include "Core.Object.h"
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
	class TrVehicle_Tank : public TrVehicle
	{
	public:
		ADD_STRUCT(float, m_CameraShakeEffectiveRadius, 3244)
		ADD_OBJECT(CameraShake, m_FireCameraShake, 3240)
		ADD_STRUCT(byte, GunnerFiringMode, 3237)
		ADD_STRUCT(byte, GunnerFlashCount, 3236)
		ADD_STRUCT(Object::Rotator, GunnerWeaponRotation, 3224)
		ADD_STRUCT(Object::Vector, GunnerFlashLocation, 3212)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponFireEffects(Object::Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.VehicleWeaponFireEffects");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessViewRotationBasedOnSeat(int SeatIndex, float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.ProcessViewRotationBasedOnSeat");
			byte params[32] = { NULL };
			*(int*)&params[0] = SeatIndex;
			*(float*)&params[4] = DeltaTime;
			*(Object::Rotator*)&params[8] = out_ViewRotation;
			*(Object::Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[8];
			out_DeltaRot = *(Object::Rotator*)&params[20];
		}
		Object::Rotator LimitViewRotation(Object::Rotator LimitViewRotation, float LimitViewPitchMin, float LimitViewPitchMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Tank.LimitViewRotation");
			byte params[32] = { NULL };
			*(Object::Rotator*)&params[0] = LimitViewRotation;
			*(float*)&params[12] = LimitViewPitchMin;
			*(float*)&params[16] = LimitViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
