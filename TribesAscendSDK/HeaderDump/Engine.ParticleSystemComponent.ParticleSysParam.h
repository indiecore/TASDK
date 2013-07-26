#pragma once
#include "Engine.MaterialInterface.h"
#include "Engine.Actor.h"
#include "Core.Object.Color.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleSystemComponent.ParticleSysParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleSystemComponent.ParticleSysParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty ParticleSystemComponent.ParticleSysParam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleSysParam
	{
	public:
		ADD_OBJECT(MaterialInterface, Material)
		ADD_OBJECT(Actor, Actor)
		ADD_STRUCT(::NonArithmeticProperty<Color>, Color, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Vector_Low, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Vector, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scalar_Low, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scalar, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ParamType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Name, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
