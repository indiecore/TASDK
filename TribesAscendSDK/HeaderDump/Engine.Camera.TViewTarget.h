#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.TPOV.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Camera.TViewTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Camera.TViewTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Camera.TViewTarget." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TViewTarget
	{
	public:
		ADD_OBJECT(Actor, Target)
		ADD_STRUCT(::NonArithmeticProperty<TPOV>, POV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AspectRatio, 0xFFFFFFFF)
		ADD_OBJECT(Controller, Controller)
		ADD_OBJECT(PlayerReplicationInfo, PRI)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
