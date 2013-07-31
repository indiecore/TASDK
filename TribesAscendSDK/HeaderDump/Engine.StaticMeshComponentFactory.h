#pragma once
#include "Engine.MeshComponentFactory.h"
#include "Engine.StaticMesh.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class StaticMeshComponentFactory : public MeshComponentFactory
	{
	public:
		ADD_OBJECT(StaticMesh, StaticMesh, 76)
	};
}
#undef ADD_OBJECT
