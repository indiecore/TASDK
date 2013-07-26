#pragma once
#include "Engine.StaticMesh.h"
#include "Engine.MaterialInterface.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGameReplicationInfo.MeshEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MeshEffect
	{
	public:
		ADD_OBJECT(StaticMesh, Mesh)
		ADD_OBJECT(MaterialInterface, Material)
	};
}
#undef ADD_OBJECT
