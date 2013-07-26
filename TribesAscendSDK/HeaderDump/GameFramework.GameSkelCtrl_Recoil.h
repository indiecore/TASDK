#pragma once
#include "Engine.SkelControlBase.h"
#include "Core.Object.Vector2D.h"
#include "GameFramework.GameSkelCtrl_Recoil.RecoilDef.h"
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
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Aim, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RecoilDef>, Recoil, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bApplyControl, 0x8)
		ADD_VAR(::BoolProperty, bOldPlayRecoil, 0x4)
		ADD_VAR(::BoolProperty, bPlayRecoil, 0x2)
		ADD_VAR(::BoolProperty, bBoneSpaceRecoil, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
