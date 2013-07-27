#pragma once
#include "Engine.NavigationPoint.h"
#include "Core.Object.h"
#include "UDKBase.UDKVehicle.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class UDKVehicleFactory : public NavigationPoint
	{
	public:
		ADD_STRUCT(int, TeamNum, 732)
		ADD_STRUCT(Object::Vector, HUDLocation, 720)
		ADD_STRUCT(float, RespawnProgress, 716)
		ADD_OBJECT(UDKVehicle, ChildVehicle, 712)
		ADD_OBJECT(ScriptClass, VehicleClass, 708)
		ADD_BOOL(bReplicateChildVehicle, 704, 0x2)
		ADD_BOOL(bHasLockedVehicle, 704, 0x1)
		ADD_STRUCT(ScriptString*, VehicleClassPath, 692)
		void SpawnVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleFactory.SpawnVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHUDLocation(Object::Vector NewHUDLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleFactory.SetHUDLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleFactory.GetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
