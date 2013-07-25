#pragma once
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
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
		// Here lies the not-yet-implemented method 'TouchOther'
		// Here lies the not-yet-implemented method 'ForceProximityScan'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'UnTouch'
		// Here lies the not-yet-implemented method 'ShouldIgnoreActor'
		// Here lies the not-yet-implemented method 'ForceClearNearByPawnsList'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'CheckNearByPawns'
		// Here lies the not-yet-implemented method 'OnPawnAdded'
		// Here lies the not-yet-implemented method 'OnPawnRemoved'
		// Here lies the not-yet-implemented method 'GetNearByPawns'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
	};
}
#undef ADD_VAR
