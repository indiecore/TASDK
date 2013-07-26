#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.ApexDestructibleAsset.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorFactoryApexDestructible." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ActorFactoryApexDestructible." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryApexDestructible." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryApexDestructible : public ActorFactory
	{
	public:
		ADD_OBJECT(ApexDestructibleAsset, DestructibleAsset)
		ADD_STRUCT(::NonArithmeticProperty<RBCollisionChannelContainer>, CollideWithChannels, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RBChannel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStartAwake, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
