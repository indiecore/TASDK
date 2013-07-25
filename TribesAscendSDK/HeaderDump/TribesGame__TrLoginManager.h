#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrLoginManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrLoginManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bRemember, 0x1)
		ADD_VAR(::StrProperty, LoginName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LoginPassword, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForLoginWaitPopup, 0x2)
	};
}
#undef ADD_VAR
