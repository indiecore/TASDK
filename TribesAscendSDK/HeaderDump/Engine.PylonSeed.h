#pragma once
#include "Engine.Actor.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PylonSeed." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PylonSeed : public Actor
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IInterface_NavMeshPathObject, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
