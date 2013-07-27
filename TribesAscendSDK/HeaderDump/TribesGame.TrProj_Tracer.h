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
		ADD_STRUCT(Object::Vector, m_vTracerDrawScale3D, 824)
		ADD_STRUCT(Object::Vector, m_vInitialFrameOfRefVelocity, 864)
		ADD_STRUCT(Object::Vector, m_vDestinationLoc, 852)
		ADD_STRUCT(float, m_fMeshScaleDownTime, 848)
		ADD_STRUCT(float, m_fCurScale, 844)
		ADD_BOOL(m_bScalingDown, 840, 0x2)
		ADD_BOOL(m_bScaledUp, 840, 0x1)
		ADD_STRUCT(float, m_fMeshScaleUpTime, 836)
		ADD_STRUCT(float, m_fAccelRate, 820)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CalcTracerAccel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.CalcTracerAccel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitTracer(Object::Vector Start, Object::Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.InitTracer");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillProjectile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.KillProjectile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScaleDownFinishedNotify()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.ScaleDownFinishedNotify");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScaleUpFinishedNotify()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.ScaleUpFinishedNotify");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OutsideWorldBounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.OutsideWorldBounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.Explode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WakeProjectile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.WakeProjectile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessTouch(class Actor* Other, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.ProcessTouch");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
