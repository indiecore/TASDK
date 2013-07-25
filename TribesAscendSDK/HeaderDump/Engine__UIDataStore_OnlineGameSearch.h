#pragma once
#include "Engine__UIDataStore_Remote.h"
#include "Engine__OnlineSubsystem.h"
#include "Engine__OnlineGameSearch.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlineGameSearch." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlineGameSearch : public UIDataStore_Remote
	{
	public:
		ADD_VAR(::IntProperty, ActiveSearchIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SelectedIndex, 0xFFFFFFFF)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_VAR(::NameProperty, SearchResultsName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'InvalidateCurrentSearchResults'
		// Here lies the not-yet-implemented method 'SubmitGameSearch'
		// Here lies the not-yet-implemented method 'OverrideQuerySubmission'
		// Here lies the not-yet-implemented method 'OnSearchComplete'
		// Here lies the not-yet-implemented method 'GetSearchResultFromIndex'
		// Here lies the not-yet-implemented method 'ShowHostGamercard'
		// Here lies the not-yet-implemented method 'BuildSearchResults'
		// Here lies the not-yet-implemented method 'GetCurrentGameSearch'
		// Here lies the not-yet-implemented method 'GetActiveGameSearch'
		// Here lies the not-yet-implemented method 'FindSearchConfigurationIndex'
		// Here lies the not-yet-implemented method 'SetCurrentByIndex'
		// Here lies the not-yet-implemented method 'SetCurrentByName'
		// Here lies the not-yet-implemented method 'MoveToNext'
		// Here lies the not-yet-implemented method 'MoveToPrevious'
		// Here lies the not-yet-implemented method 'ClearAllSearchResults'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
