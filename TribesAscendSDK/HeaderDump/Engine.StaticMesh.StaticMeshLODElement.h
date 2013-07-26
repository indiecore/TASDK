#pragma once
#include "Engine.MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " StaticMesh.StaticMeshLODElement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty StaticMesh.StaticMeshLODElement." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class StaticMeshLODElement
	{
	public:
		ADD_OBJECT(MaterialInterface, Material)
		ADD_VAR(::BoolProperty, bEnableShadowCasting, 0x1)
		ADD_VAR(::BoolProperty, bEnableCollision, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
