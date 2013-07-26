#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.PartyBeacon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.PartyBeacon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PartyBeacon : public Object
	{
	public:
		ADD_VAR(::NameProperty, BeaconName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ElapsedHeartbeatTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeartbeatTimeout, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldTick, 0x4)
		ADD_VAR(::BoolProperty, bWantsDeferredDestroy, 0x2)
		ADD_VAR(::BoolProperty, bIsInTick, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Socket, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PartyBeaconPort, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_FTickableObject, 0xFFFFFFFF)
		void OnDestroyComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeacon.OnDestroyComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeacon.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
