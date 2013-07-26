#pragma once
#include "Engine.ActorFactorySkeletalMesh.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorFactoryApexClothing." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ActorFactoryApexClothing." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ActorFactoryApexClothing : public ActorFactorySkeletalMesh
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RBCollisionChannelContainer>, ClothingRBCollideWithChannels, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClothingRBChannel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
