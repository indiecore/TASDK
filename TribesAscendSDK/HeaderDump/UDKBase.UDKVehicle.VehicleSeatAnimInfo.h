#pragma once
#include "Engine.AnimTree.h"
#include "Engine.AnimSet.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.VehicleSeatAnimInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKVehicle.VehicleSeatAnimInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VehicleSeatAnimInfo
	{
	public:
		ADD_OBJECT(AnimTree, SeatAnimTree)
		ADD_OBJECT(AnimSet, SeatAnimSet)
		ADD_VAR(::IntProperty, TeamType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ArmorType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClearAnimSet, 0x4)
		ADD_VAR(::BoolProperty, bIsFactionDependent, 0x2)
		ADD_VAR(::BoolProperty, bIsArmorDependent, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
