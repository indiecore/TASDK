#pragma once
#include "TribesGame.TrEffect_Managed.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffect_Sensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrEffect_Sensor : public TrEffect_Managed
	{
	public:
		ADD_VAR(::BoolProperty, m_bSeeLowHealthEnemy, 0x20)
		ADD_VAR(::BoolProperty, m_bSeeStealthedEnemy, 0x10)
		ADD_VAR(::BoolProperty, m_bSeeNormalEnemy, 0x8)
		ADD_VAR(::BoolProperty, m_bDisplayForeground, 0x4)
		ADD_VAR(::BoolProperty, m_bDisplayInGame, 0x2)
		ADD_VAR(::BoolProperty, m_bRequiresLOS, 0x1)
		ADD_VAR(::FloatProperty, m_fScannerRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fScannerFOV, 0xFFFFFFFF)
		void Apply(class Actor* Target, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Sensor.Apply");
			byte* params = (byte*)malloc(84);
			*(class Actor**)params = Target;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Sensor.Remove");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
