#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoal_Filter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_Filter : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumNodesProcessed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumNodesThrownOut, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowDebug, 0x1)
	};
}
#undef ADD_VAR
