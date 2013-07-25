#pragma once
#include "Engine.InterpTrackLinearColorBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackLinearColorProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackLinearColorProp : public InterpTrackLinearColorBase
	{
	public:
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
