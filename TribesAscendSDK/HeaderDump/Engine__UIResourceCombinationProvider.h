#pragma once
#include "Engine__UIDataProvider.h"
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
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
