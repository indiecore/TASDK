#pragma once
#include "Core.Object.h"
#include "Engine.DistributionVectorConstant.h"
#include "Engine.DistributionFloatParameterBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DistributionVectorParameterBase : public DistributionVectorConstant
	{
	public:
		ADD_STRUCT(DistributionFloatParameterBase::DistributionParamMode, ParamModes, 156)
		ADD_STRUCT(Vector, MaxOutput, 144)
		ADD_STRUCT(Vector, MinOutput, 132)
		ADD_STRUCT(Vector, MaxInput, 120)
		ADD_STRUCT(Vector, MinInput, 108)
		ADD_STRUCT(ScriptName, ParameterName, 100)
	};
}
#undef ADD_STRUCT
