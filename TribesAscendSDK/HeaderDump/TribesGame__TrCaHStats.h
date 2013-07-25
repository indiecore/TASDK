#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCaHStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCaHStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCaHStats : public Object
	{
	public:
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::IntProperty, RoundNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumCapturePointsHeld, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamScore, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceUpdateNextTick, 0x4)
		ADD_VAR(::BoolProperty, bForcingUpdate, 0x2)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
