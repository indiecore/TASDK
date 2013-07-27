#pragma once
#include "UDKBase.UDKVehicleBase.h"
#include "UDKBase.UDKWeapon.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKWeaponPawn : public UDKVehicleBase
	{
	public:
		ADD_STRUCT(int, MySeatIndex, 1556)
		ADD_OBJECT(UDKWeapon, MyVehicleWeapon, 1552)
		ADD_OBJECT(UDKVehicle, MyVehicle, 1548)
		Object::Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeaponPawn.GetTargetLocation");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = RequestedBy;
			*(bool*)&params[4] = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
