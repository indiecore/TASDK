#pragma once
#include "Engine.InterpTrackLinearColorBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackLinearColorProp : public InterpTrackLinearColorBase
	{
	public:
		ADD_STRUCT(ScriptName, PropertyName, 148)
	};
}
#undef ADD_STRUCT
