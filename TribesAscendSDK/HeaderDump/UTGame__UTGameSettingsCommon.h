#pragma once
#include "UDKBase__UDKGameSettingsCommon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGameSettingsCommon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTGameSettingsCommon : public UDKGameSettingsCommon
	{
	public:
		ADD_VAR(::IntProperty, MaxPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinNetPlayers, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
