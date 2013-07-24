#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameSkelCtrl_Recoil." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameSkelCtrl_Recoil." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameSkelCtrl_Recoil : public SkelControlBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'Aim'!
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.GameSkelCtrl_Recoil.RecoilDef' for the property named 'Recoil'!
		ADD_VAR(::BoolProperty, bApplyControl, 0x8)
		ADD_VAR(::BoolProperty, bOldPlayRecoil, 0x4)
		ADD_VAR(::BoolProperty, bPlayRecoil, 0x2)
		ADD_VAR(::BoolProperty, bBoneSpaceRecoil, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
