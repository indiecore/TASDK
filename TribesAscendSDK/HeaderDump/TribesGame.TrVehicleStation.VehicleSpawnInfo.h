#pragma once
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrVehicleStation.VehicleSpawnInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TrVehicleStation.VehicleSpawnInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrVehicleStation.VehicleSpawnInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VehicleSpawnInfo
	{
	public:
		ADD_STRUCT(::RotatorProperty, m_rSpawnRotOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vSpawnLocOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxCount, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_VehicleClass)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
