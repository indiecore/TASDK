#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ChangeMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ChangeMap : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bAllowRemove, 0x1)
		ADD_VAR(::IntProperty, CurrentSlotId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentMapId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemoveMapNumber, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
	};
}
#undef ADD_VAR
