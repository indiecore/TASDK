#pragma once
#include "Engine.Sequence.h"
#include "Engine.PrefabInstance.h"
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
		void SetOwnerPrefab(class PrefabInstance* InOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrefabSequence.SetOwnerPrefab");
			byte* params = (byte*)malloc(4);
			*(class PrefabInstance**)params = InOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PrefabInstance* GetOwnerPrefab()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrefabSequence.GetOwnerPrefab");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PrefabInstance**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
