#pragma once
#include "Engine.SkeletalMeshActorSpawnable.h"
#include "Engine.MaterialInstanceConstant.h"
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
	class TrDeployableHologram : public SkeletalMeshActorSpawnable
	{
	public:
		ADD_STRUCT(int, m_nOldInvalidDeployReason, 544)
		ADD_OBJECT(MaterialInstanceConstant, m_RuntimeMIC, 540)
		ADD_OBJECT(MaterialInstanceConstant, m_HologramMaterial, 536)
		void SetValidDeployableLocation(bool bValidLocation, int InvalidDeployReason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableHologram.SetValidDeployableLocation");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bValidLocation;
			*(int*)&params[4] = InvalidDeployReason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAllMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableHologram.ClearAllMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableHologram.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableHologram.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(ScriptClass* DeployableClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableHologram.Init");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DeployableClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
