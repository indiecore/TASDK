#pragma once
#include "Engine__PhysicsVolume.h"
#include "UDKBase__UDKAnimBlendBase.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimBlendByPhysicsVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByPhysicsVolume : public UDKAnimBlendBase
	{
	public:
		ADD_OBJECT(PhysicsVolume, LastPhysicsVolume)
		// Here lies the not-yet-implemented method 'PhysicsVolumeChanged'
	};
}
#undef ADD_OBJECT
