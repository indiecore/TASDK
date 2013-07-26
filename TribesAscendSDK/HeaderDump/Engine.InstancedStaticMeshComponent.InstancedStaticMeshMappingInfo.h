#pragma once
#include "Engine.ShadowMap2D.h"
#include "Core.Object.Pointer.h"
#include "Engine.Texture2D.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty InstancedStaticMeshComponent.InstancedStaticMeshMappingInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty InstancedStaticMeshComponent.InstancedStaticMeshMappingInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InstancedStaticMeshMappingInfo
	{
	public:
		ADD_OBJECT(ShadowMap2D, ShadowmapTexture)
		ADD_OBJECT(Texture2D, LightmapTexture)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, LightMap, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Mapping, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
