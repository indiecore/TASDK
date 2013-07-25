#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_VideoWindow." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_VideoWindow : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, CurrWindow, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'FillOption'
	};
}
#undef ADD_VAR
