#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlLookAt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkelControlLookAt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlLookAt : public SkelControlBase
	{
	public:
		ADD_VAR(::IntProperty, ControlBoneIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCalcTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BaseBonePos, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, BaseLookDir, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LimitLookDir, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LookAtAlphaBlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookAtAlphaTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookAtAlpha, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AllowRotationOtherBoneName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeadZoneAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxAngle, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ActorSpaceLookAtTarget, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DesiredTargetLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, TargetLocationInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllowRotationZ, 0x400)
		ADD_VAR(::BoolProperty, bAllowRotationY, 0x200)
		ADD_VAR(::BoolProperty, bAllowRotationX, 0x100)
		ADD_VAR(::BoolProperty, bShowLimit, 0x80)
		ADD_VAR(::BoolProperty, bNotifyBeyondLimit, 0x40)
		ADD_VAR(::BoolProperty, bDisableBeyondLimit, 0x20)
		ADD_VAR(::BoolProperty, bLimitBasedOnRefPose, 0x10)
		ADD_VAR(::BoolProperty, bEnableLimit, 0x8)
		ADD_VAR(::BoolProperty, bInvertUpAxis, 0x4)
		ADD_VAR(::BoolProperty, bDefineUpAxis, 0x2)
		ADD_VAR(::BoolProperty, bInvertLookAtAxis, 0x1)
		ADD_VAR(::NameProperty, TargetSpaceBoneName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AllowRotationSpace, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, UpAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LookAtAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TargetLocationSpace, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetLocation, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
