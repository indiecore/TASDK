#pragma once
#include "Engine.InterpTrack.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackBoolProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackBoolProp : public InterpTrack
	{
	public:
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
