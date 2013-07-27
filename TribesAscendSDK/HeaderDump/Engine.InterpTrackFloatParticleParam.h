#pragma once
#include "Engine.InterpTrackFloatBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackFloatParticleParam : public InterpTrackFloatBase
	{
	public:
		ADD_STRUCT(ScriptName, ParamName, 148)
	};
}
#undef ADD_STRUCT
