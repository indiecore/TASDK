#pragma once
#include "Engine__SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSkelControl_JetThruster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSkelControl_JetThruster : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::FloatProperty, DesiredStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxForwardVelocity, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'TickSkelControl'
	};
}
#undef ADD_VAR
