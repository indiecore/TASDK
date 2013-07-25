#pragma once
#include "TribesGame__TrSubDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSubDevice_ForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSubDevice_ForceField : public TrSubDevice
	{
	public:
		ADD_VAR(::FloatProperty, m_MinSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MaxDamage, 0xFFFFFFFF)
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSubDevice_ForceField.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSubDevice_ForceField.ModifyInstantHitDamage");
			byte* params = (byte*)malloc(89);
			*params = FiringMode;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			*(float*)(params + 84) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 88);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
