#pragma once
#include "UTGame__GFxUDKFrontEnd_Dialog.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_FilterDialog." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_FilterDialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_FilterDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		ADD_OBJECT(GFxObject, GameTypeOptionItem)
		ADD_OBJECT(GFxObject, DataProvider)
		ADD_VAR(::BoolProperty, bFiltersHaveChanged, 0x1)
		ADD_OBJECT(GFxClikWidget, FilterListMC)
		ADD_OBJECT(UTDataStore_GameSearchDM, SearchDataStore)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
