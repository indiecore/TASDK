#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "TribesGame.TrDeployable.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_ThrowDeployable : public TrProj_Mine
	{
	public:
		ADD_OBJECT(ScriptClass, m_DeployableToSpawn, 900)
		class TrDeployable* SpawnDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.SpawnDeployable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDeployable**)&params[0];
		}
		void DestroyOldestOverLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.DestroyOldestOverLimit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetMaxDeployedLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.GetMaxDeployedLimit");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void ArmedTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.ArmedTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
