#pragma once
#include "Engine__SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSkelControl_CicadaEngine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSkelControl_CicadaEngine : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::IntProperty, DesiredPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastThrust, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxVelocityPitchRateMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BackPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForwardPitch, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
