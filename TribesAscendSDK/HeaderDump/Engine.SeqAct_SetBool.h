#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
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
	class SeqAct_SetBool : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_BOOL(DefaultValue, 232, 0x1)
	};
}
#undef ADD_BOOL
