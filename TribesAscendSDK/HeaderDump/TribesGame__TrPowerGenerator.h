#pragma once
#include "TribesGame__TrGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPowerGenerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPowerGenerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPowerGenerator : public TrGameObjective
	{
	public:
		ADD_VAR(::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeScalePlayRate, m_AnimNodeScale)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthEffectsInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nDowntimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bFullyRestoringHealthEffects, 0x2)
		ADD_VAR(::BoolProperty, m_bAutoRestoreHealthEnabled, 0x1)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxMorphDamage, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
