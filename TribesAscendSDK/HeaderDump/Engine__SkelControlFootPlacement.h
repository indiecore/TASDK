#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlFootPlacement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkelControlFootPlacement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlFootPlacement : public SkelControlLimb
	{
	public:
		ADD_VAR(::FloatProperty, MaxFootOrientAdjust, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDownAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxUpAdjustment, 0xFFFFFFFF)
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
