#pragma once
#include "TribesGame.TrProjectile.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrProj_CallInBase : public TrProjectile
	{
	public:
		ADD_STRUCT(Object::Vector, r_TargetLocation, 816)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_CallInBase.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EffectIsRelevant(Object::Vector SpawnLocation, bool bForceDedicated, float VisibleCullDistance, float HiddenCullDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_CallInBase.EffectIsRelevant");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = SpawnLocation;
			*(bool*)&params[12] = bForceDedicated;
			*(float*)&params[16] = VisibleCullDistance;
			*(float*)&params[20] = HiddenCullDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
	};
}
#undef ADD_STRUCT
