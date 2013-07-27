#pragma once
#include "Engine.Volume.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TestSplittingVolume : public Volume
	{
	public:
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_NavMeshPathObject, 520)
	};
}
#undef ADD_STRUCT
