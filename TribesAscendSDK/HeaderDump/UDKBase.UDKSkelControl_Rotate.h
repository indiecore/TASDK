#pragma once
#include "Engine.SkelControlSingleBone.h"
#include "Core.Object.Rotator.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKSkelControl_Rotate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_Rotate : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(::RotatorProperty, DesiredBoneRotationRate, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, DesiredBoneRotation, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
