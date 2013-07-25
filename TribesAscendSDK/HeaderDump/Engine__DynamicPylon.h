#pragma once
#include "Engine__Pylon.h"
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
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'RebuildDynamicEdges'
		// Here lies the not-yet-implemented method 'FlushDynamicEdges'
		// Here lies the not-yet-implemented method 'StartedMoving'
		// Here lies the not-yet-implemented method 'StoppedMoving'
	};
}
#undef ADD_VAR
