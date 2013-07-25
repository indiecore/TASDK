#pragma once
#include "Engine__ActorFactory.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer' for the property named 'CollideWithChannels'!
		ADD_VAR(::ByteProperty, RBChannel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStartAwake, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
