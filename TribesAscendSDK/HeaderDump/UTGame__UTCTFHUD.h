#pragma once
#include "UTGame__UTCTFBase.h"
#include "UTGame__UTTeamHUD.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFHUD : public UTTeamHUD
	{
	public:
		ADD_VAR(::ByteProperty, FlagStates, 0xFFFFFFFF)
		ADD_OBJECT(UTCTFBase, FlagBases)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'DisplayTeamLogos'
		// Here lies the not-yet-implemented method 'GetDirectionalDest'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
