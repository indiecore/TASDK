#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__GfxTrHud.h"
#include "Engine__LocalPlayer.h"
#include "GFxUI__GFxObject.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GfxTrHudTeam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GfxTrHudTeam : public GfxTrHud
	{
	public:
		ADD_OBJECT(GFxObject, FlagCarrierTF)
		ADD_OBJECT(GFxObject, ScoreTF)
		ADD_OBJECT(GFxObject, ScoreBarMC)
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'InitMessageRow'
		// Here lies the not-yet-implemented method 'ClearStats'
		// Here lies the not-yet-implemented method 'UpdateGameHUD'
		// Here lies the not-yet-implemented method 'GetRank'
	};
}
#undef ADD_OBJECT
