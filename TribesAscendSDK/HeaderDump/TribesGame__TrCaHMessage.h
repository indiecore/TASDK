#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCaHMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCaHMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, Points, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WeHave, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TheEnemyHas, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MorePointsToWin, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WeNeed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TheEnemyNeeds, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ControlPointCaptured, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CaptureAndHoldTheControlPoints, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
	};
}
#undef ADD_VAR
