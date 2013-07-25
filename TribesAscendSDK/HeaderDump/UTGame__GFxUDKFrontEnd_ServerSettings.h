#pragma once
#include "UTGame__GFxUDKFrontEnd_SettingsBase.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_ServerSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_ServerSettings : public GFxUDKFrontEnd_SettingsBase
	{
	public:
		ADD_VAR(::BoolProperty, bDataChangedByReqs, 0x1)
		// Here lies the not-yet-implemented method 'SetSelectedOptionSet'
		// Here lies the not-yet-implemented method 'OnOptionChanged'
		// Here lies the not-yet-implemented method 'SaveState'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'PopulateOptionDataProviderForIndex'
		// Here lies the not-yet-implemented method 'FindControlByUTClassName'
	};
}
#undef ADD_VAR
