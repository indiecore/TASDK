#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.Matrix.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty InstancedStaticMeshComponent.InstancedStaticMeshInstanceData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InstancedStaticMeshInstanceData
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, ShadowmapUVBias, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, LightmapUVBias, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, Transform, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
