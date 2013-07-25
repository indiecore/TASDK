#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.StaticMesh.h"
#include "Engine.SkeletalMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_SetMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetMesh : public SequenceAction
	{
	public:
		ADD_VAR(::ByteProperty, MeshType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsAllowedToMove, 0x1)
		ADD_VAR(::BoolProperty, bAllowDecalsToReattach, 0x2)
		ADD_OBJECT(StaticMesh, NewStaticMesh)
		ADD_OBJECT(SkeletalMesh, NewSkeletalMesh)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
