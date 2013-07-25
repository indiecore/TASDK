#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrArenaStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrArenaStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrArenaStats : public Object
	{
	public:
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::IntProperty, TeamScore, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForcingUpdate, 0x2)
		ADD_VAR(::ByteProperty, FriendlyManGraphics, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EnemyManGraphics, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
