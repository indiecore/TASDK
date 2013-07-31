#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeExtractTopBottom : public PBRuleNodeBase
	{
	public:
		ADD_STRUCT(float, ExtractNotBottomZ, 116)
		ADD_STRUCT(float, ExtractBottomZ, 112)
		ADD_STRUCT(float, ExtractNotTopZ, 108)
		ADD_STRUCT(float, ExtractTopZ, 104)
	};
}
#undef ADD_STRUCT
