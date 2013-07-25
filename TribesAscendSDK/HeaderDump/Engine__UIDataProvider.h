#pragma once
#include "Engine__UIRoot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider : public UIRoot
	{
	public:
		ADD_VAR(::ByteProperty, WriteAccessType, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'OnDataProviderPropertyChange'
		// Here lies the not-yet-implemented method 'GetProviderFieldType'
		// Here lies the not-yet-implemented method 'ParseArrayDelimiter'
		// Here lies the not-yet-implemented method 'GetSupportedScriptFields'
		// Here lies the not-yet-implemented method 'AllowPublishingToField'
		// Here lies the not-yet-implemented method 'GetFieldValue'
		// Here lies the not-yet-implemented method 'SetFieldValue'
		// Here lies the not-yet-implemented method 'GenerateScriptMarkupString'
		// Here lies the not-yet-implemented method 'GenerateFillerData'
		// Here lies the not-yet-implemented method 'IsProviderDisabled'
		// Here lies the not-yet-implemented method 'IsCollectionDataType'
		// Here lies the not-yet-implemented method 'NotifyPropertyChanged'
		// Here lies the not-yet-implemented method 'AddPropertyNotificationChangeRequest'
		// Here lies the not-yet-implemented method 'RemovePropertyNotificationChangeRequest'
		// Here lies the not-yet-implemented method 'ParseTagArrayDelimiter'
	};
}
#undef ADD_VAR
