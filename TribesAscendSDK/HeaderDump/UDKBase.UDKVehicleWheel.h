#pragma once
#include "Engine.SVehicleWheel.h"
#include "Engine.ParticleSystem.h"
#include "UDKBase.UDKVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleWheel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKVehicleWheel : public SVehicleWheel
	{
	public:
		ADD_VAR(::FloatProperty, EffectDesiredSpinDir, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisableWheelOnDeath, 0x2)
		ADD_VAR(::BoolProperty, bUseMaterialSpecificEffects, 0x1)
		void SetParticleEffect(class UDKVehicle* OwnerVehicle, class ParticleSystem* NewTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleWheel.SetParticleEffect");
			byte* params = (byte*)malloc(8);
			*(class UDKVehicle**)params = OwnerVehicle;
			*(class ParticleSystem**)(params + 4) = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OldEffectFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSystem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleWheel.OldEffectFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSystem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
