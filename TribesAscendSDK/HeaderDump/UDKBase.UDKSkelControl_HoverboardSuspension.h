#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_HoverboardSuspension." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_HoverboardSuspension : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::FloatProperty, CurrentRot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRotRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinTrans, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTrans, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransIgnore, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
