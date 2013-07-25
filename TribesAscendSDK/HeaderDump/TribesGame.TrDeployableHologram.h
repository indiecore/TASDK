#pragma once
#include "Engine.SkeletalMeshActorSpawnable.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployableHologram." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployableHologram." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployableHologram : public SkeletalMeshActorSpawnable
	{
	public:
		ADD_VAR(::IntProperty, m_nOldInvalidDeployReason, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_RuntimeMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_HologramMaterial)
		void SetValidDeployableLocation(bool bValidLocation, int InvalidDeployReason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableHologram.SetValidDeployableLocation");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bValidLocation;
			*(int*)(params + 4) = InvalidDeployReason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeployableClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
