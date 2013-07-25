#pragma once
#include "Engine.Pylon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DynamicPylon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DynamicPylon : public Pylon
	{
	public:
		ADD_VAR(::BoolProperty, bMoving, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicPylon.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RebuildDynamicEdges()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicPylon.RebuildDynamicEdges");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlushDynamicEdges()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicPylon.FlushDynamicEdges");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartedMoving()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicPylon.StartedMoving");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoppedMoving()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicPylon.StoppedMoving");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
