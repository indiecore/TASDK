#pragma once
#include "Engine.InterpTrackFloatBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackFloatProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackFloatProp : public InterpTrackFloatBase
	{
	public:
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
