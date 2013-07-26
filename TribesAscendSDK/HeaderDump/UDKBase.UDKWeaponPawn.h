#pragma once
#include "Core.Object.Vector.h"
#include "UDKBase.UDKVehicleBase.h"
#include "UDKBase.UDKWeapon.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKWeaponPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKWeaponPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKWeaponPawn : public UDKVehicleBase
	{
	public:
		ADD_VAR(::IntProperty, MySeatIndex, 0xFFFFFFFF)
		ADD_OBJECT(UDKWeapon, MyVehicleWeapon)
		ADD_OBJECT(UDKVehicle, MyVehicle)
		Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeaponPawn.GetTargetLocation");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = RequestedBy;
			*(bool*)(params + 4) = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
