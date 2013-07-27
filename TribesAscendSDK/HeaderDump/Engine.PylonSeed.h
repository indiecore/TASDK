#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PylonSeed : public Actor
	{
	public:
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_NavMeshPathObject, 476)
	};
}
#undef ADD_STRUCT
