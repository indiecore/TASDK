#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.WeaponEffectInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKVehicle.WeaponEffectInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WeaponEffectInfo
	{
	public:
		ADD_STRUCT(::VectorProperty, Scale3D, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Offset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SocketName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
