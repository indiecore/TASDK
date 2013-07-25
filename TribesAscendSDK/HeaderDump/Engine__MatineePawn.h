#pragma once
#include "Engine__Pawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MatineePawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MatineePawn : public Pawn
	{
	public:
		ADD_OBJECT(SkeletalMesh, PreviewMesh)
	};
}
#undef ADD_OBJECT
