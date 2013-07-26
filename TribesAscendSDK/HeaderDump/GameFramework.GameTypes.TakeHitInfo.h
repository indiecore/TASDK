#pragma once
#include "Core.Object.Vector.h"
#include "Engine.Pawn.h"
#include "Engine.PhysicalMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameTypes.TakeHitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameTypes.TakeHitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameTypes.TakeHitInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TakeHitInfo
	{
	public:
		ADD_STRUCT(::VectorProperty, HitLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Momentum, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DamageType)
		ADD_OBJECT(Pawn, InstigatedBy)
		ADD_VAR(::ByteProperty, HitBoneIndex, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, PhysicalMaterial)
		ADD_VAR(::FloatProperty, Damage, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RadialDamageOrigin, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
