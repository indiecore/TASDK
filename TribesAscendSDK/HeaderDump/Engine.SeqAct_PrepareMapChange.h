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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_PrepareMapChange : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, InitiallyLoadedSecondaryLevelNames, 256)
		ADD_BOOL(bStatusIsOk, 268, 0x2)
		ADD_BOOL(bIsHighPriority, 268, 0x1)
		ADD_STRUCT(ScriptName, MainLevelName, 248)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
