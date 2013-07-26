#pragma once
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EmitterPool.EmitterBaseInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty EmitterPool.EmitterBaseInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty EmitterPool.EmitterBaseInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EmitterBaseInfo
	{
	public:
		ADD_VAR(::BoolProperty, bInheritBaseScale, 0x1)
		ADD_STRUCT(::RotatorProperty, RelativeRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RelativeLocation, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Base)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
