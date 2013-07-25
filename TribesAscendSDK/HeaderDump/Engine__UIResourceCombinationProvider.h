#pragma once
#include "Engine__UIDataProvider.h"
#include "Engine__UIDataProvider_OnlineProfileSettings.h"
#include "Engine__UIResourceDataProvider.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIResourceCombinationProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIResourceCombinationProvider." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIResourceCombinationProvider : public UIDataProvider
	{
	public:
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider)
		ADD_OBJECT(UIResourceDataProvider, StaticDataProvider)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		// Here lies the not-yet-implemented method 'InitializeProvider'
		// Here lies the not-yet-implemented method 'GetElementProviderTags'
		// Here lies the not-yet-implemented method 'GetElementCount'
		// Here lies the not-yet-implemented method 'GetListElements'
		// Here lies the not-yet-implemented method 'IsElementEnabled'
		// Here lies the not-yet-implemented method 'GetElementCellSchemaProvider'
		// Here lies the not-yet-implemented method 'GetElementCellValueProvider'
		// Here lies the not-yet-implemented method 'GetElementCellTags'
		// Here lies the not-yet-implemented method 'GetCellFieldType'
		// Here lies the not-yet-implemented method 'GetCellFieldValue'
		// Here lies the not-yet-implemented method 'ClearProviderReferences'
		// Here lies the not-yet-implemented method 'ReplaceProviderValue'
		// Here lies the not-yet-implemented method 'ReplaceProviderCollection'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
