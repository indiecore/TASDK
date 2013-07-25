#pragma once
#include "GFxUI__GFxMoviePlayer.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__GameReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrUI_TeamSelectionMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrUI_TeamSelectionMenu." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrUI_TeamSelectionMenu : public GFxMoviePlayer
	{
	public:
		ADD_OBJECT(GFxObject, MovieClip)
		ADD_VAR(::BoolProperty, bCompleted, 0x4)
		ADD_OBJECT(GFxObject, DiamondSwordCountTF)
		ADD_OBJECT(GFxObject, BloodEagleCountTF)
		ADD_OBJECT(GFxObject, DiamondSwordButton)
		ADD_OBJECT(GFxObject, BloodEagleButton)
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_VAR(::BoolProperty, JoinDiamondSwordAllowed, 0x10)
		ADD_VAR(::BoolProperty, JoinBloodEagleAllowed, 0x8)
		ADD_VAR(::BoolProperty, bJustJoined, 0x2)
		ADD_VAR(::BoolProperty, bInitialized, 0x1)
		ADD_VAR(::IntProperty, PrevDiamondSwordCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevBloodEagleCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AllowedTeamDiscrepancyOnTeam, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AllowedTeamDiscrepancyNoTeam, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'Start'
		// Here lies the not-yet-implemented method 'SetFontIndex'
		// Here lies the not-yet-implemented method 'Show'
		// Here lies the not-yet-implemented method 'SetLabels'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'EnableBloodEagle'
		// Here lies the not-yet-implemented method 'AsTeamChooseEnableButton'
		// Here lies the not-yet-implemented method 'EnableDiamondSword'
		// Here lies the not-yet-implemented method 'EnableSpectate'
		// Here lies the not-yet-implemented method 'choseTeamBE'
		// Here lies the not-yet-implemented method 'choseTeamDS'
		// Here lies the not-yet-implemented method 'choseTeamSpectate'
		// Here lies the not-yet-implemented method 'CompleteMovie'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
