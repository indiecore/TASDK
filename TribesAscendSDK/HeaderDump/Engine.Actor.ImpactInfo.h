#pragma once
#include "Engine.Actor.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.TraceHitInfo.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Actor.ImpactInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Actor.ImpactInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ImpactInfo
	{
	public:
		ADD_OBJECT(Actor, HitActor)
		ADD_STRUCT(::VectorProperty, HitLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HitNormal, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RayDir, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartTrace, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TraceHitInfo>, HitInfo, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
