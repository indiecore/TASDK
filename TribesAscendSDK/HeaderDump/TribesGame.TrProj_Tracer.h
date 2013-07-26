#pragma once
#include "TribesGame.TrProjectile.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Tracer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_Tracer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_Tracer : public TrProjectile
	{
	public:
		ADD_STRUCT(::VectorProperty, m_vTracerDrawScale3D, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vInitialFrameOfRefVelocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vDestinationLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMeshScaleDownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bScalingDown, 0x2)
		ADD_VAR(::BoolProperty, m_bScaledUp, 0x1)
		ADD_VAR(::FloatProperty, m_fMeshScaleUpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccelRate, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CalcTracerAccel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.CalcTracerAccel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitTracer(Vector Start, Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.InitTracer");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Tracer.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
