#pragma once
#include "Engine.SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControl_TwistBone." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControl_TwistBone : public SkelControlBase
	{
	public:
		ADD_VAR(::FloatProperty, TwistAngleScale, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SourceBoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
