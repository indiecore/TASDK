#pragma once
#include "Engine__FracturedStaticMeshActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FracturedStaticMeshPart." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FracturedStaticMeshPart." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FracturedStaticMeshPart." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FracturedStaticMeshPart : public FracturedStaticMeshActor
	{
	public:
		ADD_VAR(::FloatProperty, LastImpactSoundTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentVibrationLevel, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OldVelocity, 0xFFFFFFFF
		ADD_VAR(::ByteProperty, AsleepRBChannel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FracPartGravScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PartPoolIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSpawnTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCompositeThatExplodesOnImpact, 0x4)
		ADD_VAR(::BoolProperty, bChangeRBChannelWhenAsleep, 0x2)
		ADD_VAR(::BoolProperty, bHasBeenRecycled, 0x1)
		ADD_OBJECT(FracturedStaticMeshActor, BaseFracturedMeshActor)
		ADD_VAR(::FloatProperty, DestroyPartRadiusFactor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
