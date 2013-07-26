#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PrimitiveComponent.RBCollisionChannelContainer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RBCollisionChannelContainer
	{
	public:
		ADD_VAR(::BoolProperty, Default, 0x1)
		ADD_VAR(::BoolProperty, Nothing, 0x2)
		ADD_VAR(::BoolProperty, Pawn, 0x4)
		ADD_VAR(::BoolProperty, Vehicle, 0x8)
		ADD_VAR(::BoolProperty, Water, 0x10)
		ADD_VAR(::BoolProperty, GameplayPhysics, 0x20)
		ADD_VAR(::BoolProperty, EffectPhysics, 0x40)
		ADD_VAR(::BoolProperty, Untitled1, 0x80)
		ADD_VAR(::BoolProperty, Untitled2, 0x100)
		ADD_VAR(::BoolProperty, Untitled3, 0x200)
		ADD_VAR(::BoolProperty, Untitled4, 0x400)
		ADD_VAR(::BoolProperty, Cloth, 0x800)
		ADD_VAR(::BoolProperty, FluidDrain, 0x1000)
		ADD_VAR(::BoolProperty, SoftBody, 0x2000)
		ADD_VAR(::BoolProperty, FracturedMeshPart, 0x4000)
		ADD_VAR(::BoolProperty, BlockingVolume, 0x8000)
		ADD_VAR(::BoolProperty, DeadPawn, 0x10000)
		ADD_VAR(::BoolProperty, Clothing, 0x20000)
		ADD_VAR(::BoolProperty, ClothingCollision, 0x40000)
	};
}
#undef ADD_VAR
