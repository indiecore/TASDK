#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineRecentPlayersList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineRecentPlayersList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineRecentPlayersList : public Object
	{
	public:
		ADD_VAR(::IntProperty, RecentPartiesAddIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RecentPlayersAddIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRecentParties, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRecentPlayers, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineRecentPlayersList.RecentParty' for the property named 'LastParty'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
