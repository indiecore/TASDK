#pragma once
#include "UTGame__UTHUDBase.h"
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
		ADD_OBJECT(GFxProjectedUI, InventoryMovie)
		ADD_OBJECT(GFxMinimapHud, HudMovie)
	};
}
#undef ADD_OBJECT
