#pragma once
#include "Engine__LocalPlayer.h"
#include "GFxUI__GFxObject.h"
#include "UDKBase__UDKPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUIView." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxUIView : public GFxObject
	{
	public:
		ADD_VAR(::BoolProperty, bRequiresNetwork, 0x1)
		// Here lies the not-yet-implemented method 'HasLinkConnection'
		// Here lies the not-yet-implemented method 'GetPlayerOwner'
		// Here lies the not-yet-implemented method 'GetUDKPlayerOwner'
		// Here lies the not-yet-implemented method 'GetPlayerName'
		// Here lies the not-yet-implemented method 'IsLoggedIn'
		// Here lies the not-yet-implemented method 'GetCommonOptionsURL'
		// Here lies the not-yet-implemented method 'GetPlayerIndex'
		// Here lies the not-yet-implemented method 'GetPlayerControllerId'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
	};
}
#undef ADD_VAR
