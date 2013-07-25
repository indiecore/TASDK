#pragma once
#include "UDKBase__UDKAnimBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByPhysics." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByPhysics : public UDKAnimBlendBase
	{
	public:
		ADD_VAR(::FloatProperty, PendingTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PendingChildIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LandBlendDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastPhysics, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PhysicsMap, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
