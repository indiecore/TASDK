#pragma once
#include "TribesGame.TrProjectile.h"
#include "Engine.Actor.h"
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
namespace UnrealScript
{
	class TrProj_Tracer : public TrProjectile
	{
	public:
		ADD_STRUCT(Vector, m_vTracerDrawScale3D, 824)
		ADD_STRUCT(Vector, m_vInitialFrameOfRefVelocity, 864)
		ADD_STRUCT(Vector, m_vDestinationLoc, 852)
		ADD_STRUCT(float, m_fMeshScaleDownTime, 848)
		ADD_STRUCT(float, m_fCurScale, 844)
		ADD_BOOL(m_bScalingDown, 840, 0x2)
		ADD_BOOL(m_bScaledUp, 840, 0x1)
		ADD_STRUCT(float, m_fMeshScaleUpTime, 836)
		ADD_STRUCT(float, m_fAccelRate, 820)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108209);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108210);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CalcTracerAccel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108212);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitTracer(Vector Start, Vector End)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108214);
			byte params[24] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillProjectile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108219);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScaleDownFinishedNotify()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108220);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScaleUpFinishedNotify()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108221);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OutsideWorldBounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108222);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108223);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108226);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108229);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108230);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WakeProjectile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108231);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108232);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
