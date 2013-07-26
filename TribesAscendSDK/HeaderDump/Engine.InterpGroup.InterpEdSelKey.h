#pragma once
#include "Engine.InterpTrack.h"
#include "Engine.InterpGroup.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpGroup.InterpEdSelKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty InterpGroup.InterpEdSelKey." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpEdSelKey
	{
	public:
		ADD_VAR(::FloatProperty, UnsnappedPosition, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, KeyIndex, 0xFFFFFFFF)
		ADD_OBJECT(InterpTrack, Track)
		ADD_OBJECT(InterpGroup, Group)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
