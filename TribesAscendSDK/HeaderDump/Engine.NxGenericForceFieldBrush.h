#pragma once
#include "Engine.Projectile.h"
#include "Engine.Volume.h"
#include "Core.Object.h"
#include "Engine.PrimitiveComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceFieldBrush : public Volume
	{
	public:
		enum FFB_ForceFieldCoordinates : byte
		{
			FFB_CARTESIAN = 0,
			FFB_SPHERICAL = 1,
			FFB_CYLINDRICAL = 2,
			FFB_TOROIDAL = 3,
			FFB_MAX = 4,
		};
		ADD_STRUCT(ScriptArray<Object::Pointer>, ConvexMeshes, 684)
		ADD_STRUCT(ScriptArray<Object::Pointer>, ExclusionShapes, 696)
		ADD_STRUCT(ScriptArray<Object::Pointer>, ExclusionShapePoses, 708)
		ADD_STRUCT(Object::Pointer, LinearKernel, 720)
		ADD_STRUCT(Object::Pointer, ForceField, 680)
		ADD_STRUCT(float, TorusRadius, 676)
		ADD_STRUCT(Vector, FalloffQuadratic, 664)
		ADD_STRUCT(Vector, FalloffLinear, 652)
		ADD_STRUCT(Vector, Noise, 640)
		ADD_STRUCT(Vector, VelocityTarget, 628)
		ADD_STRUCT(Vector, VelocityMultiplierZ, 616)
		ADD_STRUCT(Vector, VelocityMultiplierY, 604)
		ADD_STRUCT(Vector, VelocityMultiplierX, 592)
		ADD_STRUCT(Vector, PositionTarget, 580)
		ADD_STRUCT(Vector, PositionMultiplierZ, 568)
		ADD_STRUCT(Vector, PositionMultiplierY, 556)
		ADD_STRUCT(Vector, PositionMultiplierX, 544)
		ADD_STRUCT(Vector, Constant, 532)
		ADD_STRUCT(NxGenericForceFieldBrush::FFB_ForceFieldCoordinates, Coordinates, 529)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, RBChannel, 528)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, CollideWithChannels, 524)
		ADD_STRUCT(int, ExcludeChannel, 520)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21311);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21312);
			byte params[8] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_STRUCT
