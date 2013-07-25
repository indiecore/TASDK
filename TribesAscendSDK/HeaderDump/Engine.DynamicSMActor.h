#pragma once
#include "Engine.Actor.h"
#include "Engine.MaterialInterface.h"
#include "Engine.StaticMesh.h"
#include "Engine.SeqAct_SetMesh.h"
#include "Engine.Pawn.h"
#include "Engine.SeqAct_SetMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DynamicSMActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DynamicSMActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DynamicSMActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DynamicSMActor : public Actor
	{
	public:
		ADD_STRUCT(::VectorProperty, ReplicatedMeshScale3D, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, ReplicatedMeshRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ReplicatedMeshTranslation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSafeBaseIfAsleep, 0x4)
		ADD_VAR(::BoolProperty, bPawnCanBaseOn, 0x2)
		ADD_VAR(::BoolProperty, bForceStaticDecals, 0x1)
		ADD_OBJECT(MaterialInterface, ReplicatedMaterial)
		ADD_OBJECT(StaticMesh, ReplicatedMesh)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetMesh(class SeqAct_SetMesh* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.OnSetMesh");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetMesh**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.OnSetMaterial");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetMaterial**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetStaticMesh(class StaticMesh* NewMesh, Vector NewTranslation, Rotator NewRotation, Vector NewScale3D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.SetStaticMesh");
			byte* params = (byte*)malloc(40);
			*(class StaticMesh**)params = NewMesh;
			*(Vector*)(params + 4) = NewTranslation;
			*(Rotator*)(params + 16) = NewRotation;
			*(Vector*)(params + 28) = NewScale3D;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanBasePawn(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.CanBasePawn");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Attach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.Attach");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Detach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.Detach");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLightEnvironmentToNotBeDynamic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.SetLightEnvironmentToNotBeDynamic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
