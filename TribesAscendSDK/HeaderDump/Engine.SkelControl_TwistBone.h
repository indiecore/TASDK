#pragma once
#include "Engine.SkelControlBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SkelControl_TwistBone : public SkelControlBase
	{
	public:
		ADD_STRUCT(float, TwistAngleScale, 196)
		ADD_STRUCT(ScriptName, SourceBoneName, 188)
	};
}
#undef ADD_STRUCT
