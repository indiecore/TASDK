#pragma once
#include "Engine__SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControl_CCD_IK." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkelControl_CCD_IK." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControl_CCD_IK : public SkelControlBase
	{
	public:
		ADD_VAR(::FloatProperty, MaxAngleSteps, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNoTurnOptimization, 0x2)
		ADD_VAR(::BoolProperty, bStartFromTail, 0x1)
		ADD_VAR(::FloatProperty, Precision, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IterationsCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPerBoneIterations, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumBones, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EffectorTranslationFromBone, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EffectorSpaceBoneName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EffectorLocationSpace, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EffectorLocation, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
