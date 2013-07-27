#pragma once
#include "Engine.SoundNode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeConcatenator : public SoundNode
	{
	public:
		ADD_STRUCT(ScriptArray<float>, InputVolume, 76)
	};
}
#undef ADD_STRUCT
