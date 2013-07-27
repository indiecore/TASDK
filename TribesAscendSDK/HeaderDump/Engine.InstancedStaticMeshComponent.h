#pragma once
#include "Engine.StaticMeshComponent.h"
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
	class InstancedStaticMeshComponent : public StaticMeshComponent
	{
	public:
		struct InstancedStaticMeshInstanceData
		{
		public:
			ADD_STRUCT(Object::Vector2D, ShadowmapUVBias, 72)
			ADD_STRUCT(Object::Vector2D, LightmapUVBias, 64)
			ADD_STRUCT(Object::Matrix, Transform, 0)
		};
		struct InstancedStaticMeshMappingInfo
		{
		public:
			ADD_OBJECT(ShadowMap2D, ShadowmapTexture, 12)
			ADD_OBJECT(Texture2D, LightmapTexture, 8)
			ADD_STRUCT(Object::Pointer, LightMap, 4)
			ADD_STRUCT(Object::Pointer, Mapping, 0)
		};
		ADD_STRUCT(ScriptArray<InstancedStaticMeshComponent::InstancedStaticMeshInstanceData>, PerInstanceData, 608)
		ADD_STRUCT(ScriptArray<InstancedStaticMeshComponent::InstancedStaticMeshInstanceData>, PerInstanceSMData, 620)
		ADD_STRUCT(ScriptArray<InstancedStaticMeshComponent::InstancedStaticMeshMappingInfo>, CachedMappings, 640)
		ADD_STRUCT(int, InstancingRandomSeed, 652)
		ADD_STRUCT(int, ComponentJoinKey, 636)
		ADD_STRUCT(int, NumPendingLightmaps, 632)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
