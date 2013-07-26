#pragma once
#include "TribesGame.TrObjectPool.TracerCacheInfo.h"
#include "Engine.Actor.h"
#include "TribesGame.TrProj_Tracer.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrObjectPool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrObjectPool : public Actor
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<TracerCacheInfo>, m_TracerCache, 0xFFFFFFFF)
		class TrProj_Tracer* GetTracer(byte TracerType, byte ActiveReloadTier, Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.GetTracer");
			byte* params = (byte*)malloc(30);
			*params = TracerType;
			*(params + 1) = ActiveReloadTier;
			*(Vector*)(params + 4) = SpawnLocation;
			*(Rotator*)(params + 16) = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 28);
			free(params);
			return returnVal;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreatePools()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.CreatePools");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanUpPools()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.CleanUpPools");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateTracers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.CreateTracers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupTracers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.CleanupTracers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateTracer(byte TracerType, ScriptClass* TracerClass, int Idx, bool bForceCreate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrObjectPool.CreateTracer");
			byte* params = (byte*)malloc(13);
			*params = TracerType;
			*(ScriptClass**)(params + 4) = TracerClass;
			*(int*)(params + 8) = Idx;
			*(bool*)(params + 12) = bForceCreate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_STRUCT
