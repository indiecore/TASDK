#pragma once
#include "Engine.ApexClothingAsset.h"
#include "Engine.ActorFactorySkeletalMesh.h"
#include "Engine.PrimitiveComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ActorFactoryApexClothing : public ActorFactorySkeletalMesh
	{
	public:
		ADD_STRUCT(ScriptArray<class ApexClothingAsset*>, ClothingAssets, 108)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, ClothingRBCollideWithChannels, 124)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, ClothingRBChannel, 120)
	};
}
#undef ADD_STRUCT
