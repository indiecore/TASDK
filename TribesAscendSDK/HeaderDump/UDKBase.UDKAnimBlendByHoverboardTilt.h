#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByHoverboardTilt : public AnimNodeBlendBase
	{
	public:
		ADD_STRUCT(ScriptName, UpperBodyName, 268)
		ADD_STRUCT(float, TiltYScale, 264)
		ADD_STRUCT(float, TiltDeadZone, 260)
		ADD_STRUCT(float, TiltScale, 256)
		ADD_STRUCT(Vector, UpVector, 244)
	};
}
#undef ADD_STRUCT
