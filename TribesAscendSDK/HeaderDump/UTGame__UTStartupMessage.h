#pragma once
#include "UTGame__UTLocalMessage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTStartupMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTStartupMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, SinglePlayer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NotReady, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Stage, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
