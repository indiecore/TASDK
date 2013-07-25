#pragma once
#include "TribesGame.TrProjectile.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_CallInBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_CallInBase : public TrProjectile
	{
	public:
		ADD_STRUCT(::VectorProperty, r_TargetLocation, 0xFFFFFFFF)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_CallInBase.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool EffectIsRelevant(Vector SpawnLocation, bool bForceDedicated, float VisibleCullDistance, float HiddenCullDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_CallInBase.EffectIsRelevant");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = SpawnLocation;
			*(bool*)(params + 12) = bForceDedicated;
			*(float*)(params + 16) = VisibleCullDistance;
			*(float*)(params + 20) = HiddenCullDistance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
