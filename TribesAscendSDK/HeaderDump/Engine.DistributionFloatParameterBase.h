#pragma once
#include "Engine.DistributionFloatConstant.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatParameterBase : public DistributionFloatConstant
	{
	public:
		enum DistributionParamMode : byte
		{
			DPM_Normal = 0,
			DPM_Abs = 1,
			DPM_Direct = 2,
			DPM_MAX = 3,
		};
		ADD_STRUCT(DistributionFloatParameterBase::DistributionParamMode, ParamMode, 108)
		ADD_STRUCT(ScriptName, ParameterName, 84)
		ADD_STRUCT(float, MaxOutput, 104)
		ADD_STRUCT(float, MinOutput, 100)
		ADD_STRUCT(float, MaxInput, 96)
		ADD_STRUCT(float, MinInput, 92)
	};
}
#undef ADD_STRUCT
