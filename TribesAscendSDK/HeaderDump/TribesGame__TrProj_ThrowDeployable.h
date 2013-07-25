#pragma once
#include "TribesGame__TrProj_Mine.h"
#include "TribesGame__TrDeployable.h"
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
		// Here lies the not-yet-implemented method 'SpawnDeployable'
		// Here lies the not-yet-implemented method 'DestroyOldestOverLimit'
		// Here lies the not-yet-implemented method 'GetMaxDeployedLimit'
		// Here lies the not-yet-implemented method 'ArmedTimer'
	};
}
#undef ADD_OBJECT
