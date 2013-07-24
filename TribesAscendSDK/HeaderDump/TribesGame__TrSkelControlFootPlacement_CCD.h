#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSkelControlFootPlacement_CCD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrSkelControlFootPlacement_CCD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSkelControlFootPlacement_CCD : public SkelControl_CCD_IK
	{
	public:
		ADD_VAR(::FloatProperty, FootAdjustHeightLastTick, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffContactFootAdjustInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OnContactFootAdjustInterpSpeed, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FootUpDirLastTick, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, FootOrientInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxFootOrientAdjust, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDownAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxUpAdjustment, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFootOnGroundLastTick, 0x8)
		ADD_VAR(::BoolProperty, bOnlyEnableForUpAdjustment, 0x4)
		ADD_VAR(::BoolProperty, bOrientFootToGround, 0x2)
		ADD_VAR(::BoolProperty, bInvertFootUpAxis, 0x1)
		ADD_STRUCT(::RotatorProperty, FootRotOffset, 0xFFFFFFFF
		ADD_VAR(::ByteProperty, FootUpAxis, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FootOffset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
