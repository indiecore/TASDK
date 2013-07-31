#pragma once
#include "Engine.PBRuleNodeBase.h"
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
	class PBRuleNodeVariation : public PBRuleNodeBase
	{
	public:
		ADD_BOOL(bVariationOfScopeOnLeft, 104, 0x1)
	};
}
#undef ADD_BOOL
