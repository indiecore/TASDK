#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineRecentPlayersList.RecentParty." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RecentParty
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PartyLeader, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
