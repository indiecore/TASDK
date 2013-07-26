#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKPawn.UTTakeHitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKPawn.UTTakeHitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKPawn.UTTakeHitInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTakeHitInfo
	{
	public:
		ADD_VAR(::BoolProperty, m_bDamagedSelf, 0x1)
		ADD_VAR(::NameProperty, HitBone, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DamageType)
		ADD_STRUCT(::VectorProperty, Momentum, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HitLocation, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Damage, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
