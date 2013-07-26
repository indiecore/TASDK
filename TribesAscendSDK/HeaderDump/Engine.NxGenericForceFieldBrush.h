#pragma once
#include "Engine.Projectile.h"
#include "Engine.Volume.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Vector.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxGenericForceFieldBrush." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxGenericForceFieldBrush." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceFieldBrush : public Volume
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, LinearKernel, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ForceField, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TorusRadius, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FalloffQuadratic, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FalloffLinear, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Noise, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityTarget, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityMultiplierZ, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityMultiplierY, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityMultiplierX, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionTarget, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionMultiplierZ, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionMultiplierY, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionMultiplierX, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Constant, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Coordinates, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RBChannel, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RBCollisionChannelContainer>, CollideWithChannels, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ExcludeChannel, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxGenericForceFieldBrush.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxGenericForceFieldBrush.StopsProjectile");
			byte* params = (byte*)malloc(8);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
