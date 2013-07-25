#pragma once
#include "Engine.KActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KActorSpawnable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KActorSpawnable : public KActor
	{
	public:
		ADD_VAR(::BoolProperty, bScalingToZero, 0x2)
		ADD_VAR(::BoolProperty, bRecycleScaleToZero, 0x1)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecycleInternal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.RecycleInternal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetComponents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.KActorSpawnable.ResetComponents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
