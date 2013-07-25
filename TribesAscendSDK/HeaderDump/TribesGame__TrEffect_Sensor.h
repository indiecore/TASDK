#pragma once
#include "TribesGame__TrEffect_Managed.h"
#include "Engine__Actor.h"
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
		// Here lies the not-yet-implemented method 'Apply'
		// Here lies the not-yet-implemented method 'Remove'
	};
}
#undef ADD_VAR
