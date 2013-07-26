#pragma once
#include "Core.Object.Vector.h"
#include "GameFramework.GameSkelCtrl_Recoil.RecoilParams.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameSkelCtrl_Recoil.RecoilDef." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameSkelCtrl_Recoil.RecoilDef." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RecoilDef
	{
	public:
		ADD_STRUCT(::VectorProperty, LocOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RecoilParams>, LocParams, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocSinOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocFrequency, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocAmplitude, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, RotOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RecoilParams>, RotParams, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RotSinOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RotFrequency, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RotAmplitude, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeToGo, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
