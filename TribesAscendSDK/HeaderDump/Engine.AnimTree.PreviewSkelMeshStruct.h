#pragma once
#include "Engine.SkeletalMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimTree.PreviewSkelMeshStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AnimTree.PreviewSkelMeshStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PreviewSkelMeshStruct
	{
	public:
		ADD_OBJECT(SkeletalMesh, PreviewSkelMesh)
		ADD_VAR(::NameProperty, DisplayName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
