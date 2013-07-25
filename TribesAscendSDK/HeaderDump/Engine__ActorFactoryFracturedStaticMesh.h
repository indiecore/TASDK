#pragma once
#include "Engine__ActorFactory.h"
#include "Engine__FracturedStaticMesh.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ActorFactoryFracturedStaticMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryFracturedStaticMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryFracturedStaticMesh : public ActorFactory
	{
	public:
		ADD_STRUCT(::VectorProperty, DrawScale3D, 0xFFFFFFFF
		ADD_OBJECT(FracturedStaticMesh, FracturedStaticMesh)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
