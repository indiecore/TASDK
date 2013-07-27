#pragma once
#include "Engine.SeqAct_Latent.h"
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
namespace UnrealScript
{
	class SeqAct_LevelStreamingBase : public SeqAct_Latent
	{
	public:
		ADD_BOOL(bShouldBlockOnLoad, 248, 0x2)
		ADD_BOOL(bMakeVisibleAfterLoad, 248, 0x1)
	};
}
#undef ADD_BOOL
