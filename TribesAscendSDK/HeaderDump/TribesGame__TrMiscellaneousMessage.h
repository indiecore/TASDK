#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrMiscellaneousMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrMiscellaneousMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMiscellaneousMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, EnemyTeamBoughtHerc, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OurTeamBoughtHerc, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, DiamondSwordCloseToLoss)
		ADD_OBJECT(SoundCue, DiamondSwordCloseToWin)
		ADD_OBJECT(SoundCue, BloodEagleCloseToLoss)
		ADD_OBJECT(SoundCue, BloodEagleCloseToWin)
		ADD_OBJECT(SoundCue, FriendDiamondSwordBoughtHerc)
		ADD_OBJECT(SoundCue, FriendBloodEagleBoughtHerc)
		ADD_OBJECT(SoundCue, EnemyDiamondSwordBoughtHerc)
		ADD_OBJECT(SoundCue, EnemyBloodEagleBoughtHerc)
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
