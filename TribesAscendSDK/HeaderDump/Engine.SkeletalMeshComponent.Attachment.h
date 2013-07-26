#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMeshComponent.Attachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SkeletalMeshComponent.Attachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Attachment
	{
	public:
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RelativeLocation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, RelativeRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RelativeScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
