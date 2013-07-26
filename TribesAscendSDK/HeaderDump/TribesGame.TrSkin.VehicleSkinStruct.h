#pragma once
#include "Engine.AnimSet.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrSkin.VehicleSkinStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VehicleSkinStruct
	{
	public:
		ADD_OBJECT(AnimSet, SeatAnimSet)
		ADD_OBJECT(ScriptClass, VehicleClass)
	};
}
#undef ADD_OBJECT
