#pragma once
#include "UDKBase__UDKGameSettingsCommon.h"
#include "UTGame__UTUIDataStore_MenuItems.h"
#include "Engine__GameInfo.h"
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
		// Here lies the not-yet-implemented method 'SetCustomMapName'
		// Here lies the not-yet-implemented method 'SetOfficialMutatorBitmask'
		// Here lies the not-yet-implemented method 'BuildURL'
		// Here lies the not-yet-implemented method 'UpdateFromURL'
		// Here lies the not-yet-implemented method 'SetMutators'
		// Here lies the not-yet-implemented method 'GenerateMutatorBitmaskFromURL'
		// Here lies the not-yet-implemented method 'SetCustomMutators'
	};
}
#undef ADD_VAR
