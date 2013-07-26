#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModuleLocationBoneSocket.LocationBoneSocketInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleModuleLocationBoneSocket.LocationBoneSocketInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LocationBoneSocketInfo
	{
	public:
		ADD_STRUCT(::VectorProperty, Offset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneSocketName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
