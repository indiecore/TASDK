#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObject.TrTakeHitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TrObject.TrTakeHitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrObject.TrTakeHitInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTakeHitInfo
	{
	public:
		ADD_VAR(::IntProperty, Damage, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HitLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Momentum, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DamageType)
		ADD_VAR(::NameProperty, HitBone, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
