#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "TribesGame.TrDeployable.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_ThrowDeployable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_ThrowDeployable : public TrProj_Mine
	{
	public:
		ADD_OBJECT(ScriptClass, m_DeployableToSpawn)
		class TrDeployable* SpawnDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.SpawnDeployable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDeployable**)params;
			free(params);
			return returnVal;
		}
		void DestroyOldestOverLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.DestroyOldestOverLimit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetMaxDeployedLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.GetMaxDeployedLimit");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void ArmedTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_ThrowDeployable.ArmedTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
