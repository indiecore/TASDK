#pragma once
#include "Engine__UIDataStore.h"
#include "Engine__UIDynamicFieldProvider.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_Registry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_Registry : public UIDataStore
	{
	public:
		ADD_OBJECT(UIDynamicFieldProvider, RegistryDataProvider)
		// Here lies the not-yet-implemented method 'GetDataProvider'
	};
}
#undef ADD_OBJECT
