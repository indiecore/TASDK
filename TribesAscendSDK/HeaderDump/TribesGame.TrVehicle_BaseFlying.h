#pragma once
#include "TribesGame.TrVehicle.h"
#include "Core.Object.h"
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
	class TrVehicle_BaseFlying : public TrVehicle
	{
	public:
		class FlyingParticleEffects
		{
		public:
			ADD_OBJECT(ParticleSystem, ParticleTemplate, 12)
			ADD_STRUCT(ScriptName, SocketToAttach, 4)
			ADD_BOOL(bIsAttachedToBoost, 0, 0x1)
		};
		ADD_BOOL(m_bCanAutoLevelVehicle, 3288, 0x2)
		ADD_STRUCT(ScriptArray<TrVehicle_BaseFlying::FlyingParticleEffects>, LeftEngineParticles, 3212)
		ADD_STRUCT(ScriptArray<TrVehicle_BaseFlying::FlyingParticleEffects>, MidEngineParticles, 3224)
		ADD_STRUCT(ScriptArray<TrVehicle_BaseFlying::FlyingParticleEffects>, RightEngineParticles, 3236)
		ADD_STRUCT(ScriptArray<TrVehicle_BaseFlying::FlyingParticleEffects>, LeftContrailParticles, 3248)
		ADD_STRUCT(ScriptArray<TrVehicle_BaseFlying::FlyingParticleEffects>, RightContrailParticles, 3260)
		ADD_BOOL(m_bFreeLook, 3288, 0x1)
		ADD_STRUCT(float, m_fBoostThrustInvDuration, 3284)
		ADD_STRUCT(float, m_fBoostThrustBuildUp, 3280)
		ADD_STRUCT(float, m_fThrustInvDuration, 3276)
		ADD_STRUCT(float, m_fThrustBuildUp, 3272)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_BaseFlying.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateParticleSystems()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_BaseFlying.CreateParticleSystems");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInputs(float InForward, float InStrafe, float InUp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_BaseFlying.SetInputs");
			byte params[12] = { NULL };
			*(float*)&params[0] = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = InUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleCalcCamera(float DeltaTime, int SeatIndex, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, Object::Vector& CamStart, bool bPivotOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_BaseFlying.VehicleCalcCamera");
			byte params[48] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(int*)&params[4] = SeatIndex;
			*(Object::Vector*)&params[8] = out_CamLoc;
			*(Object::Rotator*)&params[20] = out_CamRot;
			*(Object::Vector*)&params[32] = CamStart;
			*(bool*)&params[44] = bPivotOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[8];
			out_CamRot = *(Object::Rotator*)&params[20];
			CamStart = *(Object::Vector*)&params[32];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
