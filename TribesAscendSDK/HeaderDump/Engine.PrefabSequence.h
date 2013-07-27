#pragma once
#include "Engine.Sequence.h"
#include "Engine.PrefabInstance.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class PrefabSequence : public Sequence
	{
	public:
		ADD_OBJECT(PrefabInstance, OwnerPrefab, 300)
		void SetOwnerPrefab(class PrefabInstance* InOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrefabSequence.SetOwnerPrefab");
			byte params[4] = { NULL };
			*(class PrefabInstance**)&params[0] = InOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PrefabInstance* GetOwnerPrefab()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrefabSequence.GetOwnerPrefab");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PrefabInstance**)&params[0];
		}
	};
}
#undef ADD_OBJECT
