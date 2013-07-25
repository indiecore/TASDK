#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAccoladeManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAccoladeManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAccoladeManager : public Object
	{
	public:
		ADD_VAR(::IntProperty, m_nLastFlagReturnTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastFlagGrabTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_EMERGENCY_GRAB_DISTANCE, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_FLAG_DEFENSE_DISTANCE, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_ULTRA_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_FAST_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_LLAMA_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_TIME_FLAG_CREDITS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrSpinfusorKillStreak, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrExplosiveKillStreak, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrSnipingKillStreak, 0xFFFFFFFF)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_OBJECT(TrPlayerController, m_TrPC)
		ADD_OBJECT(TrGame, m_TrG)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
