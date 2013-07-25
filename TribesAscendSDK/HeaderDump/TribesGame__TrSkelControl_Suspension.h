#pragma once
#include "Engine__SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSkelControl_Suspension." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSkelControl_Suspension : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::IntProperty, WheelIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentRot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRotRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinRot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotIgnore, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinTrans, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTrans, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransIgnore, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bApplyTranslation, 0x2)
		ADD_VAR(::BoolProperty, m_bApplyRotation, 0x1)
	};
}
#undef ADD_VAR
