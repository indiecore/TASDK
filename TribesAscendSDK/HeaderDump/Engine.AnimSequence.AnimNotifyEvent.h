#pragma once
#include "Engine.AnimNotify.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimSequence.AnimNotifyEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AnimSequence.AnimNotifyEvent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotifyEvent
	{
	public:
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
		ADD_OBJECT(AnimNotify, Notify)
		ADD_VAR(::NameProperty, Comment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
