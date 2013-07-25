#pragma once
#include "Engine__SequenceAction.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_SpawnProjectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_SpawnProjectile : public SequenceAction
	{
	public:
		ADD_OBJECT(ScriptClass, ProjectileClass)
		// Here lies the not-yet-implemented method 'Activated'
	};
}
#undef ADD_OBJECT
