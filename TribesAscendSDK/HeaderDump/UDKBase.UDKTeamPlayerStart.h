#pragma once
#include "Engine.PlayerStart.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKTeamPlayerStart." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKTeamPlayerStart : public PlayerStart
	{
	public:
		ADD_VAR(::ByteProperty, TeamNumber, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
