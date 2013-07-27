#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.MaterialInterface.h"
#include "Engine.StaticMesh.h"
#include "Engine.SeqAct_SetMesh.h"
#include "Engine.Pawn.h"
#include "Engine.SeqAct_SetMaterial.h"
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
	class DynamicSMActor : public Actor
	{
	public:
		ADD_STRUCT(Object::Vector, ReplicatedMeshScale3D, 520)
		ADD_STRUCT(Object::Rotator, ReplicatedMeshRotation, 508)
		ADD_STRUCT(Object::Vector, ReplicatedMeshTranslation, 496)
		ADD_BOOL(bSafeBaseIfAsleep, 492, 0x4)
		ADD_BOOL(bPawnCanBaseOn, 492, 0x2)
		ADD_BOOL(bForceStaticDecals, 492, 0x1)
		ADD_OBJECT(MaterialInterface, ReplicatedMaterial, 488)
		ADD_OBJECT(StaticMesh, ReplicatedMesh, 484)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetMesh(class SeqAct_SetMesh* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.OnSetMesh");
			byte params[4] = { NULL };
			*(class SeqAct_SetMesh**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.OnSetMaterial");
			byte params[4] = { NULL };
			*(class SeqAct_SetMaterial**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetStaticMesh(class StaticMesh* NewMesh, Object::Vector NewTranslation, Object::Rotator NewRotation, Object::Vector NewScale3D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.SetStaticMesh");
			byte params[40] = { NULL };
			*(class StaticMesh**)&params[0] = NewMesh;
			*(Object::Vector*)&params[4] = NewTranslation;
			*(Object::Rotator*)&params[16] = NewRotation;
			*(Object::Vector*)&params[28] = NewScale3D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanBasePawn(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.CanBasePawn");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Attach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.Attach");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Detach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.Detach");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightEnvironmentToNotBeDynamic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicSMActor.SetLightEnvironmentToNotBeDynamic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
