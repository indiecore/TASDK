#pragma once
#include "Engine__UIPropertyDataProvider.h"
#include "Core__Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDynamicDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDynamicDataProvider." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDynamicDataProvider : public UIPropertyDataProvider
	{
	public:
		ADD_OBJECT(Object, DataSource)
		ADD_OBJECT(ScriptClass, DataClass)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// Here lies the not-yet-implemented method 'BindProviderInstance'
		// Here lies the not-yet-implemented method 'UnbindProviderInstance'
		// Here lies the not-yet-implemented method 'ProviderInstanceBound'
		// Here lies the not-yet-implemented method 'ProviderInstanceUnbound'
		// Here lies the not-yet-implemented method 'IsValidDataSourceClass'
		// Here lies the not-yet-implemented method 'GetDataSource'
		// Here lies the not-yet-implemented method 'CleanupDataProvider'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
