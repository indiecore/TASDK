#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InteractiveFoliageComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InteractiveFoliageComponent : public StaticMeshComponent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FoliageSceneProxy, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
