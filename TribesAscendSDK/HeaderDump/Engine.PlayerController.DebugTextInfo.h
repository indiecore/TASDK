#pragma once
#include "Engine.Actor.h"
#include "Engine.Font.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PlayerController.DebugTextInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PlayerController.DebugTextInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PlayerController.DebugTextInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DebugTextInfo
	{
	public:
		ADD_OBJECT(Actor, SrcActor)
		ADD_VAR(::FloatProperty, TimeRemaining, 0xFFFFFFFF)
		ADD_OBJECT(Font, Font)
		ADD_VAR(::BoolProperty, bAbsoluteLocation, 0x1)
		ADD_STRUCT(::VectorProperty, SrcActorOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SrcActorDesiredOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bKeepAttachedToActor, 0x2)
		ADD_STRUCT(::VectorProperty, OrigActorLocation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, TextColor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DebugText, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
