#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCollisionProxy." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCollisionProxy : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, m_bTrackLocallyControlledPawnsOnly, 0x20)
		ADD_VAR(::BoolProperty, m_bForwardOwnerOnly, 0x10)
		ADD_VAR(::BoolProperty, m_bIgnoreInvulnerablePlayers, 0x8)
		ADD_VAR(::BoolProperty, m_bIgnoreHackedPawns, 0x4)
		ADD_VAR(::BoolProperty, m_bIgnoreNonPlayers, 0x2)
		ADD_VAR(::BoolProperty, m_bIgnoreStealthPlayers, 0x1)
	};
}
#undef ADD_VAR
