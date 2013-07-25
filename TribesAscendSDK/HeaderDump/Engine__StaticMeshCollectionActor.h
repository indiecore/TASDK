#pragma once
#include "Engine__StaticMeshActorBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.StaticMeshCollectionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class StaticMeshCollectionActor : public StaticMeshActorBase
	{
	public:
		ADD_VAR(::IntProperty, MaxStaticMeshComponents, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
