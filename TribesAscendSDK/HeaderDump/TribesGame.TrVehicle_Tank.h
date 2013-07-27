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
		ADD_STRUCT(Rotator, GunnerWeaponRotation, 3224)
		ADD_STRUCT(Vector, GunnerFlashLocation, 3212)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114712);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleWeaponFireEffects(Vector HitLocation, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114716);
			byte params[16] = { NULL };
			*(Vector*)params = HitLocation;
			*(int*)&params[12] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessViewRotationBasedOnSeat(int SeatIndex, float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114722);
			byte params[32] = { NULL };
			*(int*)params = SeatIndex;
			*(float*)&params[4] = DeltaTime;
			*(Rotator*)&params[8] = out_ViewRotation;
			*(Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[8];
			out_DeltaRot = *(Rotator*)&params[20];
		}
		Rotator LimitViewRotation(Rotator LimitViewRotation, float LimitViewPitchMin, float LimitViewPitchMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114732);
			byte params[32] = { NULL };
			*(Rotator*)params = LimitViewRotation;
			*(float*)&params[12] = LimitViewPitchMin;
			*(float*)&params[16] = LimitViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
