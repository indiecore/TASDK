#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAccolade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrAccolade : public Object
	{
	public:
		ADD_VAR(::IntProperty, DatabaseId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActivityId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HUDMessage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Weight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, Broadcast, 0x1)
		ADD_VAR(::IntProperty, MessageSwitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CreditsAwarded, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
