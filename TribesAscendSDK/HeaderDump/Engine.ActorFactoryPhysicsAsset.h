#pragma once
#include "Engine.ActorFactory.h"
#include "Core.Object.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.PhysicsAsset.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class ActorFactoryPhysicsAsset : public ActorFactory
	{
	public:
		ADD_STRUCT(Object::Vector, DrawScale3D, 116)
		ADD_STRUCT(Object::Vector, InitialVelocity, 104)
		ADD_BOOL(bCastDynamicShadow, 100, 0x10)
		ADD_BOOL(bUseCompartment, 100, 0x8)
		ADD_BOOL(bNotifyRigidBodyCollision, 100, 0x4)
		ADD_BOOL(bDamageAppliesImpulse, 100, 0x2)
		ADD_BOOL(bStartAwake, 100, 0x1)
		ADD_OBJECT(SkeletalMesh, SkeletalMesh, 96)
		ADD_OBJECT(PhysicsAsset, PhysicsAsset, 92)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
