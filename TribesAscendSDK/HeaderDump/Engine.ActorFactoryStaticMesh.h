#pragma once
#include "Engine.ActorFactory.h"
#include "Core.Object.h"
#include "Engine.StaticMesh.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryStaticMesh : public ActorFactory
	{
	public:
		ADD_STRUCT(Vector, DrawScale3D, 96)
		ADD_OBJECT(StaticMesh, StaticMesh, 92)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
