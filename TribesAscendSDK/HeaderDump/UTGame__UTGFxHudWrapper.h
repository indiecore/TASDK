#pragma once
#include "UTGame__UTHUDBase.h"
#include "UTGame__GFxProjectedUI.h"
#include "UTGame__GFxMinimapHud.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGFxHudWrapper." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGFxHudWrapper : public UTHUDBase
	{
	public:
		ADD_OBJECT(ScriptClass, MinimapHUDClass)
		ADD_OBJECT(GFxProjectedUI, InventoryMovie)
		ADD_OBJECT(GFxMinimapHud, HudMovie)
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'RemoveMovies'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'CreateHUDMovie'
		// Here lies the not-yet-implemented method 'GetLocalPlayerOwnerIndex'
		// Here lies the not-yet-implemented method 'SetVisible'
		// Here lies the not-yet-implemented method 'DisplayHit'
		// Here lies the not-yet-implemented method 'CloseOtherMenus'
		// Here lies the not-yet-implemented method 'ResolutionChanged'
		// Here lies the not-yet-implemented method 'PostRender'
		// Here lies the not-yet-implemented method 'DrawHUD'
		// Here lies the not-yet-implemented method 'LocalizedMessage'
		// Here lies the not-yet-implemented method 'AddConsoleMessage'
		// Here lies the not-yet-implemented method 'CompleteCloseInventory'
		// Here lies the not-yet-implemented method 'CompleteCloseTimer'
	};
}
#undef ADD_OBJECT
