#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_HugGround." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_HugGround : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTranslationPerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZDistFromParentBone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XYDistFromParentBone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOppositeFromParent, 0x1)
		ADD_VAR(::NameProperty, ParentBone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredGroundDist, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
