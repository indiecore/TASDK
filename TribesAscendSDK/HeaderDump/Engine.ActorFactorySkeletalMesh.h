#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.AnimSet.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorFactorySkeletalMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactorySkeletalMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactorySkeletalMesh : public ActorFactory
	{
	public:
		ADD_VAR(::NameProperty, AnimSequenceName, 0xFFFFFFFF)
		ADD_OBJECT(AnimSet, AnimSet)
		ADD_OBJECT(SkeletalMesh, SkeletalMesh)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
