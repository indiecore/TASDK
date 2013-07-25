#pragma once
#include "Engine__Sequence.h"
#include "Engine__PrefabInstance.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PrefabSequence." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PrefabSequence : public Sequence
	{
	public:
		ADD_OBJECT(PrefabInstance, OwnerPrefab)
		// Here lies the not-yet-implemented method 'SetOwnerPrefab'
		// Here lies the not-yet-implemented method 'GetOwnerPrefab'
	};
}
#undef ADD_OBJECT
