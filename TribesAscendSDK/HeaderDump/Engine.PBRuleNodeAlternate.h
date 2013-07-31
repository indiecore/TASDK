#pragma once
#include "Engine.PBRuleNodeBase.h"
#include "Engine.ProcBuildingRuleset.h"
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
	class PBRuleNodeAlternate : public PBRuleNodeBase
	{
	public:
		ADD_BOOL(bEqualSizeAB, 116, 0x2)
		ADD_BOOL(bInvertPatternOrder, 116, 0x1)
		ADD_STRUCT(float, BMaxSize, 112)
		ADD_STRUCT(float, ASize, 108)
		ADD_STRUCT(ProcBuildingRuleset::EProcBuildingAxis, RepeatAxis, 104)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
