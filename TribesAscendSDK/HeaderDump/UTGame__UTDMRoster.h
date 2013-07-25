#pragma once
#include "UTGame__UTTeamInfo.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDMRoster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDMRoster." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDMRoster : public UTTeamInfo
	{
	public:
		ADD_OBJECT(ScriptClass, DMSquadClass)
		ADD_VAR(::IntProperty, Position, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AddToTeam'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
