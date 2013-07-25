#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxMinimapHud.h"
#include "Engine__WorldInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrDevices." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrDevices." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrDevices : public GFxObject
	{
	public:
		ADD_VAR(::BoolProperty, bNeedsUpdateData, 0x1)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GFxMinimapHud, HUD)
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'GetAmmonClip'
		// Here lies the not-yet-implemented method 'GetAmmonPool'
		// Here lies the not-yet-implemented method 'UpdateData'
		// Here lies the not-yet-implemented method 'Update'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
