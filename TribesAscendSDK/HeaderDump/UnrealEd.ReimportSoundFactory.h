#pragma once
#include "UnrealEd.SoundFactory.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ReimportSoundFactory : public SoundFactory
	{
	public:
		ADD_BOOL(bAutoCreateCue, 112, 0x1)
		ADD_BOOL(bIncludeAttenuationNode, 116, 0x1)
		ADD_BOOL(bIncludeModulatorNode, 124, 0x1)
		ADD_BOOL(bIncludeLoopingNode, 120, 0x1)
		ADD_STRUCT(float, CueVolume, 128)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
