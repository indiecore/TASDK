#pragma once
#include "Core__Object.h"
#include "Engine__WorldInfo.h"
#include "Engine__PlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PlatformCommon.TgSupportCommands." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TgSupportCommands : public Object
	{
	public:
		ADD_OBJECT(WorldInfo, WorldInfo)
		ADD_OBJECT(PlayerController, PC)
		// Here lies the not-yet-implemented method 'gmMatchForce'
		// Here lies the not-yet-implemented method 'gmMatchNext'
		// Here lies the not-yet-implemented method 'gmCommand'
		// Here lies the not-yet-implemented method 'gmC'
		// Here lies the not-yet-implemented method 'GPerfDebugFeet'
		// Here lies the not-yet-implemented method 'GPerfDebugSkips'
		// Here lies the not-yet-implemented method 'GPerfDebugRelevMode'
		// Here lies the not-yet-implemented method 'scLog'
		// Here lies the not-yet-implemented method 'scLogMark'
		// Here lies the not-yet-implemented method 'scStartGame'
		// Here lies the not-yet-implemented method 'scEndGame'
		// Here lies the not-yet-implemented method 'scScore'
		// Here lies the not-yet-implemented method 'scTime'
		// Here lies the not-yet-implemented method 'scTimer'
		// Here lies the not-yet-implemented method 'scDemoRec'
		// Here lies the not-yet-implemented method 'scDemoStop'
		// Here lies the not-yet-implemented method 'scPerfDebugFeet'
		// Here lies the not-yet-implemented method 'scPerfDebugSkip'
		// Here lies the not-yet-implemented method 'scPerfDebugRelevMode'
	};
}
#undef ADD_OBJECT
