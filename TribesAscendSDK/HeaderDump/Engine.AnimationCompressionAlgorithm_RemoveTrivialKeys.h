#pragma once
#include "Engine.AnimationCompressionAlgorithm.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_RemoveTrivialKeys : public AnimationCompressionAlgorithm
	{
	public:
		ADD_STRUCT(float, MaxAngleDiff, 84)
		ADD_STRUCT(float, MaxPosDiff, 80)
	};
}
#undef ADD_STRUCT
