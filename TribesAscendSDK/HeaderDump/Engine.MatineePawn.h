#pragma once
#include "Engine.Pawn.h"
#include "Engine.SkeletalMesh.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MatineePawn : public Pawn
	{
	public:
		ADD_OBJECT(SkeletalMesh, PreviewMesh, 1144)
	};
}
#undef ADD_OBJECT
