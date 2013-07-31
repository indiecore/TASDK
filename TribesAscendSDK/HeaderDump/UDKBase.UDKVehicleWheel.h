#pragma once
#include "Engine.SVehicleWheel.h"
#include "Engine.ParticleSystem.h"
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
namespace UnrealScript
{
	class UDKVehicleWheel : public SVehicleWheel
	{
	public:
		ADD_STRUCT(float, EffectDesiredSpinDir, 284)
		ADD_BOOL(bDisableWheelOnDeath, 276, 0x2)
		ADD_BOOL(bUseMaterialSpecificEffects, 276, 0x1)
		void SetParticleEffect(class UDKVehicle* OwnerVehicle, class ParticleSystem* NewTemplate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36261);
			byte params[8] = { NULL };
			*(class UDKVehicle**)params = OwnerVehicle;
			*(class ParticleSystem**)&params[4] = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OldEffectFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSystem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36264);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSystem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
